### 解题思路

有点杀鸡用牛刀了…

### 代码

```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if(rx == ry)
            return;
        if(rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if(rank[rx] == rank[ry])
                rank[rx]++;
        }
        count--;
    }
    
    int Find(int x) {
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }
    
    bool Valid(int x, int y) {
        return Find(x) != Find(y);
    }
    
    int Count() {
        return count;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind uf(n);
        for(int i=0; i<leftChild.size(); i++) {
            if(leftChild[i] != -1) {
                if(!uf.Valid(i, leftChild[i]))
                    return false;
                uf.Union(i, leftChild[i]);
            }
            if(rightChild[i] != -1) {
                if(!uf.Valid(i, rightChild[i]))
                    return false;
                uf.Union(i, rightChild[i]);
            }
        }
        return uf.Count() == 1;
    }
};
```