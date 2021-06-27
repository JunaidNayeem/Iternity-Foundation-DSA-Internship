//1. Detect cycle in a linked list.

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int val){
            data=val;
            next=NULL;
        }
};

void insert(node *&head, int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void createCycle(node *&head, int pos){
    node *temp=head;
    node *cycleNode;
    int count=0;
    while(temp->next!=NULL){
        if(count==pos){
            cycleNode=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=cycleNode;
}

bool detectCycle(node *head){
    bool flag=false;
    node *walk=head;
    node *run=head;
    while(run!=NULL && run->next!=NULL){
        run=run->next;
        if(run==walk){
            flag=true;
            break;
        }
        walk=walk->next;
        run=run->next;
    }
    return flag;
}
void removeCycle(node *&head){
    node *walk=head;
    node *run=head;
    do{
        walk=walk->next;
        run=run->next->next;
    }while(walk!=run);
    int point;
    run=head;
    while(run->next!=walk->next){
        run=run->next;
        walk=walk->next;
    }

    point=run->data;
    cout<<"Point at which Cycle Starts :"<<point<<endl;
    walk->next=NULL;
}
int main(){
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    createCycle(head,3);
    if(detectCycle(head)==true){
        cout<<"The given List is Cyclic"<<endl;
    }
    else{
        cout<<"The given List is not Cyclic"<<endl;
    }
    removeCycle(head);
    display(head);
    if(detectCycle(head)==true){
        cout<<"The given List is Cyclic"<<endl;
    }
    else{
        cout<<"The given List is not Cyclic"<<endl;
    }
    return 0;
}



//return start of the cycle
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define itr(i,a,b) for(int i=a;i<b;i++)

void heapify(vi &a, int n, int i){
    int maxInx=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && a[l]>a[maxInx])
        maxInx=l;
    if(r<n && a[r]>a[maxInx])
        maxInx=r;

    if(maxInx != i){
        swap(a[i],a[maxInx]);
        heapify(a,n,maxInx);
    }
}
void heapSort(vi &a){
    int n=a.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(a,n,i);
    }
    for(int i=n-1; i>0; i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    vi a(n);
    itr(i,0,n){
        cin>>a[i];
    }

    heapSort(a);
    itr(i,0,n){
        cout<<a[i]<<" ";
    }
    return 0;
}



//Imolementation of Radix Sort
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define itr(i,a,b) for(int i=a;i<b;i++)

int getMax(vi &a){
    int n=a.size();
    int mx=a[0];
    
    itr(i,0,n)
        mx=max(a[i],mx);
    return mx;
}
void countSort(vi &a, int n, int pos){
    vi b(n),count(10);
    int i;
    count[10]={0};
    itr(i,0,n){
        ++count[(a[i]/pos)%10];
    }
    itr(i,1,10){
        count[i]+=count[i-1];
    }
    //making output array
    for(i=n-1;i>=0;i--){
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    itr(i,0,n){
        a[i]=b[i];
    }
}
void radixSort(vi &a){
    int n=a.size();
    int mx=getMax(a);
    int pos;
    for(pos=1; mx/pos>0; pos*=10){
        countSort(a,n,pos);
    }
}  
int main(){
    int n;
    cin>>n;
    vi s(n);
    itr(i,0,n){
        cin>>s[i];
    }
    radixSort(s);
    itr(i,0,n)
        cout<<s[i]<<" ";
    return 0;
}




//Implementation of Doubly LinkedList
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;
        node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};

void insertAtHead(node *&head, int val){
    node *n=new node(val);
    n->next=head;
        if(head!=NULL)
            head->prev=n;
        head=n;
}
void insert(node *&head, int val){
    node *n=new node(val);
    node *temp=head;
    if(head==NULL){
        n->next=head;
        if(head!=NULL)
            head->prev=n;
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node *head){
    node *temp=head;
    cout<<"NULL <-> ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(node *&head, int pos){
    node *temp=head;
    int count=1;
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete temp;
}

int main(){
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insertAtHead(head,7);
    display(head);
    int pos;
    cout<<"Enter the position of node you want to delete :";
    cin>>pos;
    deletion(head,pos);
    display(head);
    return 0;
}




//Sort Doubly Linkedlist
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;
        node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};

void insertAtHead(node *&head, int val){
    node *n=new node(val);
    n->next=head;
        if(head!=NULL)
            head->prev=n;
        head=n;
}
void insert(node *&head, int val){
    node *n=new node(val);
    node *temp=head;
    if(head==NULL){
        n->next=head;
        if(head!=NULL)
            head->prev=n;
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node *head){
    node *temp=head;
    cout<<"NULL <-> ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void sort(node *&head){
    node *currPtr=head;
    node *indexPtr;
    int temp;
    if(head==NULL){
        return;
    }
    while(currPtr->next!=NULL){
        indexPtr=currPtr->next;
        while(indexPtr!=NULL){
            if(currPtr->data>indexPtr->data){
                temp=currPtr->data;
                currPtr->data=indexPtr->data;
                indexPtr->data=temp;
            }
            indexPtr=indexPtr->next;
        }
        currPtr=currPtr->next;
    }

}

int main(){
    node *head=NULL;
    insert(head,3);
    insert(head,5);
    insert(head,1);
    insert(head,4);
    insert(head,2);
    insert(head,6);
    insertAtHead(head,7);
    cout<<"Unsorted Doubly Linked List : "<<endl;
    display(head);
    sort(head);
    cout<<"Sorted Doubly Linked List : "<<endl;
    display(head);
    return 0;
}




//Implementation of Circular LinkedList
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
    }
};
//inset at Head
void insertAtHead(node *&head, int val){
    node *n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node *temp=head;
    while (temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
//insert Function
void insert(node * &head, int val){
    node *n=new node(val);

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node *temp=head;
    while (temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteAthead(node *&head){
    node *temp=head;
    while(temp!=head){
        temp=temp->next;
    }
    node *todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}
///deletion function
void deletion(node *&head, int pos){
    int count=1;
    if(pos==1){
        deleteAthead(head);
        return;
    }
    node *todelete;
    node *temp=head;
    while(count!=pos-1){
        count++;
        temp=temp->next;
    }
    todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(node *head){
    node *temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->data<<endl;
}
int main(){
    node *head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    deletion(head,4);
    display(head);
    //display(newNode);
    return 0;
}




//9
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
    }
};
//insert Function
void insert(node * &head, int val){
    node *n=new node(val);

    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
//to return require new node
node *nodeSum(node *head1, node *head2){
    node *sumNode=NULL;
    node *temp1=head1;
    node *temp2=head2;
    long long int sum,carry=0;
    while(temp1!=NULL && temp2!=NULL){
        cout<<temp1->data<<" + "<<temp2->data<<" = ";
        if(temp1==NULL)
            sum=temp2->data+carry;
        else if(head2==NULL)
            sum=temp1->data+carry;
        else
            sum=temp1->data+temp2->data+carry;
        if(sum>=10){
            sum=sum-10;
            carry=1;
        }
        else
            carry=0;
        cout<<sum<<endl;
        insert(sumNode,sum);
        if(temp1!=NULL)
        temp1=temp1->next;
        if(temp2!=NULL)
        temp2=temp2->next;
    }
    return sumNode;
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node *head1=NULL;
    node *head2=NULL;
    insert(head1,2);
    insert(head1,4);
    insert(head1,3);
    insert(head1,9);
    insert(head1,9);
    insert(head1,9);
    insert(head1,9);
    insert(head2,5);
    insert(head2,6);
    insert(head2,4);
    insert(head2,9);
    display(head1);
    display(head2);
    node *sN=nodeSum(head1,head2);
    display(sN);
    return 0;
}
