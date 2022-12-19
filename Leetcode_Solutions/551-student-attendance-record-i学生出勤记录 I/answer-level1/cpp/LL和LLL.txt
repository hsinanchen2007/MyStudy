### 解题思路
主要还是理解题目意思吧。LL是OK的，也就是A最多一个而且L连续三次不可以。
### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int cntA=0,cntL=0;
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='A'){
                cntA ++;
            }else if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L'&&i+1<=s.length()){
                cntL ++;
            }
        }
        if(cntA>1 || cntL>=1)
            return false;
        else
            return true;
    }
};
```