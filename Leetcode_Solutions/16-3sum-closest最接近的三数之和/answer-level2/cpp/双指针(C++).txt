### 解题思路
本题类似于三数求和题目，首先对给定的数组nums排序，然后利用双指针left和right进行求和sum，即int sum = nums[i] + nums[left] + nums[right]，最后，判断所求sum与目标target的距离，如果更近则更新最接近的三数之和threeSum，即若abs(sum - target) < abs(threeSum - target)则threeSum = sum。否则如果sum>target则 right--；sum < target则left++，如果 sum == target则说明距离为0，直接返回结果，即通过代码(sum > target)? right-- : left++;实现

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int threeSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++)
        {
          int left = i + 1, right = nums.size() - 1;
          while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < abs(threeSum - target))
                 threeSum = sum;
                else (sum > target)? right-- : left++;
            }
        }
        return threeSum;
    }
};
```