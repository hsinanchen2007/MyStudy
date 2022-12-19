### 解题思路
从后向前看，不要试图跳过最后一个空格，若是空格不进行计数即可。

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int num=0;
        for(int i=len-1;i>=0;i--){
            if (s[i]!=' ')
                num++;
            else{
                if (num!=0)
                    return num;
            }
        }
        return num;
    }
};
```