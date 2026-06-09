
莫得使用哈希表，也莫得考虑太多内存使用

时间复杂度为O(1)，耗时8 ms，内存使用为9.3 MB

借鉴了一下桶排序的思想，把出现过的数字放在桶里，凭借这个来统计数字的出现次数

剩下的应该就是如何利用i，j定位九宫格的格子问题了，经过简单的推导可以得出关系

以下为在VS Code中的运行代码

需要注意的是，由于数字是1-9，而数组是从0开始的，所以要-1，把数组开大一点其实也行

```C++ []
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<char>> board={{'8','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    int row[9][9]={0},col[9][9]={0},Matrix[9][9]={0};
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int num=board[i][j]-'0'-1;
                row[i][num]++;
                col[j][num]++;
                Matrix[3*(i/3)+j/3][num]++;
               if(row[i][num]==2||col[j][num]==2||Matrix[3*(i/3)+j/3][num]==2)cout<<"false"<<endl;
            }
            
        }
    }
    system("pause");
    return 0;
}
```

```LeetCode提交代码 []
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0},rol[9][9]={0},Matrix[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    row[i][num]++;
                    if(row[i][num]==2)return false;
                    rol[j][num]++;
                    if(rol[j][num]==2)return false;
                    Matrix[3*(i/3)+(j/3)][num]++;
                    if(Matrix[3*(i/3)+(j/3)][num]==2)return false;
                }
            }
        }
        return true;
    }
};
```


