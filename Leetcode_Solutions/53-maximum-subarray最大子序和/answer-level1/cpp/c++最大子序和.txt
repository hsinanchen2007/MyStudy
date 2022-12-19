//始终保证前面序列和为正才继续往后面加，否则前面的置为0，从新计算
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lastSum=0;
        int maxSum=nums[0];    //不可初始化为0，否则解决不了数组为负数的情况。
        for(int i=0;i<nums.size();i++){
            lastSum+=nums[i];
            if(lastSum>maxSum){
                maxSum=lastSum;
            }
            if(lastSum<=0){
                lastSum=0;
            }
        }
        return maxSum;
    }
};