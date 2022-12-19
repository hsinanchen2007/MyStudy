### 解题思路

先去判断是否为空，空为0；
判断字符串最后一个s[len-1]，若不为空格，将num加一；
其后判断容易了；
遇到空格+非空格组合，则num加一；
最后返回

### 代码

```cpp
class Solution {
public:
    int countSegments(string s){
        int len=s.size();
        int num=0;
        if(len==0)
            return 0;
        if(s[len-1]!=' ')
            num+=1;
        for(int i=len-1;i>=1;i--){
            if (s[i]==' '&&s[i-1]!=' ')
                num++;          
        }
        if(num==0)
            return 0;
        else
            return num;
    }
};
```