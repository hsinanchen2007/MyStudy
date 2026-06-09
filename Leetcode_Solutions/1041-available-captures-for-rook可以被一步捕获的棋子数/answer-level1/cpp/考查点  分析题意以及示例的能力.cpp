正如标题所写，这道题考查的重点，并不是多么难得算法，而是分析题意以及示例的能力。现在很多企业（阿里，美团）笔试算法题都是给一个小场景，先分析场景再去解题。如果题意和示例不能理解，则无法做题。**相较于直白的给出“反转链表”，“最大子序列和”等，这道题更考查是分析能力，所以这道题还是不错的**。
其实这道题的意思就是白色的车向四个方向分别走一次，一共可以吃掉几个卒。
思路也很简单先找到车的位置，然后按照四个方向分别模拟即可。
如果想要是程序简化，可以使用两个数组创建方向数组。
```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        if(board.empty()) return -1;
        int rows = (int) board.size();
        int clo = (int) board[0].size();
        int Rpos = -1, Cpos = -1;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j< clo; j++){
                if(board[i][j] == 'R'){
                    Rpos = i;
                    Cpos = j;
                    break;
                }
            }
            if(Rpos >-1 && Cpos > -1)  break;
        }
        int count = 0;
        //向左移动
        for(int i = Cpos -1;i >= 0; i--){
            if(board[Rpos][i] == 'p'){
                count++;
                break;
            }
            else if(board[Rpos][i] == 'B'){
                break;
            }
        }
        //向右移动
        for(int i =Cpos + 1; i<clo; i++ ){
            if(board[Rpos][i] == 'p'){
                count++;
                break;
            }
            else if(board[Rpos][i] == 'B'){
                break;
            }
        }
        //向下移动
        for( int i = Rpos + 1; i < rows;i++){
            if(board[i][Cpos] == 'p'){
                count++;
                break;
            }
            else if(board[i][Cpos] == 'B'){
                break;
            }
        }
        //向上移动
        for(int i = Rpos - 1; i >= 0; i--){
             if(board[i][Cpos] == 'p'){
                count++;
                break;
            }
            else if(board[i][Cpos] == 'B'){
                break;
            }
        }
        return count;
    }
};
```
