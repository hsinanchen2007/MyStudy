### 解题思路
利用字母在ascii码表中连续排列，用一个数组存储每个char的数量
1. 首先遍历string，统计每个char的数量存到vector中，注意这里char的数量存放的位置和其相对'a'和'A'的位置有关
2. 然后遍历一遍vector，如果char的数量是偶数就家上，如果是奇数就加上这个数量减一
3. 最后比较result和s的长度的关系，如果小于s的长度，那么一定只有可以有一个奇数的char存在，所以要加一

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> chars(52, 0);
        for (char & i : s) {
            if (i-'a' >= 0)
                chars[i-'a']++;
            else
                chars[i-'A'+26]++;
        }
        int res = 0;
        for (auto num : chars) {
            if (num <= 0)
                continue;
            if (num % 2 == 0) 
                res += num;
            else
                res += --num;
        }
        if (res < s.size())
            res++;
        return res;
    }
};
```