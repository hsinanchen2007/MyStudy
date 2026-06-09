### 解题思路
按照行列九宫格的次序依次检测

### 代码

```java []
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean []used = new boolean[9];

        // rows & columns
        for(int i=0; i<9; ++i){
            // rows
            Arrays.fill(used, false);
            for(int j=0; j<9; ++j){
                if(!check(board[i][j], used))
                    return false;
            }

            // columns
            Arrays.fill(used, false);
            for(int j=0; j<9; ++j){
                if(!check(board[j][i], used))
                    return false;
            }
        }

        // 九宫格
        for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j){
                Arrays.fill(used, false);
                for(int r=i*3; r<i*3+3; ++r)
                    for(int c=j*3; c<j*3+3; ++c){
                        if(!check(board[r][c], used))
                            return false;
                    }
            }
        

        return true;
    }

    private boolean check(char ch, boolean []used){
        if(ch == '.')
            return true;
        else if(used[ch-'1'])
            return false;
        else
            return used[ch-'1']=true;
    }
}
```
```python []
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        self.used = [False for _ in range(9)]

        # rows & columns
        for i in range(9):
            self.used = [False for _ in range(9)]
            for j in range(9):
                if not self.check(board[i][j], self.used):
                    return False

            self.used = [False for _ in range(9)]
            for j in range(9):
                if not self.check(board[j][i], self.used):
                    return False

        # nine patches
        for i in range(3):
            for j in range(3):
                self.used = [False for _ in range(9)]
                for r in range(3*i, 3*i+3):
                    for c in range(3*j, 3*j+3):
                        if not self.check(board[r][c], self.used):
                            return False
        
        return True


    def check(self, ch, used) -> bool:
        if ch == '.':
            return True

        elif self.used[int(ch)-1]:
            return False
        
        else:
            self.used[int(ch)-1] = True
            return True
```
```c++ []
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 定义数字序列
        bool used[9];

        // 检查行和列
        for(int i=0; i<9; ++i){
            fill(used, used+9, false);

            // row
            for(int j=0; j<9; ++j){
                if(!check(board[i][j], used))
                    return false;
            }

            fill(used, used+9, false);
            // column
            for(int j=0; j<9; ++j){
                if(!check(board[j][i], used))
                    return false;
            }
        }

        // 检查九宫格
        for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j){
                fill(used, used+9, false);
                for(int r=i*3; r<i*3+3; ++r)
                    for(int c=j*3; c<j*3+3; ++c){
                        if(!check(board[r][c], used))
                            return false;
                    }
            }
        return true;
    }

private:
    bool check(char ch, bool used[9]){
        if(ch == '.')
            return true;
        else if(used[ch-'1'])
            return false;
        else
            used[ch-'1'] = true;
        return true;
    }
};
```