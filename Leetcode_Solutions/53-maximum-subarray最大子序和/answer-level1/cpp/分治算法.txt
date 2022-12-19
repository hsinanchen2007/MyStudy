终于勉强写出了本题的分治算法（话说动态规划不香嘛）
# 重要参考[https://blog.csdn.net/abnerwang2014/article/details/36027747]()
```
class Solution {
    //分治算法，看收藏题解中的博客链接
private:
    int helper(vector<int>& nums,int left,int right){
        if(left==right)
            return nums[left];//递归的基准情形
        
        int center;
        center=(left+right)/2;//求分界点
        int maxLeftSum;
        maxLeftSum=helper(nums,left,center);//递归，求左半部分子序列的最大子序和，包含中间点
        int maxRightSum;
        maxRightSum=helper(nums,center+1,right);//递归，求右半部分子序列的最大子序和

        //求横跨左半部分和右半部分的最大子序和
        //首先是左半部分包含最后一个元素的最大子序列和（横跨，所以必须包含至少左边最后一个）
        int maxLeftBorderSum=nums[center],leftBorderSum=nums[center];
        for(int i=center-1;i>=left;i--){//倒着求和
            leftBorderSum+=nums[i];
            if(leftBorderSum>maxLeftBorderSum)
                maxLeftBorderSum=leftBorderSum;
        }
        
        //接着是右半部分包含第一个元素的最大子序和（横跨，所以必须至少包含右边第一个）
        int maxRightBorderSum=nums[center+1],rightBorderSum=nums[center+1];
        for(int i=center+2;i<=right;i++){
            rightBorderSum+=nums[i];
            if(rightBorderSum>maxRightBorderSum)
                maxRightBorderSum=rightBorderSum;
        }

        //返回左、右半部分最大子序和及横跨左右部分最大子序和中的最大者
        int res;
        res=max(maxLeftSum,maxRightSum);
        res=max(res,maxLeftBorderSum+maxRightBorderSum);
        return res;
    }
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return helper(nums,0,nums.size()-1);
    }
};
```
