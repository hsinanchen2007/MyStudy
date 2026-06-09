### 解题思路
跟着题目要求走就行，因为输入数据范围在int以内，因此反序后不会超过long long的范围。（如果未给定具体范围，可以使用string来完成反序）
需要注意的是 1 << 31 的值是 - 2147483648 ，而 (1 << 31) - 1 的值是 2147483647 ，这是由计算机内部对数据的存储决定的。

![image.png](https://pic.leetcode-cn.com/78978c71a0dd42c4064507a6fe1e9c65a93366321ccef34f85b66c7e9d4c7d97-image.png)


### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
        // flag 存储 x 的正负信息
        int flag;
        if(x < 0) flag = -1;
        else flag = 1;
        // 由于 x 的下限可以达到 - 2147483648 ，abs(x) 会超过int的范围，因此用 xx 暂存
        long long xx = x, y = 0;
        xx = abs(xx);
        // 倒序操作
        while(xx > 0)
        {
            y = y * 10 + xx % 10;
            xx = xx / 10;
        }
        // 判定是否越界
        if (flag  * y > (1 << 31) - 1 || y * flag < 1 << 31) return 0;
        // 判定未越界的 flag * y 必然在 int 的范围内，因此可以直接返回进行强制转换
        return flag * y;
    }
};
```