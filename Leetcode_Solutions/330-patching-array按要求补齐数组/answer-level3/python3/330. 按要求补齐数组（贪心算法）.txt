- **补齐数组特点：**
    - 假设数组 $arr$ 添加一个元素即可覆盖 $[1, n)$ 内所有数字，那么添加的数字 $m$ 一定满足`m <= n`。
    - 假设数组 $arr$ 可以覆盖 $[1, n)$ 的所有数字，则给 $arr$ 内加元素 $m$ ：
        - 若`m <= n`，新数组可以覆盖`[1, m + n) = [1, n) ∪ [m, m + n)`内所有数字；
- **贪心法则：** 对于一个覆盖 $[1, n)$ 的数组 $arr$ 来说，添加数字 $n$ 连续扩容范围最大（扩容至 $[1, 2n)$ ）。
- **思路：** 设置一个初始范围 $[1, 1)$ ，通过不断确认并扩大数组可以覆盖的范围，最终计算出最少需要加入的数字。
    - 当`i < len(nums)`且`nums[i] <= add`时：不需要加入新数字，循环确认并更新数组可以覆盖的范围`[1, add + nums[i])`，直到找到大于确认范围 $add$ 的 $nums[i]$ 或索引越界。
    - 否则：无法根据现有数字构建更大的连续范围，，因此需要使用贪心策略向数组加入数字 $add$ ，将数组从覆盖 $[1, add)$ 扩容至可覆盖 $[1, 2add)$ 。
    - 直到确认的范围`add > n`，说明此时已经覆盖 $[1, n]$ ，退出迭代并返回。

```python []
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        add, i, count = 1, 0, 0
        while add <= n:
            if i < len(nums) and nums[i] <= add:
                add += nums[i] # from [1, add] to [1, add + nums[i]]
                i += 1
            else:
                add += add # from [1, add] to [1, 2add]
                count += 1
        return count
```

```java []
class Solution {
    public int minPatches(int[] nums, int n) {
        int i = 0, count = 0;
        long add = 1;
        while(add <= n){
            if(i < nums.length && nums[i] <= add) add += nums[i++];
            else {
                add += add;
                count ++;
            }
        }
        return count;
    }
}
```