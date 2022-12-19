### 解题思路
1.使用count_Binary_0x1函数来计算传入数字二进制1的个数。
2.遍历所有二进制可能的时间情况，只将计数相同数字显示压入res容器中。

### 代码

```cpp
class Solution {
public:
    int count_Binary_0x1(int n) {
        int res = 0;
        while (n != 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count_Binary_0x1(i) + count_Binary_0x1(j) == num) {
                    res.push_back(to_string(i)+ ":" + (j < 10 ? "0"+to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }
};
```