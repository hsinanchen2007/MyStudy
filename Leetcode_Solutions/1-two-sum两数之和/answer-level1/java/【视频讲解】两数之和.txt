![...etCode 1. TwoSum.mp4](2c32f094-dfca-4284-a77d-786f81408413)

**Java 视频讲解系列 - 两数之和**
{:align=center}

```java [-Java]
package Algorithms;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 Example:

 Given nums = [2, 7, 11, 15], target = 9,

 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 */
public class TwoSum {
    /**
     * sorted time: O(n)  space: O(1)
     * @param nums
     * @param target
     * @return
     */
    public int[] twoSum(int[] nums, int target) {
        if (nums == null || nums.length <= 1) return new int[2];
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return new int[] {left, right};
            }
        }
        return new int[2];
    }

    public int[] twoSum1(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int desired = target - nums[i];
            if (map.containsKey(desired)) {
                return new int[] {map.get(desired), i};
            } else {
                map.put(nums[i], i);
            }
        }
        return new int[2];
    }
}

```

我的 [Youtube频道](https://www.youtube.com/channel/UC6sXxjf9HMntbtDu5SsWLAg)