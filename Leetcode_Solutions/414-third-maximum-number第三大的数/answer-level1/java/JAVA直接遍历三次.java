由于复杂度要求是O(n)，所以不能使用所有的排序算法
要取得第三大，就要取得第一大，第二大，然后才有第三大，遍历数组三次即可完成，复杂度3N，符合O(n)

```
class Solution {
    public int thirdMax(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return nums[0] >= nums[1] ? nums[0] : nums[1];
        }
        int first = nums[0];
        for (int i : nums) {
            first = first >= i ? first : i;
        }
        int second = 0;
        boolean init1 = false;
        for (int i : nums) {
            if (i < first) {
                if (!init1) {
                    init1 = true;
                    second = i;
                }else{
                    second = second >= i ? second : i;
                }
            }
        }
        if (!init1) {
            return nums[0];
        }
        int third = 0;
        boolean init2 = false;
        for (int i : nums) {
            if (i < second) {
                if (!init2) {
                    init2 = true;
                    third = i;
                }else{
                    third = third >= i ? third : i;
                }
            }
        }
        if (init2) {
            return third;
        } else {
            return first;
        }
    }
}
```

写法复杂了点 ，但是逻辑很明晰了，考虑到可以每次维护一个最大的长度三的数组，但是判断和交换太复杂了，不如这样，逻辑简单明了了
![image.png](https://pic.leetcode-cn.com/4c41937aecc35a99faf1cac717c49ccf1379feb07fec44baf21a52057adc9134-image.png)
