
## 思路

题目的求解采用双指针法。在求解过程中需要注意如何消除重复的四元组。

## 代码
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int N = nums.size();
        if(N<=3) return {};// 如果输入的数组长度小于4，返回空数组
        sort(nums.begin(),nums.end()); // 对输入数组进行排序
        int minSum = nums[0]+nums[1]+nums[2]+nums[3];// 计算最小和
        if(minSum>target) return {};  // 如果最小和大于目标值，返回空数组
        int maxSum = nums[N-1]+nums[N-2]+nums[N-3]+nums[N-4];// 计算最大和
        if(maxSum<target) return {}; // 如果最大和小于目标值，返回空数组
        vector<vector<int>> res;
        for(int i=0;i<N-3;i++){
            for(int j=i+1;j<N-2;j++){
                int left=j+1,right=N-1; // 定义左指针和右指针
                while(left<right){ // 当左指针小于右指针时，循环继续
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];  // 求和
                    if(sum==target){ // 和值等于目标值
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});// 存入
                        // 左指针所指的值与下一位相同，则左指针右移一位，用于去除重复项  
                        while(left<right&&nums[left]==nums[left+1])  left++; 
                        // 右指针所指的值与下一位相同，则右指针左移一位，用于去除重复项
                        while(left<right&&nums[right]==nums[right-1])right--;
                        left++,right--; // 左指针右移一位，右指针左移一位
                    } 
                    if(sum>target)right--; // 和值大于目标值，说明右指针较大，右指针左移一位
                    if(sum<target)left++; // 和值小于目标值，说明左指针较小，左指针右移一位
                }
                while(j<N-2&&nums[j]==nums[j+1])j++; // 去除重复项
            }
            while(i<N-3&&nums[i]==nums[i+1])i++; // 去除重复项
        }
        return res;
    }
};
```
