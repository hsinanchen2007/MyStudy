### 解题思路
每加入一个新的元素时，该子集的集合就要进行扩张，成倍的增加

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i, j, size;
        // 首先空集是任何集合（包括空集合）的一个子集，需要加入
        ans.push_back(vector<int>());
        // 每加入一个新的元素时，该集合就要进行扩张
        for(i = 0; i < nums.size(); i++) {
            size = ans.size();
            j = 1;
            // 该元素本身也作为一个子集
            ans.push_back({nums[i]});
            // 统计当前所有的子集，将这size-1个子集进行扩展后添加到集合的后面，构成新的子集
            while(j < size) {
                vector<int> t(ans[j]);
                t.push_back(nums[i]);
                ans.push_back(t);
                j++;
            }
        }
        return ans;
    }
};
```