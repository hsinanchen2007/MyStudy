### 解题思路
对于这种排序数值为整数且有范围，可以考虑用空间换时间的思路，使用计数排序，本题时间复杂度为O(n*m+(m+n-1)*101)，运行速度比简单的使用内置排序算法或者自己写冒泡要快得多。

每排列一条斜线上的数时，使用一个数组numCount记录斜线上的数出现的次数，数组的下标代表该数字，内容则代表该数字出现的次数,遍历一次斜线上的元素后，再同时遍历斜线和numCount，从小到大遍历numCount,赋值即可。



### 代码

```cpp
class Solution {
public:
    void addRowAddCol(int &row, int &col){
        row++;
        col++;
    }


    void simpleSort(int rowS, int colS, vector<vector<int>>& mat ){
        vector<int> numCount(101 , 0) ;
        int rowNum = mat.size();
        int colNum = mat[0].size();
        for(int nowRow=rowS, nowCol=colS; nowRow<rowNum && nowCol<colNum ;){
            int matNum = mat[nowRow][nowCol];
            numCount[matNum] ++;
            addRowAddCol(nowRow, nowCol);
        }


        for(int nowRow=rowS, nowCol=colS, i=0; nowRow<rowNum && nowCol<colNum && i<numCount.size(); ){
            if(numCount[i] == 0){
                i ++;
            }
            else{
                numCount[i]--;
                mat[nowRow][nowCol] = i;
                addRowAddCol(nowRow, nowCol);
            }
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++){
            simpleSort(i, 0, mat);

        }
        for(int i = 1; i < mat[0].size(); i++){
            simpleSort(0, i, mat);
        }

        return mat;
    }
};
```

![1.png](https://pic.leetcode-cn.com/e74d4264d03d493b2215307ee7d421ae4a0cfd02226b65d32229778c472c1741-1.png)
