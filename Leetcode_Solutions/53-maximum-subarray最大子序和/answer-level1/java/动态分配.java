### 解题思路
分治法也想出来了，不过太麻烦了8，就懒得去实现了

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int i = 0,sum = 0,max =Integer.MIN_VALUE;
        for(;i<nums.length;i++){
            int temp = sum;
            sum += nums[i];
            if(sum < 0){
                if(sum > max){
                    max = sum;
                } 
                sum = 0;
                continue;
            }
            if(sum > max){
                max = sum;
            } 
        }
        return max;
    }
}
```