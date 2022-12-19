### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int life = 1;
        int mark1 = -1;
        int mark2 = -1;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] - nums[i-1] < 0){
                life--;
                mark1 = i - 1;
                mark2 = i;
                if(life < 0){
                    return false;
                }
            }
        }
        if(life == 1){
            return true;
        }
        else{
            if(mark2 == nums.length - 1){
                return true;
            }
            if(mark1 == 0){
                return true;
            }
            if(nums[mark1-1] <= nums[mark2]){
                return true;
            }
            if(nums[mark2+1] >= nums[mark1]){
                return true;
            }
            return false;
        }


        
    }
}
```