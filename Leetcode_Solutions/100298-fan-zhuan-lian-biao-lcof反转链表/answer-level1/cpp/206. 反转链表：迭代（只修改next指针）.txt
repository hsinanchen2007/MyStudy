### 解题思路
只修改next指针。
[上一个题解](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/206-fan-zhuan-lian-biao-di-gui-yu-die-dai-by-user4/)使用迭代（新建节点）耗时太高了。

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
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;    // 空链表直接返回NULL

        ListNode *h = NULL;
        ListNode *tmp = head;
        while(tmp) {        // 迭代反转
            tmp = tmp->next;
            head->next = h;
            h = head;
            head = tmp;
        }
        return h;
    }

};
```
![3.png](https://pic.leetcode-cn.com/402d04c11571e39014427d9d00b767690525e73a1781c377f9a6ce045fde5760-3.png)
