### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了5.76%的用户
+ 双指针
以第`m-1`节点为"头节点"，将[m,n]范围的节点不断插入"头节点"后，最后，第m个节点指向第n+1个节点

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {  
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // 第m-1个节点
        ListNode *pre=dummy;
        for(int i=1; i<m; i++){
            pre = pre->next;
        }

        // 第m个节点
        ListNode *t, *cur=pre->next, *mNode=pre->next;
        // 头插法
        for(int i=m; i<=n; i++){
            t = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = t;
        }
        // 第m个节点指向第n+1个节点
        mNode->next = cur;
        
        return dummy->next;
    }
};
```