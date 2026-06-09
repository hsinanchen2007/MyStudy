### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        int count = 0;
        int diff = 0;
        Arrays.sort(nums);
        for(int i = 0;i < nums.length - 1;i++){
            //记录大小王的个数
            if(nums[i]== 0){
                count ++;
            }else{
                if(nums[i] == nums[i+1]){
                    return false;
                }else{
                    diff += nums[i+1] - nums[i] - 1;
                }
            }            
        }
        if(count >= diff || diff == 0){
            return true;
        }
        return false;
    }
}
```