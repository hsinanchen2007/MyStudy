### 解题思路
此处撰写解题思路
记录一下提醒自己，每次写并查集时都会犯一个错误，就是在合并时，总时把friends[rootJ] = i;直接写成friends[j] = i!!!!切记！！！！！
### 代码

```cpp
class Solution {
public:
    static const int stuNums = 200;
    int friends[stuNums + 1];
    int FindRootFriends(int x)
    {
        while (friends[x] != x) {
            x = friends[x];
        }
        return x;
    }
    int findCircleNum(vector<vector<int>>& M)
    {
        int n = M.size();
        int res = n;
        for (int i = 1; i < n; i++) {
            friends[i] = i;
        }
        if (n == 1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {
                    int rootI = FindRootFriends(i);
                    int rootJ = FindRootFriends(j);
                    if (rootI != rootJ) {
                        friends[rootJ] = i;
                        res--;
                    }
                }
            }
        }
        return res;
    }
};
```