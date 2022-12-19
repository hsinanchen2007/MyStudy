```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<int,char>> vec;
        stack<pair<int,char>> st;     
        st.push(make_pair(-1,'#'));
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]==')'){
                vec.emplace_back(pair<int,char>(i,s[i]));
            }
        }
        for(auto e:vec){
            if(e.second=='(')
                st.push(make_pair(e.first,e.second));
            if(e.second==')'){
                if(st.top().second=='('){
                    st.pop();
                }
                else{
                    st.push(make_pair(e.first,e.second));
                }
            }
        }       
        while(st.top().second!='#'){
            s.erase(st.top().first,1);
            st.pop();
        }
        return s;
    }
};
```