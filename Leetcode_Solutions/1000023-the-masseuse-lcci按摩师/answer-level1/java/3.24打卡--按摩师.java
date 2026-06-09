### 解题思路
此处撰写解题思路
把dp数组优化成两个变量可以处理，但是更快的方法是在原数组上进行修改（题意如果允许）
### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        if(nums.length == 1){
            return nums[0];
        }
        nums[1] = Math.max(nums[0] , nums[1]);
        for(int i = 2 ; i < nums.length ; i++){
            nums[i] = Math.max(nums[i-1] , nums[i-2]+nums[i]);
        }
        return nums[nums.length-1];
    }
}

```