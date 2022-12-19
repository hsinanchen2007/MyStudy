## 动态规划
**状态：** dp[i]表示以i结尾的最大连续子序列
**状态转移：**
对于当前的nums[i]
如果nums[i] >= 0 则 dp[i] = dp[i-1] + nums[i];
否则 dp[i] = nums[i];

其实我们可以把nums当做dp数组，直接在原数组上面操作，这样可以省掉O(n)的空间


```
    // 动态规划
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return INT_MIN; 
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] >= 0)
                nums[i] += nums[i-1];
            maxSum = max(maxSum, nums[i]);
        }
        return maxSum;
    }
```
## 分治法
注释已经写得很清楚了，这里就不在阐述
```
    // 分治法
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size() == 0) return INT_MIN;
        return divide(nums,0,nums.size()-1);
    }
    int divide(vector<int>& nums, int left, int right)
    {
        if(left == right) return nums[left];
        int mid = (left + right) / 2;
        // 1. 最大数列和在左边
        int sumLeft = divide(nums,left,mid);
        // 2. 最大数列和在右边
        int sumRight = divide(nums,mid+1,right);
        // 3. 最大数列和在中间
        // 先求左边的最大和
        int leftSum = 0,leftMaxSum = INT_MIN;
        for(int i = mid; i >= left; i--)
        {
            leftSum += nums[i];
            leftMaxSum = max(leftMaxSum,leftSum);
        }
        // 求右边的最大和
        int rightSum = 0,rightMaxSum = INT_MIN;
        for(int i = mid + 1; i <= right; i++)
        {
            rightSum += nums[i];
            rightMaxSum = max(rightMaxSum,rightSum);
        }
        return max(max(sumLeft,sumRight),leftMaxSum+rightMaxSum);
    }
```
