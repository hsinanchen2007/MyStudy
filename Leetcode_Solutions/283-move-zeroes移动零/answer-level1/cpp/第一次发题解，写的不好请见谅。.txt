    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            //原地算法 双指针 一个记录非零元素位置 
            //另一个记录要交换的位置
            int j = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] != 0 && nums[j] == 0){
                    //这么做，对于题中的示例是满足的
                    nums[j] = nums[i];
                    j++;
                    nums[i] = 0;
                }
                //避免前面有已经排好序的非零数字，就是i=j,但该位置上是非零数字不用交换
                if(nums[i]!=0 && nums[j]!=0){
                    j++;
                }
            }
        }
    };