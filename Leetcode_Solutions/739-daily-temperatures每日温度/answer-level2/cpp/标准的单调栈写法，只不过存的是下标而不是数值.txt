```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> res(T.size());
        for(int i = T.size()-1;i >=0;--i){
            while(!st.empty() && T[st.top()] <= T[i]) st.pop();
            res[i] = st.empty()?0:st.top()-i;
            st.push(i);
        }
        return res;
    }
};
```
