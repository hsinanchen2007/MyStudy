### 解题思路
我在官方题解下的评论 
[我猜这个题解的作者和相似题目的题解[27.移除元素 的题解](https://leetcode-cn.com/problems/remove-element/solution/yi-chu-yuan-su-by-leetcode/) 双指针的作者不是同一个人，否则学会了双指针的用法后，解法 3 是最自然的解法](https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode/242071/)



注意到官方的解法2也很精妙，也就是说如果从数组中抛弃一些值的话，只需要把需要保留的值往前覆盖就好，也许没必要用 swap

```c++
void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found. 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
    // After we have finished processing new elements,
    // all the non-zero elements are already at beginning of array.
    // We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
```


我的想法与官方题解3想法一致，但写法没有其精妙。

换句话说，代码将保持以下不变：

慢指针（lastnonzerofoundat）之前的所有元素都是非零的。
当前指针和慢速指针之间的所有元素都是零。

最初的写法是首先要找到第一个为0的值，然后后续的非0值，与此0值交换位置，然后依次向后推进。
通常而言快慢指针初始化为 i = j-1, 因此多了一个预处理步，需要保证 nums[i] 确实是 0

但是，这里首先取 i=j=0, 发现居然有奇效，可以免去预处理步。
j-i 表示当前找到的 0 元素的个数，
当 i=j 时，表示还没有找到一个为0的元素，并且
swap nums[i] 和 nums[j] 相当于没有操作。



### 代码-参考官方题解

```python3 
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i, j = 0, 0
        while j<n:
            if nums[j] != 0:
                if i < j:
                    nums[i], nums[j] = nums[j], nums[i]
                i += 1
            j += 1
```

### 原来自己写的代码
``` python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        j = 0
        while (j<n) and (nums[j] != 0):
            j += 1
        i = j
        j += 1
        while j<n:
            if nums[j] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
            j += 1
```



