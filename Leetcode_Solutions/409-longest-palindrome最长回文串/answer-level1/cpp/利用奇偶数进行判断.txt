### 解题思路
此处撰写解题思路
使用map实现hash的功能
如果是偶数的话，全部加进去
如果是奇数的话，减一加进去
如果没有加完，说明有奇数的存在，可以将奇数放在中间位置
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if (0 == s.size()) return 0;
	    map<char, int>hashmap;
	    int ires = 0;
	    for (auto &val : s) hashmap[val]++;

	    for (auto &val : hashmap)
	    {
		    ires += ((0 == val.second % 2) ? val.second : val.second - 1);
	    }
	    if (ires < s.size()) ires++;

	    return ires;
    }
};
```