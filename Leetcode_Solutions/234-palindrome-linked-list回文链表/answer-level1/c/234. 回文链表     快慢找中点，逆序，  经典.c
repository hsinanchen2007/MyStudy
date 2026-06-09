### 解题思路
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    struct ListNode* slow = head, *fast = head, *prev = NULL;
    struct ListNode* temp;
    
    //slow找的是中点后一个,
    //1 2 3 2 1　最终slow是２;　逆序的链表为1 2，　不影响我们比较
    //1 2 2 1 最长slow是２;
    while(fast){
        slow =slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    
    //printf("slow val=%d\n",slow->val);
    //从slow开始包含slow节点，　逆序
    while (slow) {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    while (head && prev) {
        if (head->val != prev->val)
            return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
```