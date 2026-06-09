### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        map<char,char> ma;
        ma['}']='{';
        ma[']']='[';
        ma[')']='('; 
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push_back(s[i]);
            else{
                if(st.size()<1||ma[s[i]]!=st.back()) return false;        
                st.pop_back();               
            }            
        }
        
        return st.empty();
    }
};

```