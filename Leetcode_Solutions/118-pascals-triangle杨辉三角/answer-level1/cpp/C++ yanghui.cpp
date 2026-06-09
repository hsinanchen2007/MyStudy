### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> yanghuitriangle;
        if(numRows == 0) return  yanghuitriangle;
        vector<int> first;
        first.push_back(1);
        yanghuitriangle.push_back(first);
        if(numRows == 1) return  yanghuitriangle;
        for(int i=1;i<numRows;i++)
        {
            vector<int> item;
            item.push_back(yanghuitriangle[i-1][0]);
            
            for(int j =0;j<yanghuitriangle[i-1].size() - 1;j++)
            {
                item.push_back(yanghuitriangle[i-1][j]+yanghuitriangle[i-1][j+1]);
            }
            item.push_back(yanghuitriangle[i-1][yanghuitriangle[i-1].size() - 1]);
            yanghuitriangle.push_back(item);
        }
        return yanghuitriangle;
    }
};
```