### 解题思路
1.首先确定表头，找l1,l2中更小的一个(记得记录返回的表头)
2.使用2个指针h1,h2分别从l1,l2开始处向后比较，直到一条链表走到空
3.此时链接上另一条链表
![456.png](https://pic.leetcode-cn.com/37d08b2af31c15b4a6105409873c037406880be7885ce746fc3f5eb052f9e93e-456.png)

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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (l1 == NULL)
             return l2;
         if (l2 == NULL)
             return l1;
         ListNode* ans = NULL,*p=NULL;
         ListNode* h1 =NULL,*h2=NULL;
         if (l1->val < l2->val)
         {
             ans = l1;
             h1 = l1->next;
             h2 = l2;
         }
         else
         {
             ans = l2;
             h1 = l1;
             h2 = l2->next;
         }
         p=ans;
         while (h1 != NULL && h2 != NULL)
         {
             if (h1->val < h2->val)
             {
                 ans->next = h1;
                 ans = h1;
                 h1 = h1->next;
             }
             else
             {
                 ans->next = h2;
                 ans = h2;
                 h2 = h2->next;
             }
         }
         ans->next = (h1 == NULL) ? h2 : h1;
         return p;
     }
 };
```