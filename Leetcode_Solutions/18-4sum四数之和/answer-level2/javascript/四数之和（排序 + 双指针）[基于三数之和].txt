### 解题思路

四数之和是三数之和的升级版，写法几乎一样，只是多了一重循环。

#### 三数之和的思路
- 原数组先排序
- 固定其中的一个元素(通常是较小的元素)：一层循环
- 剩余的两个元素，按照双指针法来遍历：一层循环
- 每一个元素都需要做去重

时间复杂度：`O(NlogN + N^2)` 也就是 `O(N^2)` （N 为数组的长度）

#### 相应的四数之和的思路
- 原数组先排序
- 固定其中的一个元素(通常是较小的元素)：一层循环
- 固定另一个元素(通常是次小的元素)：一层循环
- 剩余的两个元素，按照双指针法来遍历：一层循环
- 每一个元素都需要做去重

时间复杂度：`O(NlogN + N^3)` 也就是 `O(N^3)` （N 为数组的长度）

由于循环嵌套较多，所以可以适当的剪枝。比如固定了最小元素或者最小的两个元素之后，可以计算当前的最小最大值与 target 的关系，从而可以减少不必要的计算。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    const res = [];
    if (!nums || nums.length < 4) return res;

    // 排序
    nums.sort((a, b) => a - b);

    // 使用 i,j, m, n 四个指针来分别指代四个数，且 0<= i < j < m < n < nums.length
    // i 为最小元素的指针，从 0 开始遍历
    // j 为次小元素的指针，从 i + 1 开始遍历
    // i, j 固定之后，使用 m, n 作为双指针
    // m 为左指针，从 j + 1 开始往后遍历
    // n 为右指针，从 nums.length - 1 开始往前遍历
    let L = nums.length;

    for (let i = 0; i < L - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue; // i 去重：当前元素等于前一个元素，则跳过
        
        // 固定了 i 后，当前四个元素的最小以及最大和，用于剪枝
        let curMin = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
        if (curMin > target) continue;
        let curMax = nums[i] + nums[L - 1] + nums[L - 2] + nums[L - 3];
        if (curMax < target) continue;

        for (let j = i + 1; j < L - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue; // j 去重：当前元素等于前一个元素，则跳过

            // 固定了 i, j 后，当前四个元素的最小以及最大和，用于剪枝
            curMin = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
            if (curMin > target) continue;
            curMax = nums[i] + nums[j] + nums[L - 2] + nums[L - 1];
            if (curMax < target) continue;

            // 使用双指针来计算
            let sum = Number.MAX_SAFE_INTEGER;
            let m = j + 1; // 左指针
            let n = L - 1; // 右指针
            while (m < n) {
                sum = nums[i] + nums[j] + nums[m] + nums[n];
                if (sum < target) m++;
                else if (sum > target) n--;
                else {
                    // m, n 去重：当前元素等于前一个元素，则跳过
                    while (m < n && nums[m] === nums[m + 1]) m++;
                    while (m < n && nums[n] === nums[n - 1]) n--;
                    res.push([nums[i], nums[j], nums[m], nums[n]]); // 找到一组去重后的解
                    m++;
                    n--;
                }
            }
        }
    }

    return res;
};
```

**时间复杂度**：`O(N^3)` （N 为数组的长度）
**空间复杂度**：`O(1)` 

*附 AC 结果*
![four-sum-tijie.png](https://pic.leetcode-cn.com/7d7f8c6c691266c30bcc6504723236b339328d130ec51f3d2ada03ca11a38011-four-sum-tijie.png)
