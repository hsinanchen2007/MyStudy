### 解题思路
第一行一个１，从第二行起，首尾先放一个１，中间的元素等于上一层相邻两个元素的和。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > v;
        if(0 == numRows)
            return v;

        vector<int> v1;
        int i, j;
        v1.push_back(1);
        v.push_back(v1);

        for(i = 1; i < numRows; i++){
            v1.clear();
            v1.push_back(1);
            for(j = 1; j <= i -1; j++){
                v1.push_back(v[i-1][j] + v[i-1][j-1]);
            }
            v1.push_back(1);
            v.push_back(v1);
        }

        return v;
    }
};
```