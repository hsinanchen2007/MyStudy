### 解题思路
1、空集的子集还是空集；
2、假设已知前K-1个数的所有子集，那么前K个数的所有子集就是，在前K-1个数的所有子集的基础上，每个集合再加上第K个数。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return findsubsets(nums, nums.size());
    }

//前k个数的子集
    vector<vector<int>> findsubsets(vector<int>& nums, int k){
        vector<vector<int>> result;
        if(k==0){
            result.push_back({});
            //result.push_back({nums[0]});
        }
        else{
            vector<vector<int>> lastresult = findsubsets(nums, k-1);
            result = lastresult;
            for(int i = 0; i < lastresult.size(); i++){
                lastresult[i].push_back(nums[k-1]);
                //result.push_back(lastresult[i]);
                result.emplace_back(lastresult[i]);
            }
        }
        return result;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6678221db0528d9c089ffa97da48f49d6290f3a910c26d14fc080df95a5d3d40-image.png)
