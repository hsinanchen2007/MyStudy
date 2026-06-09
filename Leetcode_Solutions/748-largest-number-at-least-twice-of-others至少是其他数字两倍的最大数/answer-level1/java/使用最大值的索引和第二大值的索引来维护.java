### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int dominantIndex(int[] nums) {
       int maxIndex=0;
       int secondMaxIndex=0;
       if(nums.length==1) return 0;
       for(int i=0;i<nums.length;i++){
           if(nums[i]>=nums[maxIndex]){
               secondMaxIndex=maxIndex;
               maxIndex=i;
           }else{
               if(secondMaxIndex==maxIndex|| nums[secondMaxIndex]<nums[i]){
                   secondMaxIndex=i;
               }
           }
       }
       return nums[maxIndex]>=nums[secondMaxIndex]*2?maxIndex:-1;
    }
}
```