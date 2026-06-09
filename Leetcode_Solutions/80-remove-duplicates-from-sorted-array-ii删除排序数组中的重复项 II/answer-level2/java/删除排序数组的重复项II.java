# 代码
```java []
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0) return 0;
        int index=1;
        boolean flag=false;
        int i,j;
        for(i=1;i<nums.length;){
            if(nums[i]==nums[i-1]){
                if(flag==false) {flag=true;nums[index++]=nums[i];}
                else{
                    for(j=i+1;j<nums.length;j++){
                        if(nums[j-1]!=nums[j]) break;
                    }
                    i=j;
                    flag=false;
                }
            }
            else{
                nums[index++]=nums[i];
                i++;
            }
        }
        return index;
    }
}
```
