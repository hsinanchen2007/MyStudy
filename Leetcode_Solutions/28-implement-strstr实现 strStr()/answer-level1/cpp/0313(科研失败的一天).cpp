### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle || needle=="") return 0;
        vector<int> f;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0])
                f.push_back(i);
        }
        for(int k=0;k<f.size();k++){
            if(f[k]+needle.size()>haystack.size())
                return -1;
            else{
                int i=f[k],j;
                for(j=0;j<needle.size();j++){
                    if(haystack[i]==needle[j])
                        i++;
                    else
                        break;
                }
                if(j==needle.size())
                    return f[k];    
            }
        }
        return -1;
    }
};
```