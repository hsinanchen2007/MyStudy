## 思路
1. 分别遍历两个vector，保存(string, index)到map中。
2. 遍历其中一个map，在另一个map中寻找是否存在相同key，并更新最小索引和。
3. 再次遍历两个map，选择最小索引和等于第2步中找到的值，然后将key放入结果集。
### 代码
```c++
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> umap1;
        unordered_map<string, int> umap2;
        vector<string> res;
        for (int i = 0; i < list1.size(); ++i) {
            umap1[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); ++i) {
            umap2[list2[i]] = i;
        }        
        int minIndex = INT_MAX;
        for (auto it = umap1.begin(); it != umap1.end(); ++it) {
            if (umap2.count(it->first) > 0) {
                if (it->second + umap2[it->first] < minIndex) {
                    minIndex = it->second + umap2[it->first];
                }
            }
        }
        for (auto it = umap1.begin(); it != umap1.end(); ++it) {
            if (umap2.count(it->first) > 0) {
                if (it->second + umap2[it->first] == minIndex) {
                    res.push_back(it->first);
                }
            }
        }
        return res;
    }
};
```
#### 优化代码（最优解）
- 使用一个map。
- 在另一个list遍历过程中，判断是否存在最小索引和。
```
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> umap;        
        vector<string> res;
        int minIndex = INT_MAX;
        for (int i = 0; i < list1.size(); ++i) {
            umap[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); ++i) {            
            if (umap.count(list2[i]) > 0) {//存在相同key
                int sum = umap[list2[i]] + i;
                if (sum < minIndex) {
                    res.clear();
                    res.push_back(list2[i]);
                    minIndex = sum;
                } else if (sum == minIndex) {
                    res.push_back(list2[i]);
                }
            }
        }        
        return res;
    }
};
```

