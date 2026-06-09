### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {
 if (nums.length==0){
            return 0;
        }
        if (nums.length==1){
            return nums[0];
        }
        int[] result = new int[nums.length];
        for(int i=0; i< nums.length; i++) {
            if (i==0){
                result[i] = nums[i];
            }else if (i==1){
                result[i] = Math.max(nums[0], nums[1]);
            }else{
                result[i] = Math.max(result[i-1], result[i-2] + nums[i]);
            }
        }
        return result[nums.length-1];
    }
}
```