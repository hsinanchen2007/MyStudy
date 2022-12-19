# 代码
```java []
class Solution {
    public int removeDuplicates(int[] nums) {
        int index=0;
        int i,j;
        for(i=0;i<nums.length;){
            nums[index]=nums[i];
            for(j=i+1;j<nums.length;j++) if(nums[j]!=nums[j-1]) break;
            index+=1;
            i=j;
        }
        return index;
    }
}
```
