### 解题思路
二维通过率只有5%，自闭，就过来看有没有什么好的解法与启示。
分享一下根据pdd笔试衍生出的方法。4ms 15.5MB还行吧。
其实就是模拟倒水的过程，首先让水能充满整个区域，即初始化整个区域全部水量为INT_MAX。
考虑边界没有可以拦住的水量，因此将两个边界高度设置为直方图两边高度。
此时开始漏水，若水位比左边的高即可漏走达到与左边高度相同，若直方图本身就更高则取直方图高度。
同理再从右边漏水。
如此循环，只要一次循环中发生水位变化便再次循环，若无循环结束。
最后求水位图与直方图差即为水量。

### 代码

```cpp
class Solution {
    int dir[2] = { -1,1 };
    void getwater(vector<int>& height, vector<int>& water) {
        while (1) {
            int en = 0;
            for (int i = 1; i < height.size() - 1; i++) {
                int x = water[i];
                for (auto d : dir) {
                    x = min(x, water[i + d]);
                }
                if (x < water[i] && x >= height[i]) {
                    en = 1;
                    water[i] = x;
                }
                else if (x < height[i] && water[i] > height[i]) {
                    en = 1;
                    water[i] = height[i];
                }
            }
            for (int i = height.size() - 2; i >= 1; i--) {
                int x = water[i];
                for (auto d : dir) {
                    x = min(x, water[i + d]);
                }
                if (x < water[i] && x >= height[i]) {
                    en = 1;
                    water[i] = x;
                }
                else if (x < height[i] && water[i] > height[i]) {
                    en = 1;
                    water[i] = height[i];
                }
            }
            if (en == 0)break;
        }
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)return 0;
        vector<int> water(n, INT_MAX);
        water[0] = height[0];
        water[n - 1] = height[n - 1];
        getwater(height, water);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += water[i] - height[i];
        }
        return ans;
    }
};
```