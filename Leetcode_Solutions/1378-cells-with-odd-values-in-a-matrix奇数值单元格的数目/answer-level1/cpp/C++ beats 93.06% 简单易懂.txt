### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rowsum(n,0);
        vector<int> colsum(m,0);
        for(vector<int> gr:indices){//各行各列统计加一的次数
            rowsum[gr[0]]++;
            colsum[gr[1]]++;
        }
        int res=0;
        for(int i:rowsum)
            for(int j:colsum)
                if((i+j)%2)
                    res++;
        return res;
    }
};
```