### 解题思路
执行用时 :24 ms, 在所有 C++ 提交中击败了39.26%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了45.94%的用户

经典的回溯问题，数独
做法如下。
先保存所有未填入数字的位置（这一步是否可以省去，我还没想到），然后在调用函数，对未填入数字的位置赋值
从1开始，如果赋值有效（如何有效，下面会讲），则递归调用该函数，进行下一个位置的赋值；
如果赋值无效，则继续循环，到2，到3，4，5，6，7，8，9；
如果1到9都试过了，都无效，就将该位置的值赋为'.'（这一步且不可忘记） ，然后就返回false（这是回溯的关键，通过返回false回到上一层递归）

当所有填入的位置都填过且都有效，那么算法就已经结束了，返回true即可，所有递归层都会返回true

那么怎么判断填入的数字是否有效呢？
1、所填入的位置的横纵方向所有元素（除了所填入位置本身）都与所填入的数字不冲突（不相等）
这一步判断用一个循环就可以完成。
2、子棋盘内的所有元素（除了所填入位置本身）都与所填入的数字不冲突（不相等）
什么是子棋盘呢，就是用粗线分割开的小棋盘。
我们将子棋盘从左到右编号
0 1 2
3 4 5
6 7 8
（有点抽象，多理解理解）
然后判断所填入位置在哪个子棋盘，接着遍历该子棋盘的所有位置即可
这一步在代码里面有写，利用乘除和取余，灵活的计算
接下来就放代码吧，程序效率不高，还有待提高，希望大佬们多提意见。

### 代码

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> empty;//用来保存所有未填入数字的位置
        empty.clear();
        for(int i =0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if(board[i][j]=='.')//如果位置(i,j)未被填入数字
                {
                    empty.push_back(make_pair(i,j));//添加位置(i,j)
                }
            }
        }
        theSolution(0,empty,board);//调用函数
    }
    bool theSolution(int num,vector<pair<int,int>> &empty,vector<vector<char>>& board)
    {   
        /*
            num的含义是第(num+1)个需要填入数字的位置
            empty包含所有未填入数字的位置
            board是棋盘本身
        */
        if (num == empty.size())//如果所有的位置都填完，则返回true。算法已经结束，所有递归套用都返回true
            return true;
        bool wrong1 = false;//第一个判断：填入的位置的横纵2个方向的所有元素是否与填入的元素冲突
        bool wrong2 = false;//第一个判断：填入的位置在9*9的棋盘中的第几个3*3的子棋盘中的所有元素是否与填入元素冲突
        int block;
        for (int i = 1; i < 10; i++)//要填入的数字，从1到10
        {
            wrong1 = false;
            char ppp= i + '0';//将数字转化为char类型
            board[empty[num].first][empty[num].second] =ppp;
            for (int j = 0; j < 9; j++)//遍历填入的位置的横纵2个方向的所有元素
            {
                if ( j != empty[num].first && board[j][empty[num].second] == ppp || j != empty[num].second && board[empty[num].first][j] == ppp)//第一个判断出错
                { 
                    wrong1 = true;//第一个判断出错
                    break;
                }
            }
            if (!wrong1)//如果第一个判断没错
            {
                block = empty[num].first / 3 + empty[num].second / 3 * 3;//填入的位置在9*9的棋盘中的第几个3*3的子棋盘
                wrong2 = false;
                for (int j = (block * 3) % 9; j < (block * 3) % 9 + 3; j++)//遍历子棋盘内的元素
                {
                    for (int k = (block / 3) * 3; k < (block / 3) * 3 + 3; k++)
                    {
                        if (j == empty[num].first && k == empty[num].second)//跳过填入的位置
                            continue;
                        if (board[j][k] == ppp)//第二个判断出错
                        {
                            wrong2 = true;//第二个判断出错
                            break;
                        }
                    }
                    if (wrong2)
                        break;
                }
                if (!wrong2)//如果第二个判断没错（两个判断都没错）
                {
                    if (theSolution(num + 1, empty, board))//递归调用下一个未被填入的位置，如果返回false，则继续进行循环
                        return true;
                }
            }
        }
        board[empty[num].first][empty[num].second] = '.';//填入的位置填入1，2，3，4，5，6，7，8，9都不行，则返回false
        return false;
    }
};
```