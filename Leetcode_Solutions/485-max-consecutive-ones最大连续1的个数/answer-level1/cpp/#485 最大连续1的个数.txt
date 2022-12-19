
    class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            //算是暴力法吧
            int pos = 0, count = 0;
            int result = 0;
            while(pos < nums.size()){
                if(nums[pos] == 1)
                    count++; 
                else{
                    result = max(result, count);
                    count = 0;
                }
                pos++;
            }
            //因为可能数组末尾部分有连续个1，且个数还是最大的，所以还要在和count比较一次大小
            return max(result, count);
        }
    };