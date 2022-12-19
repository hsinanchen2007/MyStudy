### 解法

```java
public List<Integer> minSubsequence(int[] nums) {
        List<Integer> res = new ArrayList<>();
        Arrays.sort(nums);
        int left = 0, sum = 0;
        for(int i : nums)
            left += i;
        for(int i = nums.length - 1; i >= 0; i--){
            sum += nums[i];
            left -= nums[i];
            res.add(nums[i]);
            if(sum > left)
                break;
        }
        return res;
    }
```

思路分析：

* 首先题目对答案的额外要求：长度最短，且元素和最大，另外子数组并不需要连续。从示例来看并不要求保持原数组的相对顺序。那就可以按从大到小的顺序挑选元素了，毕竟元素从大的选取，那么满足该子序列的元素之和 严格 大于未包含在该子序列中的各元素之和时，选的元素个数肯定最少且子序列和最大。
* 所以先将数组进行排序。
* 需要知道子序列的和，以及除去子序列后剩余元素的和。我们可以先遍历一遍原数组，求出数组所有元素之和`left`。
* 然后从数组最后一个元素开始第二次遍历，用`sum`记录子序列的和。对于每一个元素`nums[i]`
    * 更新子序列的和`sum += nums[i]`
    * 更新除去子序列后剩余元素的和`left -= nums[i]`
    * 将元素添加到子序列中`res.add(nums[i])`
    * 判断该子序列的元素之和是否严格大于未包含在该子序列中的各元素之和，如果是中止循环。
* 最后返回结果List即可。
* 时间复杂度为$O(nlog(b))$。空间复杂度为$O(k)$，k为满足条件的子序列的最短长度。

运行结果：

* 5ms

更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖