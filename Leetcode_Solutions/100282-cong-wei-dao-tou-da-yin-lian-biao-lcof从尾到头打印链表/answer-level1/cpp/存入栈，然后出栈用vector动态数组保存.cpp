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
    vector<int> reversePrint(ListNode* head) {//返回动态数组
        //if(head==nullptr) return 0;
        
        vector<int> res;
        //ListNode* node=new ListNode();
        ListNode* pnode=head;
        stack<int> node;//栈
        while(pnode!=nullptr)
        {
            node.push(pnode->val);
            pnode=pnode->next;
        }
        while(!node.empty())
        {
            res.push_back(node.top());
            node.pop();
        }
        return res;
    }
};
```