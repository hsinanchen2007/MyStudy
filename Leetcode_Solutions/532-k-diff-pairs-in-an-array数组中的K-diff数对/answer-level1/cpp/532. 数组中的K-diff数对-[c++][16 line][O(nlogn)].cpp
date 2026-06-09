思路：只在右边界移动的时候进行统计。看下面两个例子（假设都已经排序好）

```cpp
k = 1;

注意下面的数组是 [1,1,1,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,3]，为了看的清楚，我把相册数字之间的逗号都删除了。

[1111111,2222,33333333]
 ^       ^    |       |  // step.1
 ^       |    ^       |  // step.2, found = 1, res += found = 1
         ^    ^       |  // step.3
         ^    ^       |  // step.1, r 保持不动 (第二轮)
         ^            ^  // step.2, found = 1, res += found = 2
         ^            ^  // step.3

再看 k = 0 的情况

[1111111,2222,33333333]
 ^^      |    |       |  // step.1
 ^       ^    |       |  // step.2, found = 1, res += found = 1
         ^    |       |  // step.3, l 和 r 重合了
         ^^   |       |  // step.1, r 右移一格 (第二轮)
         ^    ^       |  // step.2, found = 1, res += found = 2
              ^       |  // step.3, l 和 r 重合了
              ^^      |  // step.1, (第三轮)
              ^       ^  // step.2, found = 1, res += found = 3
              ^       ^  // step.3
```



```c++
int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int res = 0, l = 0, r = 0;
    while (r < nums.size()) {
        // Step.1 移动右边界，直到 nums[r] - nums[l] >= k 为止
        while (l == r || r < nums.size() && nums[r] - nums[l] < k) ++r;
        // Step.2 移动右边界，直到 nums[l] - nums[r] != k 为止
        int found = 0;
        while (r < nums.size() && nums[r] - nums[l] == k) {
            found = 1;
            ++r;
        }
        res += found;
        // Step.3 左边界向右收敛，直到窗口为空，或者 nums[r] - nums[l] <= k 为止
        while (r < nums.size() && l < r && nums[r] - nums[l] > k) ++l;
    }
    return res;
}
```
