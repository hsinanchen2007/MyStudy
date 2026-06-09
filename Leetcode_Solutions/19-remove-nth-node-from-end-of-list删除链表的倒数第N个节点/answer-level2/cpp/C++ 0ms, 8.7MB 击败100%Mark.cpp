### 解题思路
没什么说的，上链表！
维护原链表中一段长度为 n + 1 的头尾指针（n + 1 是考虑到该链表为单向链表）

![image.png](https://pic.leetcode-cn.com/237f6ad69d4f95fbc59ab04dcffc0642c3208cb53978bdb7224df9737121bd17-image.png)


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // pst 是长度为(n+1)的链表的头指针，pen 是长度为(n+1)的链表的尾指针
        ListNode* pst = head;
        ListNode* pen = head;
        for(int i = 0; i < n; i ++)
            pen = pen -> next;
        // 特殊处理，如果 pen == NULL 说明删除的是第一个结点，直接返回 head -> next
        if(pen == NULL) return (head -> next);
        // pst 与 pen 同步后移
        while(pen -> next != NULL)
        {
            pst = pst -> next;
            pen = pen -> next;
        }
        // 删除节点
        pst -> next = pst -> next -> next;
        return head;
    }
};
```