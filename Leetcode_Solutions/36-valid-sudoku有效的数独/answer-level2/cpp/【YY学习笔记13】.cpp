
### 解题思路
整体思路为：先按行排查，再按列排查，最后按3*3排查。具体实现采用了辅助数组a[10]来统计0-9出现的次数，若a[x]>1，则返回false。
### 知识点
for(int i=0;i<9;**i=i+3**),今天就被这个i=i+3坑了20分钟：我之前写成了for(int i=0;i<9;i+3)，这样其实是错误的，区别如下：
**前者相当于**
```
while(i<9){
......
i=i+3;
}
```
**后者相当于**
```
while(i<9){
......
i+3;
}
```
所以后者就一直循环不出去，导致超时。
### 感悟
今天这道题调试前前后后得有30min，最终发现是这么可笑一个错误，基础知识不牢固。
### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //先按照行排查
        for(int i=0;i<9;++i){
            int a[10]={0,0,0,0,0,0,0,0,0,0};
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                a[board[i][j]-'0']+=1;
                if(a[board[i][j]-'0']>1) return false;
            }
        }
        //按列排查
        for(int j=0;j<9;++j){
            int a[10]={0,0,0,0,0,0,0,0,0,0};
            for(int i=0;i<9;++i){
                if(board[i][j]=='.') continue;
                a[board[i][j]-'0']+=1;
                if(a[board[i][j]-'0']>1)return false;
            }
        }
        //按照3*3排查
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                int a[10]={0,0,0,0,0,0,0,0,0,0};
                for(int x=i;x<i+3;x++){
                  for(int y=j;y<j+3;y++){  
                    if(board[x][y]=='.') continue;
                    a[board[x][y]-'0']+=1;
                    if(a[board[x][y]-'0']>1)return false;
                  }  
                }
            }
        }
        return true;
    }
};
```