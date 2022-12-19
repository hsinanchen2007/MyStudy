class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int j = 0;
        int len = 99999;
         int tep = 0;
        for(int i =0;i < nums.size();i++){
            sum += nums[i];
            if(sum < s){
                continue;
            }
            while(sum >= s){
                if(i -tep + 1 < len){
                    len = i -tep + 1;
                }
                cout<<"ss"<<endl;
                sum = sum - nums[tep];
                tep++;
            }
        }
        if(len == 99999){
            return 0;
        }
        return len;
    }
};
