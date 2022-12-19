### 解题思路
纯粹的数学题，可以注意到，根据numrows，每一行的字符在原字符串中的位置符合规律
第一行：mod(2 * numrows - 2) = 0
第二行：mod(2 * numrows - 2) = 1 or (2 * numrows - 3)
......
代换一下，假设t = 2 * numrows - 2，则
第一行：mod t = 0
第二行：mod t = 1 or (t-1)
第三行：mod t = 2 or (t-2)
......
不难发现规律，这样做的时间复杂度为O(N)

**需要注意的是：**
1、mod t = t / 2 (t为偶数)（即两个余数相等）时的情况
2、mod t = 0 时的情况
3、numrows = 1 时的情况，此时t = 0，需要特殊处理

![oj.png](https://pic.leetcode-cn.com/094d17a9a6c96f18e0fbb5bf5741bab08389efc62420400e7e9cc00df436eef2-oj.png)


### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        // 处理numRows = 1时的情况
        if(numRows == 1) return s;
        string ans = "";
        int len = s.length();
        // mod记录除数
        int mod = numRows *2 - 2;
        for(int i = 0; i < numRows; i ++)
        {
            // tmp1和tmp2分别记录两种余数情况
            int tmp1 = i, tmp2 = mod - i;
            while(tmp1 < len)
            {
                ans += s[tmp1];
                // 处理特殊情况
                if(tmp1 != tmp2 && tmp1 % mod != 0 && tmp2 < len) ans += s[tmp2];
                tmp1 += mod;
                tmp2 += mod;
            }
        }
        return ans;
    }
};
```