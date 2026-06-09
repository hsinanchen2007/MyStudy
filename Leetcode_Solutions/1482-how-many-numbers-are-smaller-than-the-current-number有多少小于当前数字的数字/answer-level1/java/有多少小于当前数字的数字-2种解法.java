>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：排序后使用floor()函数二分查找

时间复杂度是O(nlogn)，其中n为nums数组的长度。空间复杂度是O(n)。

执行用时：4ms，击败100.00%。消耗内存：41.9MB，击败100.00%。

```java
public class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] result = new int[n], copyNums = new int[n];
        for (int i = 0; i < n; i++) {
            copyNums[i] = nums[i];
        }
        Arrays.sort(copyNums);
        for (int i = 0; i < n; i++) {
            result[i] = floor(copyNums, nums[i]) + 1;
        }
        return result;
    }

    private int floor(int[] nums, int target) {
        int left = -1, right = nums.length - 1;
        while (left < right) {
            int mid = left + ((right - left + 1) >> 1);
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }
}
```

# 解法二：哈希表

时间复杂度和空间复杂度均是O(n)，其中n为字符串expression的长度。

执行用时：1ms，击败100.00%。消耗内存：41.4MB，击败100.00%。

```java
public class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        //count[i]表示数字i在nums数组中出现的次数，lessCount[i] = count[0] + count[1] + ... + count[i - 1]
        int[] count = new int[101], lessCount = new int[101], result = new int[n];
        for (int num : nums) {
            count[num]++;
        }
        for (int i = 1; i < 101; i++) {
            lessCount[i] = lessCount[i - 1] + count[i - 1];
        }
        for (int i = 0; i < n; i++) {
            result[i] = lessCount[nums[i]];
        }
        return result;
    }
}
```