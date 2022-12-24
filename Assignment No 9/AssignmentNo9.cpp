#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int bit){
        data=bit;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int data){
    node* newNode=new node(data);
    newNode->next=head;
   
    if(head!=NULL){
        head->prev=newNode;
    }
   
    head=newNode;
}

void insertAtEnd(node* &head,int data){
    if(head==NULL){
        insertAtHead(head,data);
        return;
    }
    node* newNode=new node(data);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void displaydll(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

void twosComplement(node* head){

    node* head1=NULL;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    int flag=1;
    while(temp!=NULL){
        if(flag==1){
            if(temp->data==1){
                insertAtHead(head1,1);
                flag=0;
                temp=temp->prev;
            }
            else{
                insertAtHead(head1,0);
            }
        }
        if(temp!=NULL && flag==0)
        {
            if(temp->data==1){
                insertAtHead(head1,0);
            }
            else{
                insertAtHead(head1,1);
            }
        }
        if(temp!=NULL){temp=temp->prev;}
    }
    cout<<"2's Complement of the binary no. is: ";
    displaydll(head1);
}

void onesComplement(node* head){
    node* head1=NULL;
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==1){
            insertAtEnd(head1,0);
        }
        else{
            insertAtEnd(head1,1);
        }
        temp=temp->next;
    }
    cout<<"1's Complement of the binary no. is: ";
    displaydll(head1);
}

void addition(node* head1, node* head2){
    node* result=NULL;
    node* temp1=head1;
    node* temp2=head2;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    int carry=0;
    while(temp1!=NULL && temp2!=NULL){
        int sum=((carry)^(temp1->data)^(temp2->data));
        carry=((temp1->data)&&(temp2->data) || (temp2->data)&&
        (carry) || (temp1->data)&&(carry));
        insertAtHead(result,sum);
        temp1=temp1->prev;
        temp2=temp2->prev;
    }
    if(carry==1){
        insertAtHead(result,1);
    }
    cout<<"Sum of Two binary no.s is: ";
    displaydll(result);
   
}

int main()
{
    node* head1=NULL;
    int n;
    cout<<"Enter the no. of bits:";
    cin>>n;
    for(int i=0;i<n;i++){
        int bit;
        cout<<i<<":";
        cin>>bit;
        if(bit<=0){
            insertAtEnd(head1,0);
        }
        else{
            insertAtEnd(head1,1);
        }
       
    }
    cout<<"Binary no. 1 is: ";
    displaydll(head1);
    onesComplement(head1);
    twosComplement(head1);

    node* head2=NULL;
    int n1;
    cout<<"Enter the no. of bits:";
    cin>>n1;
    for(int i=0;i<n1;i++){
        int bit;
        cout<<i<<":";
        cin>>bit;
        if(bit<=0){
            insertAtEnd(head2,0);
        }
        else{
            insertAtEnd(head2,1);
        }
       
    }
    cout<<"Binary no. 2 is: ";
    displaydll(head2);
    onesComplement(head2);
    twosComplement(head2);
    addition(head1,head2);
    return 0;
}

