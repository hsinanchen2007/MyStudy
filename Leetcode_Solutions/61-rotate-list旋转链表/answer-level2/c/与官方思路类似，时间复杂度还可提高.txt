### 解题思路
先用一次遍历得到链表长度len，找到新的head结点（n-k结点）和end结点（n-k-1），将链表重新排列即可。
太傻了，第一次做的时候没过脑子，直接用描述的方法循环右移，被一个案例k=20000000教做人了
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *lastp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    p->next = head;
    int len = 0;
    while(p->next!=NULL){
        p = p->next;
        len++;
    }//此时p为最后的结点
    if(len==1 || head==NULL)
        return head;
    else if(k>=len)
        k = k % len;
    p->next = head;//EndNode->next = head
    p = head;
    for(int i=0;i<len-k;i++){
        lastp = p;
        p = p->next;
    }//此时p为n-k结点
    dummy->next = p;
    lastp->next = NULL;
    
    return dummy->next;
}
```