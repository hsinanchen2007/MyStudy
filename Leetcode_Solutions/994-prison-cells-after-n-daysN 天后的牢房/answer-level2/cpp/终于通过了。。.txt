### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> mem;

    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        int count = 0;
        vector<int> curVec(cells.size(), 1);
        vector<int> tmpVec(cells.size(), 0);
        for (int i = 1; i < cells.size() - 1; i++) {
            tmpVec[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
        }
        mem.push_back(tmpVec);
        vector<int> preVec = tmpVec;
        while (curVec != mem[0]) {
            count++;
            curVec[0] = 0;
            curVec[curVec.size() - 1] = 0;
            for (int i = 1; i < curVec.size() - 1; i++) {
                curVec[i] = preVec[i - 1] == preVec[i + 1] ? 1 : 0;
            }
            preVec = curVec;
            mem.push_back(curVec);
        }
        int needCmputeCount = (N - 1) % count;
        return mem[needCmputeCount];
    }
};
```