### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n,0), column(m,0);
        int odds = 0;
        for(auto v: indices){
            row[v[0]]++;
            column[v[1]]++;
        }
        for(auto r: row){
            for(auto c: column){
                if((r+c)%2)  
                    odds++;
            }
        }
        return odds;
    }
};
```