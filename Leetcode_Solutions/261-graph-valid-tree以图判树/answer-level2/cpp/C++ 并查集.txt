```C++ []
class Solution {
public:
    vector<int> F;
    int father(int i) {
        if (i != F[i])
            F[i] = father(F[i]);
        return F[i];
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        F.resize(n);
        for (int i = 0; i < n; ++i)
            F[i] = i;
        for (auto& e : edges) {
            int f1 = father(e[0]);
            int f2 = father(e[1]);
            if (f1 == f2)
                return false;
            F[f1] = f2;
        }
        int f = father(0);
        for (int i = 1; i < n; ++i) {
            if (father(i) != f)
                return false;
        }
        return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/25faa1311194953e56aca797283a5b1e8c9af9aa09961b55680aa8ba3f53b460-image.png)
