有没有大佬帮忙看一下我的疑惑之处，下while都用了两次判断0和2
```
class Solution {
    public void sortColors(int[] nums) {
        if(nums==null || nums.length==0) return;
        int p0=0,p2=nums.length-1;//初始化0，2的指针，指向0的右边界，2的左边界
        for(int curr=0;curr<nums.length;curr++){
            while(nums[curr]==0 && curr>p0){
                swap(nums,p0,curr);
                p0++;
            }
            while(nums[curr]==2  && curr<p2){
                swap(nums,curr,p2);
                p2--; 
            }
            while(nums[curr]==0 && curr>p0){//判读是不是0，是0还得处理
                    swap(nums,p0,curr);
                    p0++;
            }
            while(nums[curr]==2  && curr<p2){//判读是不是2，是2还得处理
                    swap(nums,curr,p2);
                    p2--;
                }
        }
    }
    private void swap(int[] nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
```
