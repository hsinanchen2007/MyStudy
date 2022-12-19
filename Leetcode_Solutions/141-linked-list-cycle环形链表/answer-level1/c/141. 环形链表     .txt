### 解题思路
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。





备注  step1 * 2 - step2  就是环的起始位置
这种两个步进还可以找链表中点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* s1 = head;
    struct ListNode* s2 = head;

    if(head == NULL)
        return false;
        
    while(s1->next && s2->next && s2->next->next){
        s1 = s1->next;
        s2 = s2->next->next;

        if(s2 == s1)
            return true;
    }
    return false;
        
}
```