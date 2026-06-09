### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int cnt=0;
        int length=s.size();
        s+="PP";
        for(int i=0;i<length;++i){
            if(s[i]=='A') ++cnt;
            if(cnt>1) return false;
            if((s[i]=='L')&&(s[i+1]=='L')&&(s[i+2]=='L'))
            return false; 
        }
        return true;
    }
};
```