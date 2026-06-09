### 解题思路
注释部分为大佬代码，下面为我自己修改后的代码

### 代码

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        //如果nums[i-1]<nums[i+1]:修改nums[i];如果nums[i-1]>nums[i+1]:修改nums[i+1]
        // 例如：[3,4,2,3]  4的左边3大于右边2，所以把4的值赋给2变成[3,4,4,3]
        // int count = 0;
        // for(int i = 0;i<nums.length-1;i++){
        //     int temp = nums[i];
        //     if(nums[i] > nums[i+1]){
        //         if( i > 0){
        //             nums[i] = nums[i-1];
        //         }else{
        //             nums[i] = nums[i+1];
        //         }
        //         if(nums[i] > nums[i+1]){
        //             nums[i] = temp;
        //             nums[i+1] = nums[i];
        //         }
        //         count++;
        //         if(count > 1){
        //             return false;
        //         }
        //     }
        // }
        // return true;
        int count = 0;
        for(int i = 0;i<nums.length-1;i++){
            if(nums[i] > nums[i+1]){
                if(i == 0){
                    nums[i] = nums[i+1];
                }else{
                    if(nums[i-1] > nums[i+1]){
                        nums[i+1] = nums[i];
                    }else{
                        nums[i] = nums[i+1];
                    }
                }
                count++;
                if(count > 1){
                    return false;
                }
            }
        }
        return true;
    }
}
```