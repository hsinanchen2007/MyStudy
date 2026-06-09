
![excel.png](https://pic.leetcode-cn.com/42b77d9da9eaae3bdeeaa0320d7a51c07c006132d9c74046692988c1faae70d0-excel.png)


### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        int len = s.length();
        int c;
        for(int i =0;i<len;++i)
        {
            c = s[i]-'A'+1;
            sum+=pow(26,len-i-1)*c;
        }
        return sum;
    }
};
```