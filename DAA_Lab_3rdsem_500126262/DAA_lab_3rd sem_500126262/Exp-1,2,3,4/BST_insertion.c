#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; }; 
struct Node* createNode(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); } 
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
void inorder(struct Node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); } 
} 
struct Node* insert(struct Node* root, int value) { 
    if (root == NULL) { 
        return createNode(value); } 
    if (value < root->data) { 
        root->left = insert(root->left, value); 
    } else if (value > root->data) { 
        root->right = insert(root->right, value); } 
    return root; 
} 
int main(){
     struct Node* root = NULL; 
    int choice, value,n; 
    printf("Enter the number of values you want to insert: "); 
    scanf("%d",&n); 
    for(int i=0; i<n;i++){ 
    printf("Enter value%d: ",i+1); 
    scanf("%d", &value); 
    root = insert(root, value); 
    } 
    inorder(root); 
    printf("\n"); 
}