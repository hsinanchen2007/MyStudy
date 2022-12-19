### 解题思路
时间复杂度 O(n^2), 空间复杂度： O(1)
首先排序，然后依次遍历。
当处于第i个位置时，在[i+1,n]中求出 和为 0-nums[i]的两个数字
求的方法为 双指针法。
注意，不要重合

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<2)
            return result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; ++i){
            if(nums[i]>0){ // 提前跳出
                break;
            }
            // 避免相同解
            if(i==0 || nums[i]!= nums[i-1]){
                vector<int> tmp;
                tmp.push_back(nums[i]);
                int j=i+1, k=nums.size()-1;
                while(j<k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum==0){
                        tmp.push_back(nums[j++]);
                        tmp.push_back(nums[k--]);
                        result.push_back(tmp);
                        tmp.resize(1);
                        // 防止相同解
                        while(j<k && nums[j]==nums[j-1])
                            ++j;
                    }else if(sum>0){
                        --k;
                    }else{
                        ++j;
                    }
                }
            }
        }
        return result;
    }
};
```