总体思路：两个指针记录1和2的起始坐标，记为b,c;这样c-b就是1的数量，而遍历的时候的指针i，i-c就是2的数量
接下来从头到尾遍历，分为三种情况
1.遍历到的数值为0
在三种颜色都有值的时候，我们只需要考虑三种颜色中间的边界，即b和c。要做的就是将坐标为b的值改为0，坐标为c的值改为1，坐标为2的值改为2。



class Solution {
    public void sortColors(int[] nums) {
        if(nums==null||nums.length==0) return;
        int b=0,c=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                nums[b]=0;
                if(c-b!=0) nums[c]=1;
                if(i-c!=0) nums[i]=2;
                c++;b++;
            }else if(nums[i]==1){
                nums[c]=1;
                if(i-c!=0) nums[i]=2;
                c++;
            }
        }
    }
}