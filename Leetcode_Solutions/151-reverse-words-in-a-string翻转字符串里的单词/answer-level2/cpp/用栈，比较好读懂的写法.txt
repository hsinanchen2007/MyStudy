```
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)  return "";
        
        string ans;
        stack<string> st;
        string tmp;
        for (auto c:s){
            if (c == ' ')   {
                if (tmp.size() != 0){
                    st.push(tmp);
                    tmp.clear();
                }
                continue;
            }
            tmp += c;
        }

        if (tmp.size() != 0)    st.push(tmp);

        while(!st.empty()){
            ans += st.top();
            st.pop();
            if (st.size() != 0) ans += ' ';
        }

        return ans;
    }
};
```
