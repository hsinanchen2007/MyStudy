单调栈，记录小的数的位置放在栈顶，一旦遇到比栈顶大的即出栈，这个数为栈顶这个数的解。
初始化数组为0，就不用处理后面没有比他大的数的情况了。
```
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>l;
        l.clear();
        stack<int>st;
        ListNode *p=head;
        while(p){
            l.push_back(p->val);
            p=p->next;
        }
        vector<int>ans(l.size(),0);
        for(int i=0;i<l.size();i++){
            while(!st.empty()&&l[st.top()]<l[i]){
                ans[st.top()]=l[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
```
