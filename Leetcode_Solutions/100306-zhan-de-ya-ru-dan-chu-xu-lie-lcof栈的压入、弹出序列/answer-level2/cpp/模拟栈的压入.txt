### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int push_id,pop_id;
        push_id = pop_id = 0;
        while(push_id!=n){
            if(pushed[push_id]==popped[pop_id]){
                push_id++;
                pop_id++;
            }
            else{
                if(!st.empty()&&st.top()==popped[pop_id]){
                    st.pop();
                    pop_id++;
                }
                else{
                    st.push(pushed[push_id]);
                    push_id++;
                }
            }
        }
        while(!st.empty()){
            if(st.top()==popped[pop_id]){
                st.pop();
                pop_id++;
            }
            else{
                return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
```