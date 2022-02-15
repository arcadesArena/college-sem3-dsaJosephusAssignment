#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
typedef struct node * NODE;
NODE head = NULL, tail = NULL;
int kill(int k)
{
    NODE temp = head;
    while (head->next != head)
    {
        NODE pre = NULL;
        for (int i = 1; i < k; i++)
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = head->next;
        }
        pre->next = temp->next;
        free(temp);
        temp = pre->next;
    }
    return head->data;
}
void createList(int n){
    for (int i = 1; i <= n; i++)
    {
        NODE newnode = (NODE)malloc(sizeof(struct node));
        newnode->data = i;
        if (head == NULL)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
    }
}
int josephus(int n, int k)
{
    if (k == 1)
        return n;
    createList(n);
    return kill(k);
}
int main()
{
    int n, k;
    printf("The number of prisoners: ");
	scanf("%d",&n);
	printf("The number of prisoners to be skipped: ");
	scanf("%d",&k);
    printf("The safe place is %d", josephus(n, k));
    return 0;
}