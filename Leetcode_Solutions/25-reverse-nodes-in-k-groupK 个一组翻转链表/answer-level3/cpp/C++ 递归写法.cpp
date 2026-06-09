### 解题思路
递归的子问题为： 新的头部->next = 连续k个翻转后的链表。
其中连续k个节点翻转用头插法。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * p, *q, *pre;
        pre = new ListNode(0);
        pre->next = dfs(head, k);
        return pre->next;
    }
    ListNode* dfs(ListNode* head, int k)
    {
        int len = 0, n = 1;
        ListNode* p = head;
        //判断剩余链表长度是否符合要求
        while(p)
        {
            len++;
            p = p->next;
        }
        if(len < k) return head;//小于k，不进行操作直接返回。

        p = head; //新的头部，默认从k=1开始，头部就是head。
        ListNode *q, *temp;
        q = p->next; //next link;
        p->next = NULL;
        while(q && n < k)//头插法翻转
        {
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
            n++;
        }
        head->next = dfs(q, k); //剩余链表递归，接到链表尾部。因为翻转后head就成了倒数第一个节点了
        return p;
    }
};
```
