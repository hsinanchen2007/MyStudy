### 解题思路
参考@owen的题解

### 代码

```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        if (stones.size() < 3) return {0, 0};
        sort(stones.begin(), stones.end());
        int N = stones.size();
        int head = stones[0];
        int tail = stones[N - 1];
        int S = tail - head + 1;
        if (S == N) {
            return {0, 0};
        }
        int L = stones[1] - head - 1;
        int R = tail - stones[N - 2] - 1;
        int max_step = S - N - min(L, R);
        if ((L > 1 && S - N == L) || (R > 1 && S - N == R)) {
            return {min(2, max_step), max_step};
        }
        int min_step = max_step;
        int l = 0;
        for (int i = 0; i < N; ++i) {
            while (stones[i] - stones[l] + 1 > N) {
                ++l;
            }
            min_step = min(min_step, N - (i - l + 1));
        }
        return {min_step, max_step};
    }
}; 
```

![image.png](https://pic.leetcode-cn.com/5a35c242c81445b9e445b9cb96a9d9cb4e5d320319f914438cc500a51bc88d72-image.png)
