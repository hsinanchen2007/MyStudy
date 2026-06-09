### 解题思路
快指针走两步，慢指针走一步，快指针遍历结束慢指针正好到中间
![image.png](https://pic.leetcode-cn.com/e3db79391ee9418bcd6ce95cb7bc4930280c0ac2779549898958372f5b1b8024-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```