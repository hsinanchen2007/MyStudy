### 解题思路
对于这个最短的连续子数组，它的左边一定是有序的，右边一定是有序的，由此可以确定一下第一次的边界。但是连续子数组里可能还会有更大或更小的元素，破坏左边和右边的有序，所以要把它们找出来，再分别和左右进行比较，确定最终的边界。

一开始想用动态规划做的，一直想想半天想不出办法，，
### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums.size()==2)return nums[0]<=nums[1]?0:2;
        int left=0,right=nums.size()-1;
        int bi_left,bi_right;
        //第一遍遍历，找到子数组的左界和右界
        while(left<=right){
            bool flag=false;
            if(left+1<=right&&nums[left+1]>=nums[left]){left++;flag=true;}
            if(right-1>=left&&nums[right-1]<=nums[right]){right--;flag=true;}
            if(!flag) break;
        }
        //遍历子序列，找到子序列中的最小和最大元素
        bi_left=left;bi_right=right;
        for(int i=left;i<=right;i++){
            if(nums[i]<nums[bi_left]) bi_left=i;
            if(nums[i]>nums[bi_right]) bi_right=i;
        }
        //遍历左界和右界，确立子序列的范围
        for(;left>=0&&nums[left]>nums[bi_left];left--);
        for(;right<nums.size()&&nums[right]<nums[bi_right];right++);
        
        if(left==right) return 0;
        else return right-left-1;
    }
};
```