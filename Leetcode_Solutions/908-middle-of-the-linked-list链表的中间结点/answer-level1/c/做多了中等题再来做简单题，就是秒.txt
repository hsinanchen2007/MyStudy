### 解题思路
![image.png](https://pic.leetcode-cn.com/9eb67faac36c37832f9f09a19614a1014663a24e9b4436c422fa839d175caeb7-image.png)


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
    struct ListNode* f=head;
    struct ListNode* s=head;
    while(f&&f->next){
        s=s->next;
        f=f->next->next;
    }
    return s;
}
```