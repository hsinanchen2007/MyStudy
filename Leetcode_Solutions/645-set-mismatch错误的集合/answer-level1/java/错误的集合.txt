### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int count=0,number=nums.length,k=0;
        Arrays.sort(nums);
        for(int i=1;i<=number;i++){
         count+=i;
     }
     for(int i=0;i<nums.length-1;i++){
         count-=nums[i];
         if(nums[i]==nums[i+1]){
             k=nums[i];
         }
     }
     count=count-nums[nums.length-1]+k;
     return new int[]{k,count};
    }
}
```