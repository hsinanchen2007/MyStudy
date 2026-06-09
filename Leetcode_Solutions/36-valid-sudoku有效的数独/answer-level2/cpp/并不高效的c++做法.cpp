参照的官方题解
![image.png](https://pic.leetcode-cn.com/fbdf07d9fd80241c94057e4bd1484705746ece29ea55512c165d4806f4f534d1-image.png)
看了评论区大家的思路 大同小异 只不过是数据结构不一样 比如使用了多维数组而不是map
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> colomn[9];
        map<char,int> row[9];
        map<char,int> box[9];
        
        for (int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j] != '.'){
                    char a = board[i][j];
                    if(colomn[j].find(a)!=colomn[j].end())
                    {
                        return false;
                    }                
                    colomn[j][a] = 1;
                    if(row[i].find(a)!=row[i].end())
                    {
                        return false;
                    } 
                    row[i][a] = 1;
                    int b=(i/3)*3+(j/3);
                    if(box[b].find(a)!=box[b].end())
                    {
                        return false;
                    } 
                    box[b][a] = 1;
                }
            }
        }
        return true;
    }
};
```
