### 解题思路
从尾部开始遍历

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
    int nsize=s.size();
    int ans=0;
    bool isNULL=false;
    for (int i=nsize-1;i>=0;i--){
        if ((s[i]==' ') && (isNULL==true))
            break;
        else if (s[i]!=' ') {
            ans ++;
            isNULL=true;
        }
    }
    return ans;
    }
};
```