### 解题思路

这道题用并查集比DFS的复杂度要低。

### 代码

```cpp
class DisjointSet {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
public:
    string Find(string& word) {
        if(parent.count(word) == 0)
            return word;
        else
            return parent[word] = Find(parent[word]);
    }
    
    void Union(string& a, string& b) {
        string rx = Find(a);
        string ry = Find(b);
        if(rx == ry)
            return;
        if(rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if(rank[rx] == rank[ry])
                rank[ry]++;
        }
    }
    
    bool isSimilar(string& a, string& b) {
        return Find(a) == Find(b);
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        DisjointSet ds;
        for(auto pair: pairs) {
            ds.Union(pair[0], pair[1]);
        }
        
        int m = words1.size();
        int n = words2.size();
        if(m != n)
            return false;
        if(m == 0)
            return true;
        for(int i=0; i<m; i++) {
            if(words1[i] != words2[i] && !ds.isSimilar(words1[i], words2[i]))
                return false;
        }
        return true;
    }
};
```

执行用时 :292 ms, 在所有 C++ 提交中击败了68.81% 的用户