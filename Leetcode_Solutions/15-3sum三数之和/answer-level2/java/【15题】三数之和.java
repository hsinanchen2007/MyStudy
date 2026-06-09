
**方法一：暴力**
思路：
已知题意是取数组三个元素使得三数之和为 0 并要求不包含重复的三元组。
所以最简单的思路就是暴力三层循环取和为 0 的三元组，然后去重。
*** 这里会LeetCode超时，可以通过双指针或者哈希表去优化一层。
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        // 使得数组有序，方便配合 list 去重。
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                for (int k = j + 1; k < len; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> list = new ArrayList<>(3);
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[k]);
                        if (ans.indexOf(list) < 0) {
                            ans.add(list);
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```

**方法二：双指针**
思路：
每次固定一个数，然后通过双指针遍历取另外两个数，使得三数之和为 0 。
*** 需要注意的就是每个去重的点，要使得符合要求的三元组中每个数值只使用一次。
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList();
        int len = nums.length;
        // 使得数组有序，方便取三元组时候去重。
        Arrays.sort(nums);
        for (int i = 0; i < len - 2; i++) {
            // 如果最小数字大于 0 ，则三数之和一定大于 0 。
            if (nums[i] > 0) {
                break;
            }
            // 和为 0 的三个数，相同的值只遍历一次。
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int L = i + 1, R = len - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ans.add(Arrays.asList(nums[i], nums[L], nums[R]));
                    // 和为 0 的三个数，相同的值只遍历一次。
                    while (L < R && nums[L] == nums[L + 1]) {
                        L++;
                    }
                    // 和为0的三个数，相同的值只遍历一次。
                    while (L < R && nums[R] == nums[R - 1]) {
                        R--;
                    }
                    // 取完一组和为 0 的三个数后，两个指针同时移动。
                    L++;
                    R--;
                } else if (sum < 0) {
                    // 如果三个数字之和小于 0 ，则移动左指针增加结果值。
                    L++;
                } else if (sum > 0) {
                    // 如果三个数字之和小于 0 ，则移动由指针减小结果值。
                    R--;
                }
            }
        }        
        return ans;
    }
}
```
