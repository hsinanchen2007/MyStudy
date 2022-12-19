### 解题思路

### 代码
两小边和大于第三边
```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        for(auto num: nums){
            if(num < 0) return 0;
        }
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int tag = 0;
        for(int k = nums.size()-1; k > 1; k--){
            int i = 0, j = k - 1;
            while(i < j){
                if(nums[i] + nums[j] > nums[k]){
                    tag += (j - i);
                    j--;
                }
                else{
                    i++;
                }

            }
        }
        return tag;
    }
};
```