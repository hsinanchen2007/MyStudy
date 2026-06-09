![QQ图片20191222210020.png](https://pic.leetcode-cn.com/4e1ce22ba69274124a5386308ec3a431cc320db727fc5336d88ff502e43ead9d-QQ%E5%9B%BE%E7%89%8720191222210020.png)

### 解题思路
第一次dfs先拿到所有钥匙，
第二次dfs拿到所有糖果。
### 代码

```cpp

const int kMaxLength = 1000;
class Solution {
 public:
  Solution() {}

  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    bool key[kMaxLength];
    memset(&key[0], 0, sizeof(key[0]) * kMaxLength);
    for (int i : initialBoxes) {
      key[i] = true;
    }

    bool visit[kMaxLength];
    memset(&visit[0], 0, sizeof(visit[0]) * kMaxLength);
    for (int i : initialBoxes) {
      DfsKey(status, keys, containedBoxes, i, key, visit);
    }

    memset(&visit[0], 0, sizeof(visit[0]) * kMaxLength);
    int count = 0;
    for (int i : initialBoxes) {
      DfsCandy(status, candies, containedBoxes, i, key, visit, count);
    }
    return count;
  }

  void DfsKey(vector<int>& status, vector<vector<int>>& keys,
              vector<vector<int>>& containedBoxes, int index,
              bool key[kMaxLength], bool visit[kMaxLength]) {
    if (visit[index] || (!key[index] && status[index] == 0)) {
      return;
    }

    visit[index] = true;

    for (int i : keys[index]) {
      key[i] = true;
    }

    for (int i : containedBoxes[index]) {
      DfsKey(status, keys, containedBoxes, i, key, visit);
    }
  }

  void DfsCandy(vector<int>& status, vector<int>& candies,
                vector<vector<int>>& containedBoxes, int index,
                bool key[kMaxLength], bool visit[kMaxLength], int& count) {
    if (visit[index] || (!key[index] && status[index] == 0)) {
      return;
    }

    visit[index] = true;
    count += candies[index];

    for (int i : containedBoxes[index]) {
      DfsCandy(status, candies, containedBoxes, i, key, visit, count);
    }
  }
};
```