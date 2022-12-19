```cpp

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            
            //res = max(res, sum) // Time consuming 
            if (sum > res)
                res = sum;
                   
        }
        return res;
    }
};


// 循环，本质和动态规划一样
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int res = INT_MIN;

//         for (int i = 0; i < nums.size(); i++) {
//             sum += nums[i];
//             res = max(res, sum);  
//             if (sum < 0) {
//                 sum = 0;
//                 continue;
//             }  
                   
//         }
//         return res;
//     }
// };

```