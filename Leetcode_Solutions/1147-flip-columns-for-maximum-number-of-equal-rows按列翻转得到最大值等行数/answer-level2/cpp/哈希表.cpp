### 解题思路
记录每一行的元素与第一个元素之间的相对关系，将其放入map里面，相同的+1,最后返回最大值即可。

### 代码

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>, int> matrixInfo;
        for (auto line : matrix) {
            vector<int> lineInfo;
            int firstNum = line[0];
            for (auto num : line) {
                if (firstNum == num) {
                    lineInfo.push_back(0);
                } else {
                    lineInfo.push_back(1);
                }
            }
            if (matrixInfo.find(lineInfo) == matrixInfo.end()) {
                matrixInfo[lineInfo] = 1;
            } else {
                matrixInfo[lineInfo]++;
            }
        }
        int maxNum = 0;
        for (auto pMatrixInfo : matrixInfo) {
            if (maxNum < pMatrixInfo.second) {
                maxNum = pMatrixInfo.second;
            }
        }
        return maxNum;
    }
};
```