### 解题思路
双指针，一个在前面，一个在后面。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result=new int[2];
        int First=0;
        int Last=nums.length-1;
        while(First<Last){
            if((nums[First]+nums[Last])==target){
                result[0]=nums[First];
                result[1]=nums[Last];
                return result;
            }else{
               if((nums[First]+nums[Last])>target)Last--;
               if((nums[First]+nums[Last])<target)First++;
            }
        }
        return new int[]{};
        
    }
}
```