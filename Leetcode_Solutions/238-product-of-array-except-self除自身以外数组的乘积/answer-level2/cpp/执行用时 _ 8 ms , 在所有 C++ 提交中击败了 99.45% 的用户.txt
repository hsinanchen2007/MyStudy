```
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        //把向量output初始化为1
        vector<int> output(n,1);  

        //采用两端同时累乘，最终得到的ouput[i]的值即除nums[i]以外的乘积
        int left = 1,right = 1;
        for(int i = 0; i < n; i++)
        {
            //0~i-1项乘积置于output[i]
            output[i] *= left;    
            left *= nums[i];

            //output[i]再乘以i+1~n-1项
            output[n-1-i] *= right;
            right *= nums[n-1-i];
        }
        
        return output;
    }
};
```
