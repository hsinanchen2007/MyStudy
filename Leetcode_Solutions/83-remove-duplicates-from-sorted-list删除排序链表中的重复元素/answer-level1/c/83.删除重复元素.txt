### 解题思路
![1578232629(1).png](https://pic.leetcode-cn.com/c3e67bc0395597ade9d64cf957f0df4e3700bd7698de49c1215024a44ceef688-1578232629\(1\).png)
写的比较乱，特别是指针不为空的条件。主要的方向为双指针循环访问链表，问题在保证指向head->next的指针在定义时不为空，因此我添加了一个if条件之后再初始化的指针q。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
 struct ListNode* p=head;
    if(p==0)
    {
        return NULL;
    }
    if(p->next==0)
    {
        return p;
    }
    if(p->next!=0)
    {
        struct ListNode* q=p->next;
    
    while(p!=0&&q!=0)
    {
    if(p->val==q->val)
    {
        q=q->next;
        p->next=q; 
    }
    if(q!=0&&p!=0&&p->val != q->val)
    {
        p=p->next;
        q=q->next;
    }
    }
    }
    return head;
}
```