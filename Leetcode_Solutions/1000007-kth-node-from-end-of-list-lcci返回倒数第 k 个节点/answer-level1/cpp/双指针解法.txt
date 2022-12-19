### 解题思路
两个指针p、q初始化都指向头结点。p指针先走k步后，q指针再走。当p指针走到链尾后，此时的q指针就是在倒数第k个位置

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
    int kthToLast(ListNode* head, int k) {
        ListNode *p=head ,*q=head;
        int count=0;
        while(p){
            if(count>=k) q=q->next;
            p=p->next;
            count++;
        }
        return q->val;
    }
};
```