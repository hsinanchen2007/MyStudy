```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int len=0;
        int[] d=new int[nums.length];
        d[len]=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]>d[len]) d[++len]=nums[i];
            else{
                int a=0,b=len;
                while(a<=b){
                    int m=(a+b)/2;
                    if(nums[i]>d[m]) a=m+1;
                    else{
                        b=m-1;
                    }
                }
                d[a]=nums[i];
            }
        }
        return len+1;
    }
}
```