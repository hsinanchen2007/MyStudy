### 解题思路
这道题 就两个步骤：
1. 对角线反转
2. 左右翻转

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int h = matrix.size();
        if(h == 0){
            return ;
        }
        int w = matrix[0].size();

        int i = 0;
        int j = 0;
        for(i = 0,j = 0;i<h,j<w;i++,j++){//对角线反转

            for(int k = j+1;k<w;k++){

                int temp = matrix[i][k];
                matrix[i][k] = matrix[k][i];
                matrix[k][i] = temp;
            }
        }

        i = 0;
        j = w-1;

        while(i<j){

            for(int k = 0;k<h;k++){// 左右对调

                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
            }
            i++;
            j--;
        }

        return ;
    }
};
```