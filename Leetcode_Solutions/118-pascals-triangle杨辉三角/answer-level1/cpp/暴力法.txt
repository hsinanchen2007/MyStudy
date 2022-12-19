### 解题思路
此处撰写解题思路
暴力法
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> endArr;
        vector<int> tempArr;
        for (int i = 0; i<numRows; i++) {
            for (int j = 0; j<=i; j++) {
                if (j==0 || j ==i) {
                    tempArr.push_back(1);
                }else{
                    tempArr.push_back(endArr[i-1][j-1]+endArr[i-1][j]);
                }
            }
            endArr.push_back(tempArr);
            tempArr.clear();
        }
        return endArr;
    }
};
```