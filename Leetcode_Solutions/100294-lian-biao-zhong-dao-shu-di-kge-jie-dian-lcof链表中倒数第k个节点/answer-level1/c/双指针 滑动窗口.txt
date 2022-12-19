### 解题思路
双指针 滑动窗口
![image.png](https://pic.leetcode-cn.com/bd6110426e24387739ae5d40dafb1089920cb37fca2fb1bcc4511d64f0d9e75c-image.png)

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
    struct ListNode* right = head;
    struct ListNode* left = right;
    int i = 1;
    while(i < k){
        right = right->next;
        i++;
    }
    while(right->next){
        right = right->next;
        left = left->next;
    }
    return left;
}
```