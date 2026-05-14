#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];
    int scr;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    char s[20];
    char name[20];
    int scr;

    while(1){
        scanf("%s", s);
        if(strcmp(s, "add")==0){
            scanf("%s %d", name, &scr);
            struct Node *newNode = malloc(sizeof(struct Node));
            strcpy(newNode->name, name);
            newNode->scr=scr;
            newNode->next = NULL;

            if(head==NULL){
                head=newNode;
            }else{
                struct Node *temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        else if(strcmp(s,"delete")==0){
            scanf("%s", name);
            if(head!=NULL&& strcmp(head->name,name)==0){
                struct Node *temp = head;
                head=head->next;
                free(temp);
            }else if(head!=NULL){
                struct Node *prev = head;
                struct Node* curr = head->next;

                while(curr!=NULL){
                    if(strcmp(curr->name,name)==0){
                        prev->next=curr->next;
                        free(curr);
                        break;
                    }
                    prev=curr;
                    curr=curr->next;
                }
            }
        }

        else if(strcmp(s,"print")==0){
            struct Node *temp = head;
            while(temp!=NULL){
                printf("%s %d\n",temp->name, temp->scr);
                temp=temp->next;
            }
        }

        else if(strcmp(s,"quit")==0){
            struct Node *temp=head;
            while(temp!=NULL){
                struct Node *newNode = temp->next;
                free(temp);
                temp=newNode;
            }
            break;
        }
    }
    return 0;
}