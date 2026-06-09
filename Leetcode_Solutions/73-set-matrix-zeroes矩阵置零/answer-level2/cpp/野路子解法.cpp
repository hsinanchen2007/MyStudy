选一个你喜欢的而且一般不会取到的值, 然后每当遇到0, 将元素行与列上面所有非0元素赋为你选的数字

遍历完再把选的数字赋为0

```c++
#include<bits/stdc++.h>
#define SENPAI 1145141919 // SUPPOSE_TO_ZERO

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < matrix.size(); ++k) {
                        matrix[k][j] = matrix[k][j] == 0 ? 0 : SENPAI;
                    }
                    for(int l = 0; l < matrix[0].size(); ++l) {
                        matrix[i][l] = matrix[i][l] == 0 ? 0 : SENPAI;
                    }
                }
            }
        }
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] = matrix[i][j] == SENPAI ? 0 : matrix[i][j];
            }
        }
    }
};
```