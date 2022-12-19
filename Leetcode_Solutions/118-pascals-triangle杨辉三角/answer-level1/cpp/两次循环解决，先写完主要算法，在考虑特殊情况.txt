### 解题思路
1、每行的第一个数和最后一个数都是1
2、result[i][j]=result[i-1][j-1]+result[i-1][j]
3、将numRows=0的特殊情况考虑进去

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows>0)
        {
            vector<int> v;
            v.push_back(1);
            result.push_back(v);
        }
        
        for(int i=1;i<numRows;i++)
        {
            vector<int> vec;
            vec.push_back(1);//第一个数肯定是1
            for(int j=1;j<i;j++)
            {
                int temp=result[i-1][j-1]+result[i-1][j];
                vec.push_back(temp);
            }
            vec.push_back(1);//最后一个数肯定是1
            result.push_back(vec);
        }
        return result;
    }
};
```