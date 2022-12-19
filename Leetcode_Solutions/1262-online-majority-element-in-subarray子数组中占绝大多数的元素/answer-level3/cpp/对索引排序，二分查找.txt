时间复杂度过高，存在超时的可能性；
1. 使用数组存储该数目的索引；
2. 如果在left和right范围之类，索引的数量大于threshold，则找到该值；
3. 该解法算法复杂度仍然为O(n*m*lg(n)),存在超时的可能；
```
class MajorityChecker {
public:
    unordered_map<int, vector<int>> idx;
    
    MajorityChecker(vector<int>& arr) {
      for (auto i = 0; i < arr.size(); ++i) idx[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) {
      for (auto &i : idx) {
        if (i.second.size() < threshold) continue;
        auto it1 = lower_bound(begin(i.second), end(i.second), left);
        auto it2 = upper_bound(begin(i.second), end(i.second), right);
        if (it2 - it1 >= threshold) return i.first;
      }
      return -1;
    }
};

```