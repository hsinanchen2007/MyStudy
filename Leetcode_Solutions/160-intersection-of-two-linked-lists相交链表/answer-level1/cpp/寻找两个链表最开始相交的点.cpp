### 解题思路
题目要求，去找到最开始相交的点。
思路：用二重循环去判断。思路简单，缺点是费时耗空间

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 用二重循环来做
        if(!headA||!headB) return NULL;
        ListNode *p,*q;
        p=headA;
      //  q=headB;
        for(;p!=NULL;p=p->next){
            for(q=headB;q!=NULL;q=q->next){
                if(p==q) return p;
            }
            
        }
        return NULL;
    }
};
```