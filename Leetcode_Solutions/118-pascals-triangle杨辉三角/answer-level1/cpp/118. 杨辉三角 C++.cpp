### 解题思路
1.杨辉三角形第一行一定为1个元素且为1，若有第二行，则第二行有两个元素都为1,因此杨辉三角形每一行的元素的第一个以及最后一个元素都为1。
2.杨辉三角形中间的元素都对应其左右上的元素之和。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int> > triangle;

    // First base case; if user requests zero rows, they get zero rows.
    if(numRows == 0){
        return triangle;
    }

    // Second base case; first row is always [1].
    triangle.push_back({});
    triangle[0].push_back(1);

    for(int rowNum = 1;rowNum < numRows;rowNum++){
        vector<int> row;
        vector<int> preRow = triangle[rowNum - 1];

        // The first row element is always 1.
        row.push_back(1);

        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.

        for(int j = 1;j < rowNum;j++){
            row.push_back(preRow[j - 1] + preRow[j]);
        }

        // The last row element is always 1.
        row.push_back(1);

        triangle.push_back(row);
    }

    return triangle;
    }
};
```