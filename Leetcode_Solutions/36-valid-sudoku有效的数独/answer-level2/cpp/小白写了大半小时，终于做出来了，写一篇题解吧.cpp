### 解题思路
![image.png](https://pic.leetcode-cn.com/3d2cba2b846fc0b66be5e5113d20711cc54d3bd0947da8412b491fd53bffe739-image.png)
### 按照题目要求：
1. 行无重复
2. 列无重复
3. 九宫格可分为九个小块，每个小块中无重复
#### 对于行和列的重复检验，都可以建立一个9*9的二维数组；
例如对行的检验，建立数组 x[9][9]，对于board[i][j],该位置储存的值为k(1~9)
就应该保证第i行不应该再次出现k，所以可将x[i][k-1]++，如此，如果board的i行要是还出现k值，x[i][k-1]>1，return false；
同理，要保证j行不再出现k，y[k-1][j]++，当y[k-1][j]>1，return false；
#### 对于九宫格中的九个小块，如何保证归属于该块区域的board[i][j]，储存的值k，能够映射到对应的格子位置，保证其出现的唯一性。
num=k-1
横坐标：num/3+(i/3)*3
纵坐标：num%3+(j/3)*3
0 1 2
3 4 5
6 **7** 8
look，如果知道num，那么num/3就是在这个小格子的内的横坐标，num%3则是纵坐标。举例7/3=2，7%3=1，在这个格子里坐标就是[2,1]
那么如何确定是在九块格子中的哪一个格子里呢？
(i/3)*3 确定了格子的起始横坐标
(j/3)*3  确定了格子的起始纵坐标

对于对应该块格子区域内的每个元素，最终映射的就是该块格子区域的九个位子。

官方解答是将，该格子区域的每个元素，最终映射到每一行上。

区别就是：格子——>格子
         格子——>行

https://leetcode-cn.com/problems/valid-sudoku/solution/java-wei-yun-suan-xiang-jie-miao-dong-zuo-biao-bia/
刚刚突然发现关于分块，这个大佬讲的好细致，图文并茂，给大佬点赞，转发。
### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int x[9][9]={0};
        int y[9][9]={0};
        int chunk[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    x[i][num]++;
                    y[num][j]++;
                    chunk[num/3+(i/3)*3][num%3+(j/3)*3]++;
                    if(x[i][num]>1||y[num][j]>1|| chunk[num/3+(i/3)*3][num%3+(j/3)*3]>1) return false;
                }

            }   
        }
        return true;
    }
};
```