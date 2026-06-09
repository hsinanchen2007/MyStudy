### 解题思路
两种思路，递归和迭代

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
//迭代：假设有已经解决的后几位结果，怎么利用这个结果获得前面
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 )return l2;
        if(!l2 )return l1;
        if(l1 -> val <= l2 -> val ) 
        {
            l1-> next = mergeTwoLists(l1 -> next , l2);
            return l1;
        }
        else
        {
            l2-> next = mergeTwoLists(l2 -> next , l1);
            return l2;
        }
    }
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1  )return l2;
        if(!l2  )return l1;
        ListNode* head;
        if(l1 -> val <= l2 -> val ) 
        {
            head=l1;
            l1 = l1 -> next;
        }
        else  
        {
            head=l2;
            l2 = l2 -> next;
        }
        ListNode* head0 = head;
        while(l1 && l2)
        {
            if(l1 -> val < l2 -> val ) 
            {
                head -> next =l1;
                l1 = l1 -> next;
            }
            else 
            {
                head -> next =l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        while(l1)
        {
            head -> next =l1;
            l1 = l1 -> next;
            head = head -> next;
        }
        while(l2)
        {
            head -> next =l2;
            l2 = l2 -> next;
            head = head -> next;
        }
        return head0;
    }*/
};
```