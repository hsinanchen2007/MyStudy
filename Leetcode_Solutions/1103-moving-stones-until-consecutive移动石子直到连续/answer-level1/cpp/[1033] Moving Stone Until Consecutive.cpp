## 題解

不失一般性，假設 $a < b < c$

### 最小情況

只可能為 $0$, $1$ 或 $2$

- 當三個數字已為連續時，不必移動，為 $0$
- 當三個數字中，有相鄰或間距為一者時，為 $1$
    - 存在相鄰：移動不相鄰的數字使其相鄰
    - 間距為一：第三個元素插空隙
- 其餘狀況則為 2
    - 以 $b$ 為中心，將 $a$ 移動至 $b - 1$，將 $c$ 移動至 $b + 1$ 

### 最大情況

每次移動只移動一步

- 對 $a$ 來說，移動 $b - a - 1$
- 對 $c$ 來說，移動 $c - b - 1$

將上述加總得 $\max = (b - a - 1) + (c - b - 1) = c - 1 - 2$

## 代碼

### C++

```cpp
class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    // 先將數字進行排序
    vector<int> nums = {a, b, c};
    sort(begin(nums), end(nums));

    // MIN: 有序為 0, 存在相鄰或縫隙為 1, 其他為 2
    // MAX: 每次只移動一步
    if (nums[2] - nums[0] == 2) return {0, 0};
    return {min(nums[1] - nums[0], nums[2] - nums[1]) <= 2 ? 1 : 2, nums[2] - nums[0] - 2};
  }
};
```