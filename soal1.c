/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5
 *   Hari dan Tanggal    : Selasa, 12 Mei 2025
 *   Nama (NIM)          : Nicholas L.M.Simarmata (13224060)
 *   Nama File           : soal1.c
 *   Deskripsi           : Meng-input angka ke dalam tree lalu mendisplay sesuai urutan preorder, inorder, dan posorder
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;


node* initial(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// node* add(node* root, int i, int data){
//     int tempDat = data;
//     if(data < 0){
//         tempDat *= -1;
//     }

//     if (root == NULL){
//         return initial(data);
//     } else if (root->data < tempDat){

//     }
// }

node* add(node* root, node* process,int i, int data){
    node* temp = process;
    node* newroot = root;

    
    if(temp == NULL){
        temp = initial(data);
        if(i%2 != 0){
            newroot->left = temp;
        } else newroot->right = temp;
        // printf("root:%d, prosesing:%d\n", root->data, temp->data);
        // printf("add %d;%d anak dari %d\n", i, data, newroot->data);
        return newroot;
    } else if (temp->left != NULL && temp->right != NULL){
        // printf("%d\n", temp->data);
        if(temp->left->left != NULL && temp->left->right != NULL){
            add(temp, temp->right, i, data);
        } else add(temp, temp->left, i, data);
        
    } else if (temp->left == NULL && root->right != NULL){
        // printf("root:%d; sini:%d\n", root->data, temp->data);
        return add(temp, temp->left, i, data);
    } else if (temp->right == NULL){
        return add(temp, temp->right, i, data);
    } 
    
    // if(i % 2 != 0){ // ganjil = left
    //     temp->left = initial(data);
    // } else {
    //     temp->right = initial(data);
    // }
    // return root;
}

void inorder(node* root){ // https://www.geeksforgeeks.org/dsa/binary-tree-traversal/
    if(root == NULL) return;

    inorder(root->left);
    printf("%d", root->data);
    if(root->left != NULL || root->right != NULL) printf(" ");
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL) return;
    printf("%d", root->data);
    if(root->left != NULL || root->right != NULL) printf(" ");
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
    if(root->left != NULL || root->right != NULL) printf(" ");
}

// void preorder(int Arr[]){
//     while(1){

//     }

//     return;
// }

int main(){
    node* root;
    node* temp;
    int N;
    scanf("%d", &N);
    int Arr[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &Arr[i]);
        // printf("%d\n", Arr[i]);
        if(i == 0){
            root = initial(Arr[i]);
            temp = root;
        } else {
            temp = add(root, temp, i, Arr[i]);
            temp = root;
        }
    }

    printf("PRE ");preorder(root);printf("\n");
    printf("IN ");inorder(root);printf("\n");
    printf("POST ");postorder(root);printf("\n");

    return 0;
}
