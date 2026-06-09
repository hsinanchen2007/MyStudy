## 方法一： 回溯法 + 深度优先搜索
思路：其实回溯法就是需要把图画清楚，画成树形图，当某一条路走到**底**时开始**回溯**，思想跟深度优先搜索差不多.
```c++
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    unsigned long n_size;
public:
    void backtrack(vector<int>nums) {
        
        if (path.size() == n_size) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            path.push_back(nums[i]);
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            backtrack(temp);
            path.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        this->n_size = nums.size();
        backtrack(nums);
        
        return result;
    }
};
```
## 方法二： Next permutation
思路：将数组排好序不断加入其下一个排列
```c++
vector<vector<int>> permute(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    do {
        result.push_back(nums);
    }while (next_permutation(nums.begin(), nums.end()));

    return result;
    }
```