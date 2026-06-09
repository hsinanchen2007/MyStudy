### 解题思路
* 读出链表长度len，O(n)
* 找到后半段链表（奇数则找到中间节点，偶数则找右边节点），O(n)
* 反转后半段链表，O(n)
* 从head，tail开始比较，退出条件是tail==NULL（在反转链表时后半段链表更快接近NULL结尾），O(n)

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)    return true;
        // 读出链表长度len，O(n)
        int len = 0;
        for(ListNode *t = head; t; t = t->next) len++;
        // 找到后半段链表，O(n)
        ListNode *t = head;
        for(int i=0; i < len / 2; i++) t = t->next;
        // 反转后半段链表
        ListNode * tail = reverseList(t);
        /* 不用函数
        ListNode * tail = NULL;
        for(; t; ) {
            ListNode *tmp = t->next;
            t->next = tail;
            tail = t;
            t = tmp;
        }
        */
        // 首尾开始遍历，tail == NULL 结束
        while(tail) {
            if(head->val == tail->val) {
                head = head->next;
                tail = tail->next;
            }
            else
                return false;
        }
        return true;
    }
    ListNode* reverseList(ListNode *h) {
        ListNode *t = NULL;
        for(; h; ) {
            ListNode *tmp = h->next;
            h->next = t;
            t = h;
            h = tmp;
        }
        return t;
    }
};
```
![2.png](https://pic.leetcode-cn.com/25958cf57339cf0efcc0404e118130ba5dc218a08cad8f23e3843e9b0d94f0f5-2.png)

* 如果不使用reverseList函数，稍有优化
![3.png](https://pic.leetcode-cn.com/daabcaf21954d2d0eac5dd4351938c695a0c592a136a1c08f34678607513fad2-3.png)
