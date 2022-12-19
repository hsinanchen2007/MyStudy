### 解题思路
最关键的是去除重复值，首先是去除最小数和最大数的可能重复值，其次四数之和等于target时，需要去掉左中间数和右中间数的重复值，在不等于target时可以不用加去除重复值的操作，不然就容易超时

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 3; i++) {
            for (int r = nums.length - 1; r > i + 2; r--) {
                if (r != nums.length - 1 && nums[r] == nums[r + 1]) {
                    continue;//去掉可能重复的r
                }else if (i != 0 && nums[i] == nums[i-1]){
                    continue;//去掉可能重复的i
                }
                int left = i + 1, right = r - 1;
                int sum = target - nums[i] - nums[r];

                while (left < right) {
                    if (sum == nums[left] + nums[right]) {
                        res.add(Arrays.asList(nums[i], nums[left], nums[right], nums[r]));
                        while (left < right && nums[left] == nums[left + 1]) left++;//去除重复的left
                        while (right > left && nums[right] == nums[right - 1]) right--;//去除重复的right
                        left++;
                        right--;
                    } else if (sum < nums[left] + nums[right]) {
                        right--;//不能加去除重复的循环，不然超时
                    } else {
                        left++;//不能加去除重复的循环，不然超时
                    }
                }
            }
        }
        return res;
    }
}
```