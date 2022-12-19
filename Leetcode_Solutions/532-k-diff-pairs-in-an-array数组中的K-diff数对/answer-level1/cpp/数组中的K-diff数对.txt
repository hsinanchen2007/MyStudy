### 解题思路
使用set作为辅助，使用map保存K-diff数对
遍历数组：
1. 如果set中有与当前元素差的绝对值为k的元素，则把此数对保存到map中，其中较小的数作为key
2. 将当前元素存入set。
返回map的大小即为数对个数。
### 代码

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> ans;
        set<int> helper;

        if(k < 0){
            return 0;
        }

        for(int i=0; i<nums.size(); i++){
            if(helper.find(nums[i] + k) != helper.end()){
                ans.insert(pair<int, int>(nums[i], nums[i]+k));
            } 
            if(helper.find(nums[i] - k) != helper.end()){
                ans.insert(pair<int, int>(nums[i]-k, nums[i]));
            }
            helper.insert(nums[i]);
        }

        return ans.size();
    }
};
```