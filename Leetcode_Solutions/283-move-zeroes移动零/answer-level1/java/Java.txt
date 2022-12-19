```
class Solution {
    public void moveZeroes(int[] nums) {
        int count=0,len=nums.length;
        for(int i=0;i<len;i++){
            if(nums[i]!=0){
                nums[count++]=nums[i];
            }
        }
        for(int i=1;i<=len-count;i++){
            nums[len-i]=0;
        }
    }
}
```
直接把非零的数往前放，后面的数再置0就行了。也可以用一次for循环就解决，在里面加上
```
if ((count-1)!=i) nums[i]=0;
```
