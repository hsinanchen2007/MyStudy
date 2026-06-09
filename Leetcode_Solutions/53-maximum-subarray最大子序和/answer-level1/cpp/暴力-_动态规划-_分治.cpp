### 解题思路
暴力，动态规划，分治

### 代码

#### 暴力
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxnum = nums[0];
        int n = nums.size();
        int sum;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum > maxnum)maxnum = sum;
            }
        }
        return maxnum;
    }
};
```

#### 动态规划
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int pre = 0, cur;
        for(int i = 0; i < nums.size(); i++){
            cur = max(pre, 0) + nums[i];
            res = max(res, cur);
            pre = cur;
        }
        return res;
    }
};
```

#### 分治
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideconquer(nums, 0, nums.size()-1);
    }

    int divideconquer(vector<int>& nums, int start, int end){
        if(start == end)return nums[start]; //无法分解时直接返回当前值

        int mid = (start + end) / 2; 
        int leftmax = divideconquer(nums, start, mid);
        int rightmax = divideconquer(nums, mid + 1, end);

        //计算中间最大和
        int left = 0, right = 0;
        int leftcross = INT_MIN, rightcross = INT_MIN;
        for(int i = mid; i >= start; i--){
            left += nums[i];
            leftcross = max(leftcross, left);
        }
        for(int i = mid + 1; i <= end; i++){
            right += nums[i];
            rightcross = max(rightcross, right);
        }
        int crossmax = rightcross + leftcross;
        return max(crossmax, max(leftmax, rightmax));
    }
};
```