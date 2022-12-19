class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        int lastValue = -9999;
        int nowValue = 0;
        int count = 1;
        int lastCount = 0;
        int temp = 0;
        int flag = 0;
        for(int i = 0; i < nums.size(); i++)
        {
           
            nowValue = nums[i];
            if(nowValue == lastValue)
                count++;
            else
            {
                if(1 == flag)
                { 
                    temp = lastCount + count;
                    flag = 0;
                }
                lastCount = count;
                count = 1;
                if(nowValue - lastValue == 1)
                    flag = 1;
            }
            lastValue = nowValue;
            if(temp > res)
                res = temp;
            if(i == nums.size() - 1 && 1 == flag)
            {
                temp = lastCount + count;
                if(temp > res)
                   res = temp;
            }
            
        }
        return res;
    }
};