##### 首先，假设有两个单词 "abcd"和"abcde"，那么在一本涵盖了所有字母排列的字典中，
##### 这两个单词之间的单词也一定有前缀"abcd"（可以看做26进制的数）
##### 于是，我们就只需要比较最小字典序的字符串和最大字典序的字符串
##### 那么sort一遍数组，然后取strs[0]与strs[n-1],比较求解即可
##### c++代码如下：
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];
        sort(strs.begin(),strs.end());
        for(int i = 0;i < min(strs[0].length(),strs[n-1].length());i++){
            if(strs[0][i] != strs[n-1][i]) return strs[0].substr(0,i);
        }
        return strs[0].length() > strs[n-1].length()?strs[n-1]:strs[0];
    }
};
```
![image.png](https://pic.leetcode-cn.com/8d235d7280012937461947d248a4ebf6e13c3b8f0e18209ab842928f6887a8eb-image.png)


