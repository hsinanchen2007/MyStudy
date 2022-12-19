### 解题思路
递归 只保存上级的数组，但是内存消耗还是挺大

### 代码

```cpp
class Solution {
    vector<int> lastRows;
    vector<int> endRows;
    
public:
    
    vector<int> helper(int rowIndex,int numRow){
        if (rowIndex == numRow+1) {
            return lastRows;
        }
        for (int i = 0; i<= rowIndex; i++) {
            if (i == 0 || i == rowIndex) {
                endRows.push_back(1);
            }else{
                endRows.push_back(lastRows[i-1]+lastRows[i]);
            }
        }
        lastRows = endRows;
        endRows.clear();
        return helper(rowIndex+1, numRow);
    }
    vector<int> getRow(int rowIndex) {
        return helper(0,rowIndex);
    }
};
```