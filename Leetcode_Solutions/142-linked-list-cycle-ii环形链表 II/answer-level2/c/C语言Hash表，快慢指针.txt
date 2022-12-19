### 解题思路
重要思路如图
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //Hash表方法
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head) return NULL;
    struct ListNode *hash[10000]={0};//Maxsize=10000
    while(head)
    {
        int pos=(unsigned int)head%10000;
        while(hash[pos]!=head&&hash[pos]!=NULL) pos++;//查找hash表，含冲突处理
        if(!hash[pos]) {hash[pos]=head;head=head->next;}
        else return head;
    }
    return NULL;
}

//快慢指针
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow=head,*fast=head;
    if(!head) return NULL;
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) 
        {
            slow=head;
            while(slow!=fast) //相遇，head到环结点的距离=相遇处结点到环结点的距离
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
```