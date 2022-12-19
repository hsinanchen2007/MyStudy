### 解题思路
此处撰写解题思路

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
       ListNode  * newlist = new ListNode(0); 
       ListNode * frist  =newlist;
       ListNode * ans;
       while(l1 != NULL || l2 != NULL)
       {
           if(l1 == NULL)
           {
                newlist->next = l2;
                break;
           }
          
           else if (l2 == NULL )
          { 
              newlist->next = l1;
              break;
          } 
           else
           {
               if(l1->val >  l2 ->val)
               {
                   newlist->next = l2 ;
                   newlist =newlist->next;
                   l2 =l2 ->next;
               }
               else
               {
                   newlist->next = l1;
                   newlist = newlist->next;
                   l1 = l1->next;
               }
           }
       }
      
      ans = frist->next;
      return ans;

    }
    
    
};
```