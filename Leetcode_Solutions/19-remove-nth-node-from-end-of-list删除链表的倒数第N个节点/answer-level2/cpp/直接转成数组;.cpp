### 解题思路
直接转成数组;

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
        vector<ListNode*>  vNode;
        while(head != NULL)
        {
            vNode.push_back(head);
            head = head->next;
        }
        
        int iIndex = vNode.size() - n;
        if(iIndex - 1 >= 0 && iIndex + 1 < vNode.size())
        {
            vNode[iIndex - 1 ]->next = vNode[iIndex + 1 ];
        }

        if(iIndex == vNode.size() - 1 && iIndex - 1 >= 0)
        {
            vNode[iIndex - 1]->next =NULL;
        }

        if(iIndex == 0 && vNode.size() > 1)
        {
            return vNode[1];
        }

        if(vNode.size() > 1)
        {
            return vNode[0];
        }else
            return NULL;
        


        
    }
};
```