欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 3)，其中n为nums数组的长度。
空间复杂度是O(1)。

执行用时：188ms，击败5.23%。消耗内存：36.9MB，击败83.68%。

```java
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length, diff = Integer.MAX_VALUE, result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (Math.abs(nums[i] + nums[j] + nums[k] - target) < diff) {
                        diff = Math.abs(nums[i] + nums[j] + nums[k] - target);
                        result = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return result;
    }
}
```

# 解法二：双指针

内层循环采用双指针遍历的形式。

时间复杂度是O(n ^ 2)，其中n为nums数组的长度。
空间复杂度是O(1)。

执行用时：17ms，击败48.29%。消耗内存：36.5MB，击败84.07%。

```java
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length, diff = Integer.MAX_VALUE, result = 0;
        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    if (Math.abs(nums[i] + nums[left] + nums[right] - target) < diff) {
                        diff = Math.abs(nums[i] + nums[left] + nums[right] - target);
                        result = nums[i] + nums[left] + nums[right];
                    }
                    left++;
                } else if (nums[i] + nums[left] + nums[right] == target) {
                    return target;
                } else {
                    if (Math.abs(nums[i] + nums[left] + nums[right] - target) < diff) {
                        diff = Math.abs(nums[i] + nums[left] + nums[right] - target);
                        result = nums[i] + nums[left] + nums[right];
                    }
                    right--;
                }
            }
        }
        return result;
    }
}
```