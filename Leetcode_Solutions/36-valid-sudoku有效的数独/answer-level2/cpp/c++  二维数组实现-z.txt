### 解题思路
https://leetcode-cn.com/problems/valid-sudoku/solution/36-jiu-an-zhao-cong-zuo-wang-you-cong-shang-wang-x/
思路来源，看不懂我的代码可以看他的，讲解细致
### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row[9][10]={0};
        int column[9][10]={0};
        int sbox[9][10]={0};        //用三个数组分别记录对应的行，列，小数独中对应值为value的元素出现次数，9行是因为矩阵为9*9，有9个小数独
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               if(board[i][j] == '.') continue;

               int value=board[i][j]-'0';      //得到当前元素的int型值
               if(row[i][value])    return false;
               if(column[j][value]) return false;
               int k=i/3*3+j/3;     //表示元素在第几个小数独中
               if(sbox[k][value])   return false;
               row[i][value]++;
               column[j][value]++;
               sbox[k][value]++;        //使对应元素的出现次数++
            }
        }
        return true;
    }
};
```