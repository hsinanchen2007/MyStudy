### 解题思路
sebset 方法变形，先了解subset的模板
void subsetHelper(vector<vector<int>>& result, vector<int>& sebset, vector<int>& nums, int pos) {
    result.push_back(sebset);
    for (int i = pos; i < nums.size(); i++) {
        sebset.push_back(nums[i]);
        subsetHelper(result, sebset, nums, pos + 1);
        temp.pop_back();
    }
}
模板重要的是：
（1）什么时候输出
（2）什么时候跳过

对于全排列（无重复）：
（1）subset 的size 是 nums 的size的输出；
（2）什么时候跳过，由于全排列，每次都要从头遍历（而不是从上一次pos遍历）所以要标记哪些位置的已经放入sebset，不能重复放入；


因此：关键点（key）
（1）有个相同大小数组记录对应点是否放入sebset；
（2）回溯subset的时候，也要重置这个对应点的状态；

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        subsetHelper(result, used, temp, nums);
        return result;
    }
    void subsetHelper(vector<vector<int>>& result, vector<int>& used, vector<int>& temp, vector<int>& nums) {
         if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    temp.push_back(nums[i]);
                    used[i] = 1;
                    subsetHelper(result, used, temp, nums);
                    used[i] = 0;
                    temp.pop_back();
                }
        }
        
    }
};
```