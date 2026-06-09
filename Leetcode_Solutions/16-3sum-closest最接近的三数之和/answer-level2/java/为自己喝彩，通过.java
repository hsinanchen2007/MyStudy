### 解题思路
其实和三个数之和为0比较类似，这里选一个最接近的，也就是两个数之差绝对值最小的，每次都记录最小的对应的result，然后夹逼的思想，不断循环，最后的结果就是了。
思考一下，是否还可以加上剪枝，提高效率呢？

### 代码

```java
class Solution {
    int result = Integer.MAX_VALUE;

    public int threeSumClosest(int[] nums, int target) {

        int min = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            int tmp = nums[i];
            int begin = i + 1;
            int end = nums.length - 1;
            while (begin < end) {
                int sum = tmp + nums[begin] + nums[end];
                int cha = Math.abs(sum - target);
                if (cha < min) {
                    min = cha;
                    result = sum;
                }
              
                if (sum > target) {
                    end--;
                } else {
                    begin++;
                }
            }
        }
        return result;
    }
}
```