![image.png](https://pic.leetcode-cn.com/87c675654ca0e5e3385365dbd3f12dc3715bdeb59d7a0873186ccc02581096a9-image.png)


### 题目描述

给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
**注意:**
假设字符串的长度不会超过 1010。

#### 样例

```
输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
```

----------

### 算法
##### (哈希表、奇偶性)  $O(n)$

1. 用哈希表统计每个字符出现的次数
2. 判断奇偶性：
    1. 若字符出现次数为偶数，则肯定能够组成回文串，计入累加器
    2. 若为奇数，添加个数-1并计入累加器，并且标记存在中心字符

### 代码
```
class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> hash;
        for (auto x : s) hash[x] ++;
        int res = 0, center = 0;

        for (auto item : hash){
            if (item.second % 2 == 0) 
                res += item.second;
            else{
                res += item.second - 1；
                center = 1;
            }
        }
        return res + center;
	}
};
```

时间复杂度分析：最多需要遍历输字符串中n个字符，所以时间复杂度为$O(n)$
空间复杂度分析：根据unordered_map的空间复杂度为$O(n)$