class Solution {
public:
    int findMin(vector<int>& nums) {
        return find(nums,0,nums.size()-1);
    }
    
    int find(vector<int>& nums,int left,int right){
        if(nums[right]>nums[left]){
            return nums[left];
        }//针对递增序列来的
        if(right-left<=1){
            return min(nums[left],nums[right]);
        }//剩两个就直接比较了
        int middle=left+(right-left)/2;
        if(nums[middle]<nums[left]){
            return find(nums,left,middle);
        }else if(nums[middle]>nums[left]){
            return find(nums,middle+1,right);
        }else{
            return min(find(nums,left,middle),find(nums,middle+1,right));
        }
    }
};