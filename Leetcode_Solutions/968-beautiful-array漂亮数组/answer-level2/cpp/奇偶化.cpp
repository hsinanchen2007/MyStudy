### 解题思路
运用了漂亮数组的性质，将其奇偶化。

### 代码

```cpp
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> vecResult;
        if (N == 1) {
            vecResult.push_back(1);
            return vecResult;
        }
        vector<int> leftVec = beautifulArray(N / 2);
        vector<int> rightVec = beautifulArray((N + 1) / 2);
        for (int i = 0; i < leftVec.size() ; i++) {
            vecResult.push_back(leftVec[i] * 2);
        }
        for (int i = 0; i < rightVec.size() ; i++) {
            vecResult.push_back(rightVec[i] * 2 - 1);
        }
        return vecResult;
    }
};
```