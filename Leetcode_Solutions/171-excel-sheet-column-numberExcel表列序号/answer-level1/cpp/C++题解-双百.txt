自己第一个双百，但是好菜，想了特别久。
相当于26进制
```
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int res=0;
        for(int i=0;i<len;i++){
            res +=(s[i]-'A'+1)*pow(26,len-1-i);
        }
        return res;
    }
};
```
![2.png](https://pic.leetcode-cn.com/984d6326b47212af164913b48b656cae518f833364350e8c56e8407e91b06e86-2.png)
