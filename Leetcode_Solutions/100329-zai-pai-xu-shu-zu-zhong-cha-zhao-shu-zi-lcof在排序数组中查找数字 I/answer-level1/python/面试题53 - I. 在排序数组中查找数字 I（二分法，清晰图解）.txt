#### 解题思路：

> 排序数组中的搜索问题，首先想到 **二分法** 解决。

- 排序数组 $nums$ 中的所有数字 $target$ 形成一个窗口，记窗口的 **左 / 右边界** 索引分别为 $left$ 和 $right$ ，分别对应窗口左边 / 右边的首个元素。
- 本题要求统计数字 $target$ 的出现次数，可转化为：使用二分法分别找到 **左边界 $left$** 和 **右边界 $right$** ，易得数字 $target$ 的数量为 $right - left - 1$ 。

![Picture1.png](https://pic.leetcode-cn.com/b4521d9ba346cad9e382017d1abd1db2304b4521d4f2d839c32d0ecff17a9c0d-Picture1.png){:width=500}

##### 算法解析：

1. **初始化：** 左边界 $i = 0$ ，右边界 $j = len(nums) - 1$ ；代表闭区间 $[i, j]$ 。
2. **循环二分：** 当 $i \leq j$ 时循环 *（即当闭区间 $[i, j]$ 为空时跳出）* ；
   1. 计算中点 $m = (i + j) // 2$ ，其中 "$//$" 为向下取整除法；
   2. 若 $nums[m] < target$ ，则数字 $target$ 一定在闭区间 $[m + 1, j]$ 中，因此执行 $i = m + 1$；
   3. 若 $nums[m] > target$ ，则数字 $target$ 一定在闭区间 $[i, m - 1]$ 中，因此执行 $j = m - 1$；
   4. 若 $nums[m] = target$ ，则右边界 $right$ 在闭区间 $[m+1, j]$ 中；左边界 $left$ 在闭区间 $[i, m-1]$ 中。因此分为以下两种情况：
      1. 若查找 **右边界 $right$** ，则执行 $i = m + 1$ ；（跳出时 $i$ 指向右边界）
      2. 若查找 **左边界 $left$** ，则执行 $j = m - 1$ ；（跳出时 $j$ 指向左边界）
3. **返回值：** 应用两次二分，分别查找 $right$ 和 $left$ ，最终返回 $right - left - 1$ 即可。

<![Picture2.png](https://pic.leetcode-cn.com/62e233e1013cd8c2e1226b892ed2005be99e16905ec3d8fbecfec01eb07ddc31-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/1757f72b12f980ae4701f42a6eee0e17af34e8264377acb50bd708b135eeb40b-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/7588bcf5b4d70eaec44d5869f4db77693eb0db714d96de77dda62cd332e9f979-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/f990452d907f35ac68495375089f8b3410c841386bd0130c6f480e8ef23d55fd-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/8030e471a6d20106eff4f9dcadd321145f2ecfc32c5c9a7582ce09dfdfa00f24-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/859d40c4877979e85743b03ec59b091096826138f1dd5aa57e20816597049c81-Picture7.png)>

##### 复杂度分析：

- **时间复杂度 $O(log N)$ ：** 二分法为对数级别复杂度。
- **空间复杂度 $O(1)$ ：** 几个变量使用常数大小的额外空间。

#### 代码：

> 为使代码更加简洁，可将 $nums[m] = target$ 情况合并至其他两种情况中。

```python []
class Solution:
    def search(self, nums: [int], target: int) -> int:
        i, j = 0, len(nums) - 1
        while i <= j:
            m = (i + j) // 2
            if nums[m] <= target: i = m + 1
            else: j = m - 1
        right = i

        i, j = 0, len(nums) - 1
        while i <= j:
            m = (i + j) // 2
            if nums[m] < target: i = m + 1
            else: j = m - 1
        left = j
        
        return right - left - 1
```

```java []
class Solution {
    public int search(int[] nums, int target) {
        int i = 0, j = nums.length - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] <= target) i = m + 1;
            else j = m - 1;
        }
        int right = i;

        i = 0; j = nums.length - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] < target) i = m + 1;
            else j = m - 1;
        }
        int left = j;
        
        return right - left - 1;
    }
}
```