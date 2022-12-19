//大体思路是：
//通过二分查找，每次找一个数进行收敛
//实现：
//如果遇到数组里的值等于 index标记 的设为左边界，因为二者等于时，他前面不可能缺数
//如果遇到不等于设为右边界，这是要么在右边界前面，要么右边界是缺的数

class Solution {
    public int missingNumber(int[] nums) {
        return search(nums,0,nums.length-1);
    }
    public int search(int[] nums,int left,int right){
        int mid = (left+right)/2;

        if (nums[0]!=0)return 0; //左边有可能开始的时候就不等于，不收敛左边，其实直接返回就可以,缺0
        else if(nums[nums.length-1]==nums.length-1) return nums.length;//右边等于，说明整个数组都匹配，差了一个尾，所以返回最后一个数加1
        else if (left+1==right) return right;//剩下left和right相邻的时候,右边就是收敛边界

        if(nums[mid]>mid) return search(nums,left,mid);//right如果可以收敛，收敛结束一定是一个不一样的
        else return search(nums,mid,right);//这里else暗含nums[mid]==mid.left如果可以收敛，收敛结束一定是一样的
    }
}

//以往在题解中受过很多帮助，希望也能给各位朋友在想这道题的朋友一些帮助