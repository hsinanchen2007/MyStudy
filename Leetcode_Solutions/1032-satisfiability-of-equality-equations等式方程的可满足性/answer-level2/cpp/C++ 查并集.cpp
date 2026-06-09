### 解题思路
查并集
先把相等的都合并。然后再遍历不等的，看是不是在同一个集合里面。
在第一次遍历的时候，如果遇到了不等的方程式，也可以同时判断他们是不是已经在一个集合里面了，如果已经在同一个集合，那么可以直接返回false

### 代码

```cpp
class Solution {
public:
    vector<int> parent;
    
    void init(int size) {
        for (int i=0; i<size; i++) {
            parent.emplace_back(i);
        }
    }
    
    int find(int i) {
        while (i != parent[i]) {
            i = find(parent[i]);
        }
        return i;
    }
    
    void merge(int i, int j) {
        int m = find(i);
        int n = find(j);
        parent[m] = n;
    }
    
    bool equationsPossible(vector<string>& equations) {
        init(26);
        vector<string> unequal;
        for (int i=0; i<equations.size(); i++) {
            int m = find(equations[i][0] - 'a');
            int n = find(equations[i][3] - 'a');
            if ('!' == equations[i][1]) {
                if (m == n) {
                    return false;
                }
                unequal.emplace_back(equations[i]);
            } else {
                merge(m, n);
            }
        }
        
        for (int i=0; i<unequal.size(); i++) {
            int m = find(unequal[i][0] - 'a');
            int n = find(unequal[i][3] - 'a');
            if (m == n) {
                return false;
            }
        }
        return true;
    }
};
```