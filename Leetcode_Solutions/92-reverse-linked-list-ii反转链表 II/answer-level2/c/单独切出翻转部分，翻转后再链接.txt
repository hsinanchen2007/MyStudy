### 解题思路
参考翻转链表 https://leetcode-cn.com/problems/reverse-linked-list/

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(n==0) return head;
    int len=n-m+1;
    struct ListNode* p=NULL;//记录翻转起始点的前一个节点
    struct ListNode* h=head;//记录起始头结点
    while(head!=NULL&&m>1)
    {
        p=head;
        head=head->next;
        m--;
    }
    struct ListNode* prev=NULL;
    struct ListNode* cur=head;
    struct ListNode* temp;
    while(len>0)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        len--;
    }//此处参考翻转链表 https://leetcode-cn.com/problems/reverse-linked-list/
    head->next=cur;//翻转后head为尾。cur为下一个节点。连接尾巴未翻转部分
    if(p!=NULL)
    {
        p->next=prev;//不是从头翻转。
    }
    else return prev;//从头翻转
    return h;//头节点
}








```