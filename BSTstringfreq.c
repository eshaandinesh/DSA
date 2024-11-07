#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int len;
    char *str;
    int freq;
    struct node* left;
    struct node* right;
};

struct node* create(char arr[]){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->len = strlen(arr);
    temp->str = (char*)malloc(sizeof(char)*temp->len);
    strcpy(temp->str,arr);
    temp->freq = 1;
    temp->left = NULL;
    temp->right = NULL;
}

void insert(struct node* root, char arr[]){
    struct node* par = NULL;
    struct node* ptr = root;
    while(ptr != NULL){
        if(strcmp(ptr->str,arr) == 0){
            ptr->freq++;
            return;
        }
        else if(strcmp(ptr->str,arr) > 0){
            par = ptr;
            ptr = ptr->left;
            if(ptr == NULL){
                par->left = create(arr);
                return;
            }
        }
        else{
            par = ptr;
            ptr = ptr->right;
            if(ptr == NULL){
                par->right = create(arr);
                return;
            }
        }
    }
}

void disp(struct node* root){
    if(root != NULL){
        disp(root->left);
        printf("%s (%d times)\n",root->str,root->freq);
        disp(root->right);
    }
}

void freq(struct node* root,int n){
    int max = 0;
    char *s = NULL;
    struct node* queue[n];
    int front = 0;
    int rear = 0;
    if(root == NULL){
        printf("(null) (0 times)");
        return;
    }
    queue[rear++] = root;
    max = root->freq;
    s = root->str;
    while(front < rear){
        struct node* temp = queue[front++];
        if(temp->freq > max){
            max = temp->freq;
            s = temp->str;
        }
        if(temp->left != NULL){
            queue[rear++] = temp->left;
        }
        if(temp->right != NULL){
            queue[rear++] = temp->right;
        }
    }
    printf("%s (%d times)",s,max);
}

int main(){
    char str[100];
    struct node* root = NULL;
    int count = 0;
    while(true){
        scanf("%s",str);
        if(strcmp(str,"end") == 0){
            break;
        }
        else{
            count++;
            if(root == NULL){
                root = create(str);
            }
            else{
                insert(root,str);
            }
        }
    }
    printf("Words in alphabetical order:\n");
    disp(root);
    printf("The most frequent word: ");
    freq(root,count);
}
