>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 深度优先搜索

遍历 nums 数组中的每一个元素，可以将其加入 list 中，也可以选择将其不加入 list 中。

本问题的关键在于，如何去重？

1.满足什么样的条件我们可以将当前元素加入 list 中呢？

显然是当前元素大于等于 list 中的最后一个元素。

2.满足什么样的条件我们可以不将当前元素加入 list 中呢？

这个问题的回答是去重的关键。如果 list 不为空，且当前元素和 list 中的最后一个元素相等，我们不考虑不将当前元素加入 list 中这一分支。

为什么呢？

因为当前元素和 list 中的最后一个元素相等，如果考虑这一分支，又会得到一个重复的 list。

以`[4, 6, 7, 7]`为例来说明这一情况，假设现在我们的 list 是`[4, 6]`。

```
                                                     将索引为3处的7加进 list 中[4, 6, 7, 7]
                    将索引为2处的7加进 list 中[4, 6, 7]
                                                     不将索引为3处的7加进 list 中[4, 6, 7] （这种情况不需要考虑）    
当前 list 值为[4, 6]  
                                                     将索引为3处的7加进 list 中[4, 6, 7]
                    不将索引为2处的7加进 list 中[4, 6]
                                                     不将索引为3处的7加进 list 中[4, 6]
```

时间复杂度是 O(2 ^ n)，其中 n 为 nums 数组的长度。空间复杂度是 O(n)。

执行用时：5ms，击败98.29%。消耗内存：47.4MB，击败100.00%。

```java
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> findSubsequences(int[] nums) {
        dfs(nums, new ArrayList<>(), 0);
        return new ArrayList<>(result);
    }

    private void dfs(int[] nums, List<Integer> list, int index) {
        if (index >= nums.length) {
            if (list.size() >= 2) {
                result.add(new ArrayList<>(list));
            }
            return;
        }
        // 把第 index 个元素加进 list 中
        if (list.isEmpty() || nums[index] >= list.get(list.size() - 1)) {
            list.add(nums[index]);
            dfs(nums, list, index + 1);
            list.remove(list.size() - 1);
        }
        if (index > 0 && !list.isEmpty() && nums[index] == list.get(list.size() - 1)) {
            return;
        }
        // 不把第 index 个元素加进 list 中
        dfs(nums, list, index + 1);
    }
}
```