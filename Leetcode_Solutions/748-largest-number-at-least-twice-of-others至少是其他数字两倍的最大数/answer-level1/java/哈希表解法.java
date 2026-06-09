![6ED6C7C9E4766C211BAA21E10573B0B1.png](https://pic.leetcode-cn.com/516a2b6014e23a32f92231cada8d0610c4c9009f3857181dbce5fe7601603693-6ED6C7C9E4766C211BAA21E10573B0B1.png)

```
class Solution {
    public int dominantIndex(int[] nums) {
        //排除特殊情况
        if (nums.length == 1) {
            return 0;
        }
        Map<Integer, Integer> map = new HashMap<>();
        int max = -1; //数组中最大的数字 
        int min = -1; //数组中第二大的数字
        for (int i = 0; i < nums.length; i++) {
            //更新最大、二大的数字
            if (nums[i] > max) {
                min = max;
                max = nums[i];
            } else if (nums[i] < max && nums[i] > min) { //更新二大的数字
                min = nums[i];
            }
            map.put(nums[i], i);
        }
        if (min != 0 && max / min >= 2 || min == 0) {
            return map.get(max);
        }
        return -1;
    }
}
```
