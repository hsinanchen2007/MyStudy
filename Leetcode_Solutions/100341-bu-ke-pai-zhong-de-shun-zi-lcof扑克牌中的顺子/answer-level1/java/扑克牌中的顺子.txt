### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        int count=0;
     Arrays.sort(nums);
     for(int i=0;i<nums.length-1;i++){
         if(nums[i]==0)
         count++;
         else if(nums[i+1]==nums[i])
        return false;
       else if(nums[i+1]!=nums[i]+1){
            count-=nums[i+1]-nums[i]-1;
        }
     }
     return count>=0;
    }
}
```