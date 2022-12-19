### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        int gobalMax = (1<<31);
        for(int i = 0; i < matrix.size(); i++){             // 起始行
            vector<int> sumOfCol(matrix[0].size(), 0);      // 累加从起始行到终止行，每列的和
            for(int j = i; j < matrix.size(); j++){         // 终止行
                int curMax = (1<<31), curStar = 0;
                for(int k = 0; k < matrix[0].size(); k++){  // 遍历终止行的每列，找出最大值子矩阵：[i, curStar, j, k]
                    sumOfCol[k] += matrix[j][k];            // 累加此列的值
                    if(curMax > 0){                         // 动态规划：curMax = max(curMax + sumOfCol[k], sumOfCol[k]);
                        curMax += sumOfCol[k];
                    }else{
                        curMax = sumOfCol[k];               // 舍弃前面的列
                        curStar = k;                        // 起始列需要更新
                    }
                    if(curMax > gobalMax){                  // 获取最大值
                        gobalMax = curMax;
                        r1 = i;
                        c1 = curStar;
                        r2 = j;
                        c2 = k;
                    }
                }
            }
        }
        return {r1, c1, r2, c2};
    }
};
```