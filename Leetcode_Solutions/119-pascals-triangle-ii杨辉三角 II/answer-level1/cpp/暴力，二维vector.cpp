### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>triangle(rowIndex+1);
        for(int i = 0 ; i< rowIndex + 1 ; i++)
        {
            triangle[i] = vector<int>(i + 1 , 1);
        }

        for(int j = 2 ; j < rowIndex + 1  ; j++)
        {
            for(int k = 1 ; k < j ; k++)
            triangle[j][k] = triangle[j - 1][k - 1] + triangle[j - 1][k];
        }
        return triangle[rowIndex];

    }
};
```