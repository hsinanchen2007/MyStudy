### 解题思路
![image.png](https://pic.leetcode-cn.com/d677a84b706be858805c0990af41480150c8dfb187eff4a38284adf90c9bdc63-image.png)

### 代码

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int>mymap;
        for(char c:s)mymap[c]++;
        int c=0;
        for(auto x:mymap)if(x.second%2==1)c++;
        return c<=1;
    }
};
```