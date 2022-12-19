### 解题思路
此处撰写解题思路
(1)范围控制，一圈一圈剥离，剥离后其实就是循环
例如：
[1, 2, 3, 4,5],
[5, 6, 7, 8,5],    
[9,10,11,12,5],
[9,10,11,12,5],
[9,10,11,12,5]       
走完外部的一圈后变成如下，按照前面的规则再走一遍就好

[6, 7, 8],    
[10,11,12],
[10,11,12],


### 代码

```cpp
class Solution {
public:
    void walk(vector<vector<int>>& matrix, int rs, int re, int cs, int ce, vector<int>& ret){
        if (rs > re && cs > ce) {
            return;
        }

        if (rs <= re) {
            for (int i = 0; i <= ce - cs; i ++) {
                ret.push_back(matrix[rs][cs + i]);
            }//遍历 第一行
        }
        
        if (cs <= ce) {
            for (int i = 1; i <= re - rs; i ++) {
                ret.push_back(matrix[rs + i][ce]);
            }//遍历 最后一列
        }

        if (rs < re) {
            for (int i = 1; i <= ce - cs; i ++) {
                ret.push_back(matrix[re][ce - i]);
            }//遍历 最后一行
        }

        if (cs < ce) {
            for (int i = 1; i <= re - rs - 1; i ++) {
                ret.push_back(matrix[re - i][cs]);
            }//遍历 第一列
        }

        walk(matrix, rs + 1, re - 1, cs + 1 , ce - 1, ret);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return vector<int>();
        }

        if (matrix[0].size() == 0) {
            return vector<int>();
        }
        vector<int> ret;

        walk(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1,ret);

        return ret;
    }
};
```