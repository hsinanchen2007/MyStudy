### 解题思路
因爲只需要找到兩個元素，所以用枚舉是可行的。O(n^2)在這裏不會超時。
因爲解存在且唯一，説明在循環過程中不一定會遍歷所有元素，找到即可使用vector存儲下標並返回。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(),i=0,j;
        vector<int> ans;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;    
                };
     return ans;      
    };
};
```