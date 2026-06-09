### 解题思路一

回溯法 + 标记Visited数组

### 代码一

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<bool> visited;
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visited.resize(n, false);
        vector<int> empty;
        backtrack(nums, empty);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& cur) {
        if(cur.size() == n) {
            res.push_back(cur);
            return;
        }

        for(int j=0; j<n; j++) {
            if(!visited[j]) {
                cur.push_back(nums[j]);
                visited[j] = true;
                backtrack(nums, cur);
                visited[j] = false;
                cur.pop_back();
            }
        }
    }
};
```

### 解题思路二

基于原地交换的回溯算法，省去了保存状态的数组的内存。

### 代码二

```cpp
class Solution {
private:
    vector<vector<int>> res;
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        backtrack(nums, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, int i) {
        if(i == n) {
            res.push_back(nums);
            return;
        }
        
        for(int j=i; j<n; j++) {
            // Place nums[j] at position i.
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
            // Backtrack.
            swap(nums[i], nums[j]);
        }
    }
};
```