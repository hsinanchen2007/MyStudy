### 解题思路
开始help（）里面没有加上return 0；老是报错说这个函数有可能不会返回值，我就纳闷了，不是只会有七种数字吗，还好灵机一动加上最后一句就好了。hiahia

### 代码

```cpp
class Solution {
public:
    int help(char c){
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int n=size(s);
        int sum=0;
        for(int i=0;i<n;i++){
            if(help(s[i])<help(s[i+1])) sum=sum-help(s[i]);
            else sum=sum+help(s[i]);
        }
        return sum;
    }
};
```