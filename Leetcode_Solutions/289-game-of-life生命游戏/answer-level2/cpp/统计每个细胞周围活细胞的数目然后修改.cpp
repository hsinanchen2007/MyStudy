### 解题思路
遍历每个数字，通过countLive()统计周围活细胞的数目
然后判断当前细胞是死是活
每行判断结束后，将结果添加到原数组末尾
最后删去原数组前m行数据即可
### 代码

```cpp
class Solution {
public:
    int m,n;

    int CountLive(vector<vector<int>>& board,int i,int j){
        int ans = 0;

        if(i-1>=0 && j-1>=0)
            if(board[i-1][j-1] == 1)
                ans ++;
        if(i-1>=0)
            if(board[i-1][j] == 1)
                ans ++;
        if(i-1>=0 && j+1<n)
            if(board[i-1][j+1] == 1)
                ans ++;
        if(j-1>=0)
            if(board[i][j-1] == 1)
                ans ++;
        if(j+1<n)
            if(board[i][j+1] == 1)
                ans ++;
        if(i+1<m && j-1>=0)
            if(board[i+1][j-1] == 1)
                ans ++;
        if(i+1<m)
            if(board[i+1][j] == 1)
                ans ++;
        if(i+1<m && j+1<n)
            if(board[i+1][j+1] == 1)
                ans ++;

        return ans;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int count;
        vector<int> vi;

        m = board.size();
        if(m != 0)
            n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count = CountLive(board,i,j);

                if(board[i][j] == 1){
                    if(count < 2){
                        vi.push_back(0);
                    }
                    else if(count < 4){
                        vi.push_back(1);
                    }
                    else{
                        vi.push_back(0);
                    }
                }
                else{
                    if(count == 3){
                        vi.push_back(1);
                    }
                    else{
                        vi.push_back(0);
                    }
                }
            }

            board.push_back(vi);
            vi.clear();
        }

        board.erase(board.begin(),board.begin()+m);
    }
};
```