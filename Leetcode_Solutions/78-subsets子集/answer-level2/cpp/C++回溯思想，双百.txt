### 解题思路
此题要求返回数组**所有可能的子集**，且**子集不能重复**，同时，给定的数组中**不包含重复元素**。
此时，我们可以这样思考。
当给定的数组为空集时，返回的数组中，只有{}；
当给定的数组只有一个元素a时，返回的数组中，有{}, {a}；
当给定的数组中有两个元素a,b时，返回的数组中，有{}, {a}, {b}, {a,b}；
观察可以发现，每增加一个元素，其实就是增加的元素与原有输出（比当前元素数量少一个的输出）相组合的结果。
所以，我们可以这样考虑，按顺序每次选择给定数组中元素一个元素，将其与原来的输出组合，即为当前元素个数的输出结果，直到给定数组中所有元素均被组合到返回的数组中。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return {{}};
        vector<vector<int>> ans;
        ans.push_back({});  //首先将输出结果中插入一个空集
        //遍历nums中每一个元素，将其与ans中集合组合
        for (int i = 0; i < nums.size(); ++i){
            int anssize = ans.size();
            //将nums中位置为i的元素与ans中每一个集合组合
            for (int j = 0; j < anssize; ++j){
                vector<int> veci(ans[j]); 
                veci.push_back(nums[i]);
                ans.push_back(veci);
            }
        }
        return ans;
    }
};
```