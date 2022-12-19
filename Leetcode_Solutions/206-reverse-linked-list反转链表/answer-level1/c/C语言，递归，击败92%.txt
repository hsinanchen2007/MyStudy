### 解题思路
递归方法，
全局变量存放链表头，
next为空，表示到达了链表尾，为结束条件
![截图.PNG](https://pic.leetcode-cn.com/74a60a224cf7e927ce0011b9881fe5d939b5ea989621870d3753a1592832abcf-%E6%88%AA%E5%9B%BE.PNG)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* gret = NULL;
struct ListNode* ReverseNode(struct ListNode* cur)
{
    if (cur == NULL) {
        return NULL;
    }

    if (cur->next == NULL) {
        gret = cur;
        return cur;
    }
    struct ListNode* pre = ReverseNode(cur->next);
    pre->next = cur;
    cur->next = NULL;

    return cur;
}
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    gret = NULL;
    ReverseNode(head);

    return gret;
}
```