### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray0(vector<int>& nums) { // 暴力破解：两个循环
        if(nums.empty())
            return 0;
        int max = (1<<31);
        for(int i = 0; i < nums.size(); i++){
            int curSum = 0;
            for(int j = i; j < nums.size(); j++){
                curSum += nums[j];
                if(curSum > max)
                    max = curSum;
            }
        }
        return max;
    }
    int maxSubArray1(vector<int>& nums){ // 动态规划：公式版，一个数组
        int* sum = new int[nums.size()]{0};
        int maxSum = (1<<31);
        for(int i = 0; i < nums.size(); i++){
            sum[i] = (i == 0) ? nums[i] : max(nums[i] + sum[i-1], nums[i]);
            maxSum = maxSum < sum[i] ? sum[i] : maxSum;
        }
        return maxSum;
    }
    int maxSubArray2(vector<int>& nums){ // 动态规划：内存简化版，一个变量
        int maxSum = (1<<31);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            // if(sum + nums[i] > nums[i]) // 用比较符号，代替 max 公式
            if(sum > 0)
                sum += nums[i];
            else
                sum = nums[i]; // 需要舍弃前面的子序列，重新开始
            maxSum = maxSum < sum ? sum : maxSum;
        }
        return maxSum;
    }
    int maxSubArray3(vector<int>& nums){ // 贪心算法：先累加，若小于0，则重新开始寻找子串
        int maxSum = (1<<31);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
    int findMaxCrossingSubarray(vector<int>& nums, int left, int mid, int right){
        int leftSum = 0;
        int leftMax = (1<<31);
        for(int i = mid; i >= left; i--){ //从中间向左扩展，寻找最大子序列和，不需要舍弃子序列（保证延续性）
            leftSum += nums[i];
            leftMax = leftMax < leftSum ? leftSum : leftMax;
        }
        int rightSum = 0;
        int rightMax = (1<<31);
        for(int i = mid + 1; i <= right; i++){ // 从中间向右扩展
            rightSum += nums[i];
            rightMax = rightMax < rightSum ? rightSum : rightMax;
        }
        return (leftMax + rightMax); // 两者之和为跨中心最大子序列和
    }
    int maxSubArrayCore(vector<int>& nums, int left, int right){
        if(left == right) // 终止条件
            return nums[left];
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayCore(nums, left, mid);               // 1、子序列全在左边
        int rightSum = maxSubArrayCore(nums, mid+1, right);           // 2、子序列全在右边
        int midSum = findMaxCrossingSubarray(nums, left, mid, right); // 3、子序列跨中心
        int result = max(leftSum, rightSum);
        result = max(result, midSum);                                 // 选择左、中、右最大的子序列和
        return result;
    }
    int maxSubArray(vector<int>& nums){ // 分治算法
        return maxSubArrayCore(nums, 0, nums.size()-1);
    }
};
```