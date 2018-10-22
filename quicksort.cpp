#include <iostream>
#include <cstdio>
using namespace std;
 

class LLNode
{
public:
    int data;
    LLNode *next;
};
 
//chen node
void insertAtBeginning(LLNode**head,int dataToBeInserted)
{
    LLNode*curr=new LLNode;
    //tao node moi va con cho chi den NUll
    curr->data=dataToBeInserted;
    curr->next=NULL;

    if(*head==NULL) //neu ds trong thi dat node vao dau ds
            *head=curr;
        
    else 
        {
            curr->next=*head;
            *head=curr;
        }
        
        //O(1) const time
}
 
// in lkl
void display(LLNode**head)
{
    LLNode*temp=*head;
    while(temp!=NULL) 
        {
            if(temp->next!=NULL)
            cout<<temp->data<<" ->";
            else
            cout<<temp->data;
            
            temp=temp->next;
        }
        
    cout<<endl;
}
 
// tra ve node cuoi
LLNode *getTail(LLNode *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// chia vung ds
LLNode *partition(LLNode *head, LLNode *end, LLNode **newHead, LLNode **newEnd)
{
    LLNode *pivot = end;
    LLNode *prev = NULL, *cur = head, *tail = pivot;
 
    
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // nut dau nho hon pivot thi tro thanh node moi
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else 
        {
            // neu lon hon pivot thi di chuyen xuong duoi
            if (prev)
                prev->next = cur->next;
            LLNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // neu nho hon thi di chuyen len dau
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    (*newEnd) = tail;
    return pivot;
}
 
 
LLNode *quickSortRecur(LLNode *head, LLNode *end)
{
    if (!head || head == end)
        return head;
 
    LLNode *newHead = NULL, *newEnd = NULL;
 
    // phan vung ds, cap nhat head va tall
    LLNode *pivot = partition(head, end, &newHead, &newEnd);
 
    // pivot nho nhat thi ko can dat lai
    if (newHead != pivot)
    {
        // dat node truoc pivot
        LLNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 

        newHead = quickSortRecur(newHead, tmp);
 
        // lay nua trai thanh pvot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 

void quickSort(LLNode **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 

int main()
{
    LLNode *head = NULL;
    LLNode *tail = NULL;

    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 16);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 23);
 
    cout << "Linked List truoc khi sap xep \n";
    display(&head);
 
    quickSort(&head);
 
    cout << "Linked List sau khi sap xep \n";
    display(&head);
 
    return 0;
}