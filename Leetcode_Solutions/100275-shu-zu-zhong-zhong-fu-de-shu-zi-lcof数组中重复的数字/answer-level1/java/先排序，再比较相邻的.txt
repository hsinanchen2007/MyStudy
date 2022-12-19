

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        int temp=-1;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]){
                temp=nums[i];break;
                
            }
            

        }return temp;
        

    }
}
```