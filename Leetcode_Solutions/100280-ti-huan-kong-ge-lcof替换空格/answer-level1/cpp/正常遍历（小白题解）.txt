
### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) 
    {
        if(s.empty()) return s;
        
        string res="";
        for(char c:s)
        {
            if(c==' ') res+="%20";
            else res+=c;
        }

        return res;
    }
};
```