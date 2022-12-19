### 解题思路
先进行排序，再使用双指针法

### 代码

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());        
        int ans = nums[0]+nums[1]+nums[2];
        for(int i =0;i<nums.size()-2;i++){
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                int sum = nums[i]+nums[start]+nums[end];
                if(abs(target-sum)<abs(target-ans))
                    ans = sum;
                if(sum>target)
                    end--;
                else if(sum<target)
                    start++;
                else
                    return sum;
            }
        }
        return ans;
    }
};
```