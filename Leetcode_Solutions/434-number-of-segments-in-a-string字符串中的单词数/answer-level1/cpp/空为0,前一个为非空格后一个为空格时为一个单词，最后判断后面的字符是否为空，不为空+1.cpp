### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
    if(s.empty())return 0;
        int count=0;
        int i=0;
        for(i=1; i<s.size(); i++){
           if(s[i-1]!=' '&&s[i]==' '){
                count++;
              
            }
        }
        if(s[i-1]!=' '){count++;}
        return count;
    }
};
```