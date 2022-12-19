### 题目描述

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须**原地**修改，只允许使用额外**常数空间**。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
```txt
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
```

### 思路

首先想一个问题，什么情况下求下一个排列最简单？根据题意，自然是字典序最大也就是降序排列的时候，因为这种情况的下一个排列就是字典序最小的，将原序列逆序就行了。

那么我们就围绕这个点来思考。

对于任意一个序列，我们从后往前找，先找到一个**最长递减子序列**，比如`2 1 7 5 4 3`，那么**最长递减子序列**就是`7 5 4 3`，把它逆序，变成`3 4 5 7`，这是**最小序列**，这时整个序列变成了`2 1 3 4 5 7`。这样还不够，我们还要满足比原序列的字典序大，其实也好处理，**最长递减子序列**的前一个元素是`1`，我们只需要在**最小的序列**`3 4 5 7`中找一个比它大并且最接近它的元素，将它换掉就可以了，显然这个替换的元素是`3`（替换并没有破坏**最小序列的单调性**），这样整个序列就变成了`2 3 1 4 5 7`，这也就是我们的目标序列。


### 代码
```java
class Solution {
    public void nextPermutation(int[] nums) {
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i == 0) {
                reverse(nums, 0, nums.length - 1);
                return;
            }
            if (nums[i] > nums[i - 1]) {
                // 将递增序列逆序
                reverse(nums, i, nums.length - 1);
                for (int j = i; j < nums.length; j++) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums, j, i - 1);
                        return;
                    }
                }
            }
        }
    }

    // 数组反转 
    private void reverse(int[] nums, int begin, int end) {
        while (begin < end) {
            swap(nums, begin++, end--);
        }
    }

    // 交换
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

