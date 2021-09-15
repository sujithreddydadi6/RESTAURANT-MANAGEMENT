//RESTAURANT 
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
struct node{//declare the node.
    string foodname;
    int quantity;
    float price;
    int data;
    struct node *next;
};

struct node *headc=NULL,*newnode,*tailc=NULL,*heada=NULL,*taila=NULL,*heads;

void adminmenu(){
    printf("\n\t\t\t\t\t\t\t\t1. View Total sales\n");
    printf("\n\t\t\t\t\t\t\t\t2. Add new items in order menu\n");
    printf("\n\t\t\t\t\t\t\t\t3. Delete items from order menu\n");
    printf("\n\t\t\t\t\t\t\t\t4. Display order menu\n");
    printf("\n\t\t\t\t\t\t\t\t5. Back to main menu\n\n\n");
    printf("\n\t\t\t\t\t\t\t\tEnter your choice ......");
}
void customermenu(){
    printf("\n\t\t\t\t\t\t\t\t1. Place your order\n");
    printf("\n\t\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\n\t\t\t\t\t\t\t\t3. Delete item from your order\n");
    printf("\n\t\t\t\t\t\t\t\t4. Display final bill\n");
    printf("\n\t\t\t\t\t\t\t\t5. Back to main menu\n\n\n");
    printf("\n\t\t\t\t\t\t\t\tEnter your choice ......");
}
struct node* createadmin(int data,string fname,float price){//create admin and add it at the end of list
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->price=price;
    newnode->quantity=0;
    newnode->foodname=fname;
    newnode->next=NULL;
    struct node *temp=heada;
    if(temp==NULL){
        heada=newnode;
        taila=newnode;
        return heada;
    }
    taila->next=newnode;
    taila=newnode;
    return heada;
}
struct node *createcustomer(int data,int quantity){// add item in the customer list
     newnode=(struct node*)malloc(sizeof(struct node));
     struct node *temp=heada;
     int f=0;
     while(temp!=NULL){
         if(temp->data==data){
             f=1;
             break;
         }
         temp=temp->next;
     }
     if(f==1){
        newnode->data=data;
        newnode->price=quantity*(temp->price);
        newnode->quantity=quantity;
        newnode->foodname=temp->foodname;
        newnode->next=NULL;
        temp=headc;
        if(temp==NULL){
            headc=newnode;
            tailc=newnode;
            return headc;
        }
        tailc->next=newnode;
        tailc=newnode;
        return headc;
     }
     else printf("\n\t\t\t\t\t\t\tThere is no such item in menu");
     return headc;
}
void displaylist(struct node* head){//display total sales history
    struct node *temp=head;
    if(temp==NULL){
        printf("\n\t\t\t\t\t\t\t\t List is empty");
        return;
    }
    printf("\n");
    while(temp!=NULL){
            cout << temp->data;
            printf("\t");
            cout << temp->foodname;
            printf("\t");
            cout << temp->quantity;
            printf("\t");
            cout << temp->price;
            printf("\n");
        temp=temp->next;
    }
    printf("\n");
    return ;
}
void displaylistad(){//dispaly restaurant menu
    struct node *temp=heada;
    if(temp==NULL){
        printf("\n\t\t\t\t\t\t\t\t List is empty");
        return;
    }
    printf("\n");
    while(temp!=NULL){
            cout << temp->data;
            printf("\t");
            cout << temp->foodname;
            printf("\t");
            //cout << temp->quantity;
            //printf("\t");
            cout << temp->price;
            printf("\n");
        temp=temp->next;
    }
    printf("\n");
    return ;
}
struct node* totalsales(int data , int quantity) {//for total sales till now
    newnode=(struct node*)malloc(sizeof(struct node));
    int f=0;
    struct node *temp=heada;
    while(temp->data!=data)temp=temp->next;
    newnode->data=data;
    newnode->price=quantity*(newnode->price);
    newnode->quantity=quantity;
    newnode->foodname=temp->foodname;
    newnode->next=NULL;
    temp=heads;
    if(temp==NULL)heads=newnode;
    else{
        while(temp->next!=NULL){
            if(temp->data==data){
                f=1;
                break;
            }
            temp=temp->next;
        }
        if(f==1){
            temp->quantity+=newnode->quantity;
            temp->price+=newnode->price;
        }
        else temp->next=newnode;
    }
    return heads;
}
void calculatesales(){
    struct node *temp=headc;
    while(temp!=NULL){
        heads=totalsales(temp->data,temp->quantity);
        temp=temp->next;
    }
}
int deleteadminorcust(struct node *head){//for deleteion of item
    printf("\n\t\t\t\t\t\tEnter serial no. of fooditem to be deleted:");
    int num;
    scanf("%d",&num);
    struct node *temp=head,*ntemp=head;
    if(temp==NULL)return 0;
    if(temp->data==num){
        head=head->next;
        free(temp);
    }
    while(temp!=NULL && temp->data!=num){
        ntemp=temp;
        temp=temp->next;
    }
    if(temp==NULL)return 0;
    ntemp->next=temp->next;
    free(temp);
    return 1;
}
void dispalybill(){//to display bill
    displaylist(headc);
    struct node *temp=headc;
    float tprice=0;
    while(temp!=NULL){
        tprice+=(temp->quantity)*(temp->price);
        temp=temp->next;
    }
    printf("\n\t\t\t\t\t\ttotal price: %.2f\n",tprice);
}
struct node* deletelist(struct node *head){//for clearance of list
    if(head==NULL)return NULL;
    struct node *n,*temp=head;
    while(temp!=NULL){
        n=temp->next;
        free(temp);
        temp=n;
    }
    head=NULL;
    return head;
}
void admin(){
    printf("\n\t\t\t\t\t\t\t Admin Section");
    int opt=0;
    do{
        adminmenu();
        struct node *temp=heada; 
        int num,f=0;
        string name;
        float price;
        scanf("%d",&opt);
        if(opt==5)break;
        switch(opt){
            case 1:
                displaylist(heads);
                break;
            case 2:
                printf("\n\t\t\t\tEnter serial number of food item");
                scanf("%d",&num);
                f=0;
                while(temp!=NULL){
                    if(temp->data==num){
                        printf("\n\t\t\t\tGiven serial number already exists\n");
                        f=1;
                        break;
                    }
                    temp=temp->next;
                }
                if(f==1)break;
                printf("\n\t\t\t\tenter food item");
                cin >> name;
                printf("\n\t\t\t\tEnter price ");
                scanf("%f",&price);
                heada=createadmin(num,name,price);
                printf("\n\t\t\t\titem added successfully");
                break;
            case 3:
                if(deleteadminorcust(heada)){
                    printf("\n\t\t\t\tupdated list of food item menu\n");
                    displaylistad();
                }
                else printf("food item with given serial number doesnt exists\n");
                break;
            case 4:
                printf("\n\t\t\tOrder menu is\n");
                displaylistad();
                break;
            case 5:
                break;
            default:
                printf("\n\t\t\tEnter valid option\n");
                break;
        }
    }while(opt!=5);
}
void cust(){
    printf("\n\t\t\t\t\t\t\t Customer Section");
    int f=0,j=1,opt=0;
    char ch;
    do{
        customermenu();
        //int opt;
        scanf("%d",&opt);
        //if(opt==5)break;
        switch (opt){
            case 1:
                displaylistad();
                printf("\n\t\t\t\t Enter number corresponding to item you want");
                int n;
                scanf("%d",&n);
                printf("Enter quantity:");
                int quantity;
                scanf("%d",&quantity);
                headc=createcustomer(n,quantity);
                break;
            case 2:
                printf("\n\t\t\tList of ordered items are");
                displaylist(headc);
                break;
            case 3:
                if(deleteadminorcust(headc)){
                    printf("\n\t\t\t Updated list is");
                    displaylist(headc);
                }
                else printf("\n\t\t\tNo such serial number exists");
            case 4:
                calculatesales();
                printf("\n\t\t\tFinal Bill ");
                dispalybill();
                headc=deletelist(headc);
                printf("\n\t\t\t press any key to return to main menu\n\n\n");
                fflush(stdin);
                ch=fgetc(stdin);
                f=1;
                break;
            case 5:
                break;
            default:
                printf("\n\t\t\t Choose valid option");
        
        }
        if(f==1)break;
    }while(opt!=5);
    
}
void mainmenu(){
    printf("\n\t\t \t\t\tWELCOME TO REASTAURANT");
    printf("\n\t\t\t1.Admin section");
    printf("\n\t\t\t2. customer section");
    printf("\n\t\t\t3. EXIT");
    printf("\n\t\t\tEnter your option");
}
int main(){
    heada=createadmin(1,"chicken_biriyani",200);
    heada=createadmin(2,"veg_biriyani",150);
    heada=createadmin(3,"chicken_manchuria",120);
    heada=createadmin(4,"chicken_65",200);
    heada=createadmin(5,"veg_fried_rice",100);
    int choice=0;
    while(1){
        mainmenu();
        int choice;
        scanf("%d",&choice);
        if(choice==1)admin();
        else if(choice==2)cust();
        else if(choice==3)break;
        else  printf("\t\n\n\nEnter valid option");
    }
    return 0;
}
