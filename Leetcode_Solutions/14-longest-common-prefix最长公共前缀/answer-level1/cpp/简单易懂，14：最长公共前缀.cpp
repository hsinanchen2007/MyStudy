### 解题思路
比较公共前缀，不同则直接返回相同的。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j=0;
        char a; //用来存放每次比较的字符
        string result;

        if(strs.size()==0) return result;

        while(strs[0][j]!='\0') //因为不知道最短的字符是多长，所以我直接令第一个字符串为判断条件
        {
            a=strs[0][j];
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i][j]!=a) return result;
            }
            result=result+a;    //能运行到这里，证明a中的字符相同
            j++;
        }
        return result;
    }
};
```
