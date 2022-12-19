### 思路
- 主要就是将区间的范围全部置为1
- 找到区间的左右端点处于的索引位置，单独处理两个端点
    - 左端点是将一个32位数的从低位到高位置1，右边正好方向相反，可以通过按位与`-1`清除指定位数末尾`0`来得到
    - 特别注意如果两个端点是重合的，我们需要将常规求出的左端点的数与右端点的数按位与
- 区间内的数直接全部置为`-1`即可

### 代码
```cpp
class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> ans(length, 0);
        int x = w / 32 * y;
        int w1 = x1 / 32, w2 = x2 / 32;
        int leftOfOne = 32 - x1 % 32, rightOfOne = x2 % 32 + 1;
        int n1 = 0, n2 = 0;
        while(leftOfOne--)
        {
            n1 <<= 1;
            n1 = n1 ^ 1;
        }
        rightOfOne = 32 - rightOfOne;
        while(rightOfOne--)
        {
            n2 <<= 1;
            n2 = n2 ^ 1;
        }
        n2 = -1 ^ n2;
        ans[x + w1] = n1;
        ans[x + w2] = w1 != w2 ? n2 : n1 & n2;
        for(int i=x+w1+1;i<x+w2;i++)
        {
            ans[i] = -1;
        }
        return ans;
    }
};
```
