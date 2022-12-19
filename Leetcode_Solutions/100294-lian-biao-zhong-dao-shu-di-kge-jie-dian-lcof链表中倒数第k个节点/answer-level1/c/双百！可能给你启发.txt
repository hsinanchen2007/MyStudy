### 解题思路
1.我选择的是快慢指针单次遍历，也是其他题解的一般思路
2.为了防止k值大于链表长度，增加了一个反馈if(slow==NULL&&k>0)return 0;但是题上好像对这个没要求。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *fast = head;
	struct ListNode *slow = head;
    while(fast!=NULL)
    {
        if(--k<0)slow=slow->next;
        fast=fast->next;
        if(slow==NULL&&k>0)return 0;
    }
    return slow;
	

}
```