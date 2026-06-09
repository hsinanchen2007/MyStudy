### 解题思路
此处撰写解题思路
![1329.jpg](https://pic.leetcode-cn.com/328d74c097c288592860befe348e88633da41a563ec09ed7dbc5e4512df4cf03-1329.jpg)
### 代码
```cpp
#include <queue>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.empty()) return mat;
        priority_queue<int, vector<int>, greater<int>> myQue; //小顶堆
        //for循环时牢牢抓住一点，i+j的值在一对角线上为定值
        //no no no
        //j = i + k

        //for(int k = -3; k < 3; ++k)
        int border1 = 1-mat[0].size();
        int border2 = mat.size();
        //for(int k = 1-mat[0].size(); k <mat.size(); ++k) 将永远执行不到
        for(int k = border1 ; k < border2 ; ++k)
        {
            if(k <= 0)
            {
                for(int j = 0; j-k < mat[0].size() && j < mat.size(); ++j)
                {
                    myQue.push(mat[j][j-k]);
                }
                for(int j = 0; j-k < mat[0].size() && j < mat.size(); ++j)
                {
                    mat[j][j-k] = myQue.top();
                    myQue.pop();
                }
            }
            else
            {
                for(int i = 0; i+k < mat.size() && i < mat[0].size(); ++i)
                {
                    myQue.push(mat[i+k][i]);
                }
                for(int i = 0; i+k < mat.size() && i < mat[0].size(); ++i)
                {
                    mat[i+k][i] = myQue.top();
                    myQue.pop();
                }
            }
        }
        return mat;
    }
};
```