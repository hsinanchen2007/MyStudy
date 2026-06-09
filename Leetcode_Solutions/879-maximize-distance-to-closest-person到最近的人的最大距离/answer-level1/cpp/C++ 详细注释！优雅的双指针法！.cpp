### 解题思路
双指针法，详细过程见注释。

### 双指针法

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        /*
        思路：双指针法
            1. prev 指向位置 i 左边第一个有人的位置：i - prev 为距离
            2. next 指向位置 i 右边第一个有人的位置：next - i 为距离
            3. 与 i 的最近距离为：min(i - prev, next - i)
            4. 所有最近距离中求最大值：ans = math(ans, min(i - prev, next - i))
        */

        int prev = -1;
        int next = 0;

        int left_len = 0;
        int right_len = 0;
        int max_len = 0;

        int N = seats.size();

        for (int i = 0; i < N; i++) {
            // 0. 遍历数组寻找第一个空位置
            if (seats[i] == 1) {
                prev = i;
            } else {
                // 1. 找到空位置 seat[i] == 0，然后寻找空位置右边第一个有人的位置
                while (next < i || (next < N && seats[next] == 0))
                    next++;
                
                // 2. 计算位置 i 到左边第一个有人位置的距离
                // 当 i = 0，左边没人则认为距离无限大，设置为 N
                left_len = (prev == -1 ? N : i - prev);

                // 3. 计算位置 i 到右边第一个有人位置的距离
                // 当 i = N - 1，右边没人也认为距离无限大，设置为 N
                right_len = (next == N ? N : next - i);

                // 4. 先求每次左右距离的最小值，然后求所有距离的最大值
                max_len = max(max_len, min(left_len, right_len));
            }
        }

        return max_len;
    }
};
```