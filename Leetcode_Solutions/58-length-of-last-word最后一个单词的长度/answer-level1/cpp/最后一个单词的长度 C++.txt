### 解题思路
简单的从后遍历

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int tmpLen=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' ')
                tmpLen++;
            else if( tmpLen!=0 && s[i]==' ')
                return tmpLen;
        }
        return tmpLen;
    }
};
```