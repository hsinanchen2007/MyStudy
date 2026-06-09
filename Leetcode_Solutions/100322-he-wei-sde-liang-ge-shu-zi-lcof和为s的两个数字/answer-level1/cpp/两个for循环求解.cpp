class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> add(2,0);
        int one=0;
        int two=0;
        for(int i=0;i<nums.size();i++){
            one=nums[i];
            for(int j=i+1;j<nums.size();j++){
                two=target-one;
                if(nums[j]==two){
                    add[0]=one;
                    add[1]=two;
                }
            }
        }
        return add;
    }
};