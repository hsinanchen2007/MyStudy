### 解题思路
![QQ截图20200326182112.png](https://pic.leetcode-cn.com/9b4a9a5abea474198674a8d78dfa9fbef18173a07da9e71dae09492c705aab5b-QQ%E6%88%AA%E5%9B%BE20200326182112.png)


### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        // 2,5成对出现, 构成一个0
        // 统计有多少个5，不考虑2，因为n!中2的个数显然大于5的个数
        return helper(n);
    }
    
    int helper(int n) { // n!中有多少个5
        if (n < 5) return 0;
        return helper(n / 5) + n / 5; 
        // 5*x <= n; 于是5*1*a1*5*2*a1*...*5*x <= n, 即5*5*..*5*a1*...*an*1*2*...*x <= n
        // 于是n!中5的个数 = (x + x!中5出现的个数)
    }
};
```