### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int m=s.size();
        if(0==m) return 0;
        int res(0);
        bool start=false;
        for(int i=m-1;i>=0;--i){
            if(s[i]==' '&&start==true) break;
            else if(s[i]==' '&&start==false) continue;
            else{ //(s[i]!=' ')
                ++res;
                start=true;
            }
        }
        return res;
    }
};
```