### 解题思路
将num的二进制按照0进行分割，可得到多个连续1串，这样每个区间1的个数都可以知道，但是只有当两个1段之间有且仅有1个0时，其修改一个0后得到的连续1串才可相加，所以使用flag计算是否出现连续的0串，用于区分是否可以拼接。
![图片.png](https://pic.leetcode-cn.com/3e1e043d2aec2761dc777d71db81079227b1d235abd3a5824f13d7a63910fc39-%E5%9B%BE%E7%89%87.png)
### 代码

```cpp
class Solution {
public:
    int reverseBits(int num) {
        int res = 0; // 修改一位之后的最长连续1串长度
        int prev = 0; // 前一段连续1的长度
        int cnt = 0; // 当前段连续1的长度
        int flag = false; // 是否为连续0串标记

        while (num) {
            if (num & 1) { // 当前位为1， 直接计数
                cnt++;
                flag = false;
            }
            else { // 当前位为0
                res = max(prev + cnt + 1, res); // 计算修改后最长连续1 串长度
                if (flag) { // 存在连续0串
                    prev = 0; // 清空前一段连续1串长度
                    cnt = 0; // 清空当前段连续1串长度
                }
                else {
                    prev = cnt; // 保存前一段连续1串长度
                    cnt = 0; // 清空当前段连续1串长度
                }
            }
            num >>= 1;
        }
        res = max(prev + cnt + 1, res);
        return res;
    }
};
```