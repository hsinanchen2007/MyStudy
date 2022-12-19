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
    vector<int> reversePrint(ListNode* head) {
        stack<int> res;
        vector<int> a;
        if(head==nullptr) return a;
        while(head!=nullptr)
        {
            res.push(head->val);//
            head=head->next;
        }
        //输出
        //for(int i=0;i<=res.size();++i)这里不可以用res.size()因为res长度在变化
        while(res.size()!=0)
        {
            a.push_back(res.top());
            res.pop();
        }
        return a;
    }
};
```