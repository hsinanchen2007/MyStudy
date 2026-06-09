### 解题思路


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
    ListNode* backnode = nullptr;
    //反转前m到n个节点
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1)
        {
            return reverseN(head,n);
        }
        head -> next = reverseBetween(head -> next,m - 1,n - 1);
        return head;
    }
    //反转前n个节点
    ListNode* reverseN(ListNode* head,int n)
    {
        if(n == 1)
        {
            backnode = head -> next;
            return head;
        }
        ListNode* last = reverseN(head -> next,n - 1);
        head -> next -> next = head;
        head -> next = backnode;
        return last;
        
    }
    //每隔k反转
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* test = head;
        ListNode* ans = nullptr;
        while(test)
        {
            size++;
            test = test -> next;
        }
        for(int i = 1;i + k - 1 <= size;i += k)
        {
            head = reverseBetween(head,i,i + k - 1);
        }
        
        return head;
    }
};
```