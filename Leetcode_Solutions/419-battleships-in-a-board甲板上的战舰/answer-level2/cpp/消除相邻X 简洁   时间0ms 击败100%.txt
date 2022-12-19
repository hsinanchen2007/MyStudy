首先，只要出现了一个X 那么这一定时某个战舰的： sum ++;
接着， 和这个X相邻的X一定是同一个战舰的： 消除
使用递归消除相邻的X  因为没有相邻战舰，所以不会误消除其他战舰的信息

注意：
1.别出界
2.空甲板的判断

优点：快，简单    空间上，改写递归成循环，还能提高
缺点：修改了原来的信息
```
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();//获取行列大小
        
        if (m == 0 || n == 0)//排除空的情况
            return 0;
        
        int sum = 0;
        int i, j;
       
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                if (board[i][j] == 'X'){//只要出现了一个X 那么这一定时某个战舰的
                    sum += 1;
                    search(board, i, j, m, n);//消除和这个X相邻的X 因为时是同一个
                }
            }
        }
       
        return sum;
    }
    
    void search(vector<vector<char> > &board, int i, int j, int m, int n){
       
        if (j+1 < n && board[i][j+1] == 'X'){//避免出界
            board[i][j+1] = '#';
            search(board, i, j+1, m, n);
        }
        
        if (i+1 < m && board[i+1][j] == 'X'){
            board[i+1][j] = '#';
            search(board, i+1, j, m, n);
        }
    }
};
```
