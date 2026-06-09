### 解题思路
此处撰写解题思路
第一个for循环判断数组中有无非负数，如果没有，直接返回数组中最小值，如果有，第二个for循环按照常规解题
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int max = Integer.MIN_VALUE;
        int len = nums.length;
        //int max_f = ;
        boolean flag = false;
        for (int a : nums) {
            max = a > max ? a : max; 
            if ((flag = a >= 0 ? true : flag) == true) {
                break;
            }     
        }
        if (flag == false) 
            return max;   
        for (int i = 0; i < nums.length; i++) {
            if (sum < 0)
                sum = 0;
            sum += nums[i];
            max = max > sum ? max : sum;
            
        }
        return max;
    }
}
```