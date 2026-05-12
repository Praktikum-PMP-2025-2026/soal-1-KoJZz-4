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

node* add(node* root, node* process,int i, int data){
    node* temp = process;
    node* newroot = root;

    
    if(temp == NULL){
        temp = initial(data);
        if(i%2 != 0){
            newroot->left = temp;
        } else newroot->right = temp;
        return newroot;
    } else if (temp->left != NULL && temp->right != NULL){
        if(temp->left->left != NULL && temp->left->right != NULL){
            add(temp, temp->right, i, data);
        } else add(temp, temp->left, i, data);
        
    } else if (temp->left == NULL && root->right != NULL){
        return add(temp, temp->left, i, data);
    } else if (temp->right == NULL){
        return add(temp, temp->right, i, data);
    } 
}

void display(int Arr[], int N){
    for(int i = 0; i < N; i++){
        printf("%d", Arr[i]);
        if(i != N-1) printf(" ");
    }
}

void inorder(node* root, int i, int N, int Arr[]){ // https://www.geeksforgeeks.org/dsa/binary-tree-traversal/
    if(root == NULL) return;

    inorder(root->left, i+1, N, Arr);
    // printf("%d ", root->data);
    // if(i != N-1) printf(" ");
    Arr[i] = root->data;
    inorder(root->right, i+1, N, Arr);
}

void preorder(node* root, int i, int N, int Arr[]){
    if(root == NULL) return;
    // printf("%d", root->data);
    Arr[i] = root->data;
    // if(i != N-1) printf(" ");
    preorder(root->left, i+1, N, Arr);
    preorder(root->right, i+1, N, Arr);
}

void postorder(node* root, int i, int N, int Arr[]){
    if(root == NULL) return;
    postorder(root->left, i+1, N, Arr);
    postorder(root->right, i+1, N, Arr);
    // printf("%d", root->data);
    // if(i != N) printf(" ");
    Arr[i] = root->data;
}

node* inputs(int* size, node* root, int* Arr){
    node* temp;
    int N;
    scanf("%d", &N);
    *size = N;
    // int Arr[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &Arr[i]);
        if(i == 0){
            root = initial(Arr[i]);
            temp = root;
        } else {
            temp = add(root, temp, i, Arr[i]);
            temp = root;
        }
    }
    return temp;
}

int main(){
    node* root;
    // node* temp;
    int N;
    // scanf("%d", &N);
    int Arr[N];
    // for(int i = 0; i < N; i++){
    //     scanf("%d", &Arr[i]);
    //     if(i == 0){
    //         root = initial(Arr[i]);
    //         temp = root;
    //     } else {
    //         temp = add(root, temp, i, Arr[i]);
    //         temp = root;
    //     }
    // }

    root = inputs(&N, root, Arr);
    

    printf("PRE ");preorder(root,0,N, Arr);
    display(Arr, N);
    printf("\n");
    printf("IN ");inorder(root,0,N, Arr);
    display(Arr, N);
    printf("\n");
    printf("POST ");postorder(root,0,N, Arr);printf("\n");

    return 0;
}
