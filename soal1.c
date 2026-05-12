#include <stdio.h>

int main(void) {
    return 0;#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    node* left;
    node* right;
} node;

node* initial(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* add(node* root, int i, int data){
    node* temp = root;

    if(root->left == NULL){

    } else if (root->right == NULL){
        
    }
    
    if(i % 2 != 0){ // ganjil = left
        // while(temp->left != NULL){
        //     temp = temp->left;
        // }
        temp->left = initial(data);
    } else {
        // while(temp->right != NULL){
        //     temp = temp->right;
        // }
        temp->right = initial(data);
    }
    return root;
}

void preorder(int Arr[]){
    while(1){

    }

    return;
}

int main(){
    node* root;
    node* temp;
    int N; int count = 0;
    scanf("%d", &N);
    int Arr[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &Arr[N]);
        if(i == 0){
            root = initial(Arr[N]);
            temp = root;
        } else {
            temp = add(temp, i, Arr[N]);
            count++;
        }
    }

    return 0;
}
}
