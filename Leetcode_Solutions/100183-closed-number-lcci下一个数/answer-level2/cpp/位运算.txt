### 解题思路

比 num 大的数：从右往左，找到第一个 01 位置，然后把 01 转为 10，右侧剩下的 1 移到右侧的低位，右侧剩下的位清0。
比 num 小的数：从右往左，找到第一个 10 位置，然后把 10 转为 01，右侧剩下的 1 移到右侧的高位，右侧剩下的位置0。

常规上，低位在右侧，bitset 注意方向相反

### 代码

```cpp
class Solution {
   public:
    vector<int> findClosedNumbers(int num) {
        bitset<32> small(num);
        bitset<32> bigger(num);

        int s = -1;
        // small, 10 转 01，1移到左侧
        for (int i = 1; i < 32; i++) {
            if (small[i] == 1 && small[i - 1] == 0) {
                small.flip(i);
                small.flip(i - 1);
                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && small[left] == 0) left++;
                    while (left < right && small[right] == 1) right--;
                    small.flip(left);
                    small.flip(right);
                }
                s = (int)small.to_ulong();
                break;
            }
        }

        // bigger, 01转10，1移到最右侧
        int b = -1;
        for (int i = 1; i < 32; i++) {
            if (bigger[i] == 0 && bigger[i - 1] == 1) {
                bigger.flip(i);
                bigger.flip(i - 1);

                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && bigger[left] == 1) left++;
                    while (left < right && bigger[right] == 0) right--;
                    bigger.flip(left);
                    bigger.flip(right);
                }
                b = (int)bigger.to_ulong();
                break;
            }
        }

        return {b, s};
    }
};
```