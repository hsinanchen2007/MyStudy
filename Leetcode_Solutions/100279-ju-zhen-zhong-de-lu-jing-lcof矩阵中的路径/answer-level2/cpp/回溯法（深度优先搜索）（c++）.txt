1.比较学习“131、分割回文串”：
https://leetcode-cn.com/problems/palindrome-partitioning/solution/shen-du-you-xian-sou-suo-jie-fa-c-by-bike666222/
2.本题可参考：
https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
3.思路如下：
![矩阵中的路径01.jpg](https://pic.leetcode-cn.com/a33139fafa0537f5e1cddf4c3a026a8ca4ecab167e78b009285b1327b3d849ac-%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E8%B7%AF%E5%BE%8401.jpg)


```
//深度优先搜索（也可以称为回溯法）,DFS
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) { // board为给定的矩阵，word为字符串
        int rows=board.size(); // 矩阵board的行数
        int cols=board[0].size(); // 矩阵board的列数
        int num=0; // 用于记录已经识别成功的字符个数。最终用于终止条件的判别。
        vector<vector<bool>> visited(rows,vector<bool>(cols,false)); // 标记该字符在这条路径上是否已经访问过，
                                                                     // 未访问记为false，初始化全部为false。
        bool symbol=false,symbol01; // 可改进的地方一。直接“return true;”或者“return false;”,可省去这两个参数
        for(int i=0;i<rows;i++){ // 使用两个for循环，进行暴力搜索，按顺序对每一个字符进行访问
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    num++; // 可改进的地方二。使用“dfs(..., num+1 ,...)”，可避免num多次加减，如下文代码"num+1"
                    visited[i][j]=true; // 可改进的地方三。在进行下一次深度遍历前先将当前已经访问过的字符替换成
                                        // 非字母字符，如"char tmp = board[i][j]; board[i][j] = '.';"；深度
                                        // 遍历之后改回来，如"board[i][j] = tmp;"
                    symbol01=dfs(board,word,i,j,num,rows,cols,visited);
                    visited[i][j]=false;
                    num--;
                    if(symbol01) symbol=symbol01;
                }
            }
        }
        return symbol;
    }

    bool dfs(vector<vector<char>> &board,string word,int i,int j,int num,int rows,int cols,vector<vector<bool>> &visited){
        if(num==word.length()){ // 终止条件：长度与给定的字符串长度相等，则说明存在路径，返回true
            return true;
        }

        // 可改进的地方四：下面四个if语句用于遍历字符board[i][j]的“左右上下”四个方位的字符
        if(j-1>=0&&visited[i][j-1]==false){ // 字符board[i][j]左边的字符，并且这个字符未访问过时
            if(board[i][j-1]==word[num]){ // 并且这个字符等于所给的字符串的对应字符时
                num++;
                visited[i][j-1]=true;
                if(dfs(board,word,i,j-1,num,rows,cols,visited)) return true;
                visited[i][j-1]=false;
                num--;
            }
        }

        if(j+1<=cols-1&&visited[i][j+1]==false){ // 右边字符
            if(board[i][j+1]==word[num]){
                num++;
                visited[i][j+1]=true;
                if(dfs(board,word,i,j+1,num,rows,cols,visited)) return true;
                visited[i][j+1]=false;
                num--;
            }
        }

        if(i-1>=0&&visited[i-1][j]==false){ // 上面的字符
            if(board[i-1][j]==word[num]){
                num++;
                visited[i-1][j]=true;
                if(dfs(board,word,i-1,j,num,rows,cols,visited)) return true;
                visited[i-1][j]=false;
                num--;
            }
        }

        if(i+1<=rows-1&&visited[i+1][j]==false){ // 下面的字符
            if(board[i+1][j]==word[num]){
                num++;
                visited[i+1][j]=true;
                if(dfs(board,word,i+1,j,num,rows,cols,visited)) return true;
                visited[i+1][j]=false;
                num--;
            }
        }

        return false; // 上面都未返回true时，默认返回false。必须有
        
    }
};
```
改进：
"""
参考：
作者：Hanwn
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/shen-sou-hui-su-by-hanwn/
"""

![矩阵中的路径02.jpg](https://pic.leetcode-cn.com/b643f39dfee9dec91d7e0b19366a5687d8c303d996d101566b73e3d1db68ca3c-%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E8%B7%AF%E5%BE%8402.jpg)


```
class Solution {
public:
    int x[4] = {0,0,-1,1}; //x[4]、y[4]和dfs中for循环，共同构成遍历字符board[i][j]的“左右上下”四个字符这一功能
    int y[4] = {-1,1,0,0}; // 这里用的特别巧妙
    int rows,cols;
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int num) {
        if (num == word.size()) return true;
        char tmp = board[i][j]; // 用于暂时保存字符
        board[i][j] = '.'; // 代表这个字符已经访问过
        for (int k = 0; k < 4; k++) {
            int d_x = x[k] + i; // 新的i值
            int d_y = y[k] + j; // 新的j值
            if (d_x >= 0 && d_x < rows && d_y >= 0 && d_y < cols && word[num] == board[d_x][d_y]) {
                if (dfs(board,word,d_x,d_y,num + 1)) return true;
            }
        }
        board[i][j] = tmp; // 遍历结束后改回来
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board,word,i,j,1)) return true;
                }
            }
        }
        return false;
    }
};
```
下面是更简洁的代码：（但是消耗的内存是上面的8倍，时间是上面的6倍）
 --- “先判断是否需要遍历，需要再遍历”比“先进行遍历，再判断”明显节省时间。
```
class Solution {
public:
    int rows,cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        if(board.size()<1 || word.size()<1 || rows<1 || cols<1) return false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board,string word,int i,int j,int num){
        if(i>=0 && i<rows && j>=0 && j<cols && board[i][j]==word[num]){
            num++;
            if(num==word.size()) return true;
            char tmp=board[i][j];
            board[i][j]='.';
            if(dfs(board,word,i,j-1,num) || dfs(board,word,i,j+1,num) || dfs(board,word,i-1,j,num) || dfs(board,word,i+1,j,num)) return true;
            board[i][j]=tmp;
            num--;
        }
        return false;
    }
};
```
