```cpp
class Solution {
public:
    // maximum 26 characters
    vector<int> parents = vector(26,0);
    // union find
    int find(int x) {
        if (x!=parents[x]) parents[x]=find(parents[x]);
        return parents[x];
    }
    void unionSet(int x, int y) {
        int xx = find(x);
        int yy = find(y);
        if (xx==yy) return;
        parents[xx] = yy;
    }
    bool connected(int x, int y) {
        if (find(x)==find(y)) return true;
        else return false;
    }
    // helper func
    int toInt(char c) {
        return c-'a';
    }
    // main
    bool equationsPossible(vector<string>& equations) {
        for (int i=0; i<26 ;i++) parents[i]=i;
        for (auto e : equations) if(e[1]=='=') unionSet(toInt(e[0]), toInt(e[3]));
        for (auto e : equations) if(e[1]=='!' && connected(toInt(e[0]), toInt(e[3]))) return false;
        return true;
    }
};
```
