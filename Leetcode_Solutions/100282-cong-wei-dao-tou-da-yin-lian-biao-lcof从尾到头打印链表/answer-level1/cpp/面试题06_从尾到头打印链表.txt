### 解题思路
方法一：栈

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
    vector<int> reversePrint(ListNode* head) {

        stack<ListNode*> nodes;//设置一个栈
        vector<int> result;
        ListNode* pNode=head;
        while(pNode!=NULL)
        {
            nodes.push(pNode);
            pNode=pNode->next;
        }
        while(!nodes.empty())
        {
            pNode=nodes.top();
            int temp=pNode->val;
            result.push_back(temp);
            nodes.pop();
            
        }
        return result;
    }
};
```