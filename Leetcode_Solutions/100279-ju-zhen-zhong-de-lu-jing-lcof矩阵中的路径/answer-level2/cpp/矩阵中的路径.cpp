### 解题思路
参考了大佬 **@Kreahets**的思路，然后用C++实现。
稍有不同在于，将矩阵和字符串声明为成员变量，不用每次递归的时候传入这两个参数。
#### 个人思路理解：
分析：首先理解好题意，题中强调每次只能走一步，也就是说某一格以及相邻格才能构成路径。
![clipboard.png](https://pic.leetcode-cn.com/bac1861b1ea7c166f946dec42ee2ce5c99d9ad81c9e793cb0360c48e5dca0de1-clipboard.png)
基本思路：要把这道题按照让机器解决问题的思路去思考。应当是先从第一个元素检索，深度优先搜索，把能走的路径走个遍，走的过程中如果当前元素符合条件，就继续朝四个方向探索，四个方向中只要有一个能走通就OK，走不通就返回false，跳到矩阵的下一个元素，继续深度优先。直到走完，如果走完还没有返回true那就说明不行，返回false。
### 以下是作者连接，膜拜大佬
作者：jyd
链接：https ://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/

### 代码

```cpp
class Solution {
public:
    vector<vector<char>> boardCopy;
    string wordCopy;
    bool exist(vector<vector<char>>& board, string word) {
        boardCopy = board;
        wordCopy = word;
        for(int i = 0 ; i<boardCopy.size() ; i++)
        {
            for(int j = 0 ; j<boardCopy[0].size() ; j++)
            {
                if(searchPath(i,j,0))
                    return true;
            }
        }
        return false;
    }
     bool searchPath(int indexRow,int indexCol,int indexWord)
     {
         if(indexRow>boardCopy.size()-1 || indexCol>boardCopy[0].size()-1 ||indexRow<0 || indexCol<0 || boardCopy[indexRow][indexCol] != wordCopy[indexWord])
            {
                return false;
            }
        if(indexWord == wordCopy.length() - 1) return true;
            char tmp = boardCopy[indexRow][indexCol];
            boardCopy[indexRow][indexCol] = '/';
            bool res = searchPath(indexRow+1,indexCol,indexWord+1) || searchPath(indexRow-1,indexCol,indexWord+1) || searchPath(indexRow,indexCol+1,indexWord+1) || searchPath(indexRow,indexCol-1,indexWord+1);
            boardCopy[indexRow][indexCol] = tmp;
            return res;
     }
};














```