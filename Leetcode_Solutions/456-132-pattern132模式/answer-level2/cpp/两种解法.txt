记录一下，栈解法思路参照官方题解

```
//暴力
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         bool temp[2]={0};
//         int size=nums.size()-1;
        
//         for(int i=size;i>=0;i--){
//             for(int j=i-1;j>=0;j--){
//                 if(nums[j]>nums[i])temp[0]=1;
//                 if(nums[j]<nums[i] && temp[0])return true;
//             }
//             temp[0]=0;temp[1]=0;
//         }

//         return false;
//     }   
// };


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        stack<int> s;
        int n=nums.size();
        int third=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<third) return true;
            while(!s.empty() && nums[i]>s.top())
            {
                third=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
```
