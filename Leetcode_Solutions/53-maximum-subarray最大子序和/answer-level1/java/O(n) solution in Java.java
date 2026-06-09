### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int current = 0; //value of current subarray
        int max = Integer.MIN_VALUE; //value of the maximum subarray
        
        if(nums.length == 0){
            return 0;
        }
        
        
        for(int i = 0; i < nums.length; ){ //traverse nums
            if(max < nums[i]){
                max = nums[i];
            }
            if(nums[i] <= 0){
                i++;
                continue;
            }
            else{
                current += nums[i];
                if(max < current){
                    max = current;
                }
                i++;
                for(int j = i; j < nums.length && current >0; j++){
                        current += nums[j];
                        if(current > 0){
                            if(max < current){
                                max = current;
                            }
                            i = j + 1;
                            continue;
                        }
                        else{
                            current = 0;
                            i = j + 1;
                            break;
                        }
                
                }
            }
        }
        return max;
    }
}
```