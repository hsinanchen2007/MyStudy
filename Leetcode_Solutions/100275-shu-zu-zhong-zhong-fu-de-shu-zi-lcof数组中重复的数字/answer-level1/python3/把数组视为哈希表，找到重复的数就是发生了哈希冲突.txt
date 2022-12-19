
本题方法很多，每个方法都有优点和缺点，题目也没有限制是否可以使用额外空间，是否可以修改原始数组。如果在面试的时候，需要询问面试官是否有这些限制，并给出对应的解决方案。

在实际的工作中，我们遇到的问题很多时候也不会直接告诉我们有哪些限制，需要我们根据实际情况，具体分析应该使用哪种方法。所以有些面试官可能出的一些题目就是没有说的很清楚，他希望你向他提问，就是为了考察你是不是有考虑得很全面（面试就酱紫，是和活生生的人对话，不是做题 Accept 就完事，大家要稳，习惯就好，有的时候不能 Accept ，但是面试官看到了你其他方面的素质，其实也会给通过的）。

所以这道题是一个“很有话说”的问题，面试的时候遇到的话，可以和面试官展开讨论（扯的有点远了，大家体会意思就好。）

---

### 方法一：哈希表（最自然，但是要额外空间）

最容易想到用哈希表判重，这种方法是最自然的。

特别地，在数组的长度不超过 $32$ 的时候，使用位运算的技巧可以实现 $O(1)$ 空间复杂度判重，但是这道题不是回溯算法的问题，题目给出的测试用例的长度肯定不止 32 位，因此，不建议使用位运算的技巧。

分析：这种方法不修改原始数组，但是使用了 $O(N)$ 空间，使用空间换时间，是最正常的思路，时间复杂度是 $O(N)$。

### 方法二：排序（也比较容易想到，但是要排序，复杂度高）

排序以后，再遍历一遍就知道哪个重复了。

分析：这个方法其实比较容易想到，但是时间复杂度是 $O(N \log N)$，同时也修改了原始数组。

### 方法三：把数组视为哈希表（有一类问题是这么做的，但是会修改数组）

+ 由于数组元素的值都在指定的范围内，这个范围恰恰好与数组的下标可以一一对应；
+ 因此看到数值，就可以知道它应该放在什么位置，这里**数字`nums[i]` 应该放在下标为 `i` 的位置上**，这就像是我们人为编写了哈希函数，这个哈希函数的规则还特别简单；
+ 而**找到重复的数就是发生了哈希冲突**；
+ 类似问题还有「力扣」第 41 题： [缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)、「力扣」第 442 题：  [数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)、「力扣」第 448 题： [找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/) 。

分析：这个思路利用到了数组的元素值的范围恰好和数组的长度是一样的，因此数组本身可以当做哈希表来用。遍历一遍就可以找到重复值，但是修改了原始数组。


**参考代码 1**：

这里感谢 [@zi-lai-huo](/u/zi-lai-huo/) 在评论区提供的 Python 代码。

**原来的写法没有考虑得很仔细，可能误导了一些朋友，在这里表示歉意**，已经在 Java 版本的代码中做了注释，现在已经做了修改。

```Java []
import java.util.Arrays;

public class Solution {

    public int findRepeatNumber(int[] nums) {
        int len = nums.length;

        for (int i = 0; i < len; i++) {
            // 如果当前的数 nums[i] 没有在下标为 i 的位置上，就把它交换到下标 i 上
            // 交换过来的数还得做相同的操作，因此这里使用 while
            // 可以在此处将数组输出打印，观察程序运行流程
            // System.out.println(Arrays.toString(nums));

            while (nums[i] != i) {

                if (nums[i] == nums[nums[i]]) {
                    // 如果下标为 nums[i] 的数值 nums[nums[i]] 它们二者相等
                    // 正好找到了重复的元素，将它返回
                    return nums[i];
                }
                swap(nums, i, nums[i]);
            }
        }
        throw new IllegalArgumentException("数组中不存在重复数字！");
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

}
```
```Python []
class Solution:

    def findRepeatNumber(self, nums: List[int]) -> int:
        for index, value in enumerate(nums):

            while index != value:
                if nums[value] == value:
                    return value

                nums[value], nums[index] = nums[index], nums[value]
        return -1
```

说明：题目中给出了数组的长度范围，因此不需要对数组的长度做非空判断。

**复杂度分析**：

+ 时间复杂度：$O(N)$，这里 $N$ 是数组的长度。虽然 `for` 循环里面套了 `while`，但是每一个数来到它应该在的位置以后，位置就不会再变化。这里用到的是**均摊复杂度分析**的方法：如果在某一个位置 `while` 循环体执行的次数较多，那么一定在后面的几个位置，根本不会执行 `while` 循环体内的代码，也就是说最坏的情况不会一直出现。也就是说最坏复杂度的情况不会一直出现。
+ 空间复杂度：$O(1)$。

### 方法四：二分法（为了不修改数组，要遍历数组很多遍）

由于要确定的数字是**有范围的整数**，因此可以使用二分法来确定这个数，这就是「力扣」第 278 题：[“寻找重复数”](https://leetcode-cn.com/problems/find-the-duplicate-number/)，题目有一点点不一样，但思想是一样。

分析：这种做法，不修改原始数组，不使用额外空间（即不像使用哈希表的方法那样，使用 $O(N)$ 空间），但是看了数组很多遍，是很反常的“使用时间换空间”的做法。

「力扣」第 278 题：“寻找重复数”，还有一种做法是快慢指针，就更难想到了，这里只是做提示，大家可以在这道题的题解区和评论去看到这种解法，这里就不展开了。