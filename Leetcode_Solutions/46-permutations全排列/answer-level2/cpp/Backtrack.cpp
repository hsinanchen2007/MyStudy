### 解题思路
递归树查找合适所有的path.

### 代码

```cpp
class Solution {
 public:
  vector<vector<int>> permute(const vector<int>& nums) {
    if (nums.size() == 0) {
      return {{}};
    }
    vector<int> path = nums;
    backTrack(0, path);
    return results_;
  }

 private:
  void backTrack(int layer, vector<int>& path) {
    if (layer == path.size()) {
      results_.push_back(path);
      return;
    }

    for (int i = layer; i < path.size(); ++i) {
      if (i != layer) {
        std::swap(path[i], path[layer]);
      }
      backTrack(layer + 1, path);
      if (i != layer) {
        std::swap(path[i], path[layer]);
      }
    }
  }

 private:
  vector<vector<int>> results_;
};
```