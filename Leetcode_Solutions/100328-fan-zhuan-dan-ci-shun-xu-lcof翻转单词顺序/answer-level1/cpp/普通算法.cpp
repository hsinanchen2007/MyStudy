
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string temp="";
        
        for(char c:s)
        {
            if(c==' ') {if(!temp.empty()) vs.push_back(temp);temp.clear();}
            else temp.push_back(c);
        }
        if(!temp.empty()) vs.push_back(temp);
        
        if(vs.empty()) return "";
        
        reverse(vs.begin(),vs.end());
        
        string res=vs[0];
        for(int i=1;i<vs.size();i++)
        {
            res+=" ";
            res+=vs[i];
        }
        
        return res;
    }
};
```