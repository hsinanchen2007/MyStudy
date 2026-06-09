### 解题思路：
- 因为空间复杂度要求 $O(1)$，不能使用 `除法`，因此一定需要在 `乘法` 过程中得到所有答案；
- 我们可以将 `res` 数组列成乘积形式，不同的 $n$ 组成每行内容，形成一个矩阵，可以发现矩阵 `主对角线` 全部为 $1$ （当前数字不相乘，等价为乘 $1$）；
- 因此，我们分别计算矩阵的 `下三角` 和 `上三角`，并且在计算过程中储存过程值，最终可以在遍历 $2$ 遍 `nums` 下完成结果计算。

| **res**    |        |        |     |          |          |
| ---------- | ------ | ------ | --- | -------- | -------- |
| res[0] =   | **1**  | num[1] | ... | num[n-2] | num[n-1] |
| res[1] =   | num[0] | **1**  | ... | num[n-2] | num[n-1] |
| ...        | ...    | ...    | ... | num[n-2] | num[n-1] |
| res[n-2] = | num[0] | num[1] | ... | **1**    | num[n-1] |
| res[n-1] = | num[0] | num[1] | ... | num[n-2] | **1**    |
### 代码：

```Python []
class Solution:
    def productExceptSelf(self, nums: [int]) -> [int]:
        res, p, q = [1], 1, 1
        for i in range(len(nums) - 1): # bottom triangle
            p *= nums[i]
            res.append(p)
        for i in range(len(nums) - 1, 0, -1): # top triangle
            q *= nums[i]
            res[i - 1] *= q
        return res
```

```Java []
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        int p = 1, q = 1;
        for (int i = 0; i < nums.length; i++) {
            res[i] = p;
            p *= nums[i];
        }
        for (int i = nums.length - 1; i > 0 ; i--) {
            q *= nums[i];
            res[i - 1] *= q;
        }
        return res;
    }
}
```