```
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums==null ||nums.length<=0) return 0;
        int count=0;//将不为val的数都往前移
        int j=nums.length-1;//从最后开始，前面遇到val就拿后面的填坑
        for(int i=0;i<j;i++){
            if(nums[i]==val){
                while( j>i && nums[j]==val){//找到不是val的下标j,且j必须大于i
                    j--;
                    if(j==0 && nums[j]==val) return 0;
                }
                nums[i]=nums[j];
                j--;
            }   
        }
        if(nums[j]==val){
            return j;
        }
        return j+1;
    }
}
```
