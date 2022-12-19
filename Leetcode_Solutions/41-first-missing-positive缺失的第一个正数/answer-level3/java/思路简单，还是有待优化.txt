### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if(nums.length == 0){
            return 1;
        }

        Arrays.sort(nums);
        int min = 1;
        for(int i=0;i<nums.length;i++){
            if(nums[i] > 0){
                if(nums[i] > min){
                    return min;
                }else{
                    min = nums[i] + 1;
                }
            }
        }
        return min;
    }
}
```