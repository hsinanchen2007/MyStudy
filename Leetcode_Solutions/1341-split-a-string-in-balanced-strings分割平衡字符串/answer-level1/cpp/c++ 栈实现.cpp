```
class Solution {
public:
    int balancedStringSplit(string s) {
        if(s.empty()) return 0;
        stack<char> st;
        int num = 0;
        for(auto c:s){
            if(st.empty()){  
                st.push(c);
                num++;
            } 
            else{  //栈非空
                if(st.top() != c) st.pop(); //'R'与'L'匹配，出栈
                else st.push(c);  //相同字符入栈              
            }
        }
        return num;
    }
};
```
