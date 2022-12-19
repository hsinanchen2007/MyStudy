### 解题思路
找到合适的地方，断链收尾，在重新接上

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL || head->next==NULL|| k==0) return head;
    Node* prev=(Node*)malloc(sizeof(Node)); //哨兵节点
    prev->next=head;
    Node* _prev=prev; //先保存头部，等下准备被反转的连接 

    Node* cur=head; //哨兵的后一个节点 和哨兵配和找到断开的地方并收尾
    int len =0;
    while(head)  //求长度
    {
        len++;
        head=head->next;
    }
    k=k%len;
    if(k==0) //k是长度的倍数，怎么反转还是不变的
        return cur;
    int n=len-k;
    while(n--)  //找断开的地方
    {
        prev=prev->next;
        cur=cur->next;
    }
    prev->next=NULL; //收尾
    Node *tail=cur;  //变为头
    while(tail&&tail->next)
    {
        tail=tail->next;
    }
    tail->next=_prev->next; //连接之前保存的头部
    return cur;   
}
```