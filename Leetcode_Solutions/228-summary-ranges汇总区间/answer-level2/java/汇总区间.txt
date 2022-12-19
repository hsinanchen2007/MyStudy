**思路**

对于包含连续元素的一段区间。如果相邻的元素之间的差值大于 $1$，那么这两个元素肯定不属于一段区间。

**算法**

为了得出这些区间，我们需要找到一种方法将它们分开。题目所给出的数组是有序的，同时还没有重复元素。在这样的数组里面，两个相邻的元素的差值要么等于 1 要么大于 1。对于那些差值等于 1 的就将它们被放在同一段区间内；否则，就将把它们放在不同的区间。

我们还需要知道的是一段区间的起始坐标，这样就可以把它们放进结果里面了。因此，我们需要保存两个坐标，分别代表一段区间的两个分界点。对于遍历到的每个新元素来说，检查一下它是否可以拓展当前的区间，如果不能，就把当前的元素作为一个新的区间的开始。

不要忘记把最后一段区间也放进结果里面。这个逻辑很容易实现，你可以在循环里通过一个特定的判断条件来加入或者在循环结束后加入。

```Java [solution-1]
public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> summary = new ArrayList<>();
        for (int i = 0, j = 0; j < nums.length; ++j) {
            // check if j + 1 extends the range [nums[i], nums[j]]
            if (j + 1 < nums.length && nums[j + 1] == nums[j] + 1)
                continue;
            // put the range [nums[i], nums[j]] into the list
            if (i == j)
                summary.add(nums[i] + "");
            else
                summary.add(nums[i] + "->" + nums[j]);
            i = j + 1;
        }
        return summary;
    }
}
```

**Java (可选)**

```Java [solution-1]
public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> summary = new ArrayList<>();
        for (int i, j = 0; j < nums.length; ++j){
            i = j;
            // try to extend the range [nums[i], nums[j]]
            while (j + 1 < nums.length && nums[j + 1] == nums[j] + 1)
                ++j;
            // put the range into the list
            if (i == j)
                summary.add(nums[i] + "");
            else
                summary.add(nums[i] + "->" + nums[j]);
        }
        return summary;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$
每个元素都需要被访问常量次数，要么在相邻元素中被比较，要么就是被放入结果的时候被访问。

* 空间复杂度：$O(1)$
如果不考虑输出的话，我们唯一需要额外开辟空间的就是一段区间的两个坐标。