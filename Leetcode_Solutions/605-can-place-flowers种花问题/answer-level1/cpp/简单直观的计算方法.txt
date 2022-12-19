枚举处理两种情况
1.最左边或最右边有n个0，可以种 (n+1)/2 朵花
2.中间有n个0，可以种(n-1)/2朵花。

具体逻辑就是数0的个数，再判断是在边上还是在中间，可计算出可种的数量。

```c++ []
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int left = -1;
        int right = 0;

        while (right < size) {
            int count = right - left;

            if (flowerbed[right] == 1) {
                n -= (count - 1) / 2;
                left = right + 1;
            } else if (left == 0 || right == (size-1)) {
                n -= (count + 1) / 2;
            }

            right++;
        }

        return n <= 0;
    }
};
```

