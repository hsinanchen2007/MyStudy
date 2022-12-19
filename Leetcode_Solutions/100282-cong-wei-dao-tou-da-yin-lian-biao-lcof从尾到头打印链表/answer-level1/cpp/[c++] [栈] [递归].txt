### 解题思路
解法一：栈
解法二：递归

### 代码
解法一
```cpp
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        //if(head==NULL) return res;
        stack<ListNode*> st;
        while(head){
            st.push(head);
            head=head->next;
        }
        while(!st.empty()){
            res.push_back(st.top()->val);
            st.pop();
        }
        return res;
    }
};
```
解法二
```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if(head==NULL) return res;
        helper(head,res);
        return res;
    }
    void helper(ListNode* node,vector<int>& res){
        if(node==NULL) return;
        helper(node->next,res);
        res.push_back(node->val);
    }
};
```