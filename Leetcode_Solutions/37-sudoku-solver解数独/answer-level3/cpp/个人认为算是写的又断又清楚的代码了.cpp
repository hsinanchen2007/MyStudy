### 解题思路
问题的关键在于回溯怎么写，具体看我回溯部分的代码，很容易懂。
不要把这题看成二维的，看成一维的一直往后填思路会更清晰。

### 代码

```cpp
class Solution {
public:
    bool check(vector<vector<char>>& a,int x,int y,char c){
        int i,j;
        for(i=0;i<9;i++){
            if(a[x][i]==c||a[i][y]==c)return false;
        }
        for(i=x/3*3;i<x/3*3+3;i++){
            for(j=y/3*3;j<y/3*3+3;j++){
                if(a[i][j]==c)return false;
            }
        }
        return true;
    }//判断能否安放
    void solveSudoku(vector<vector<char>>& board) {
        int i,j,k=0,x,y;
        char c;
        vector<vector<char>>a=board,b=board;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(a[i][j]=='.')b[i][j]='0';
                else b[i][j]='a';//最初已填标记为a
            }
        }
        while(k<81&&k>=0){
            if(k<10)printf("%d,",k);
            i=k/9;j=k%9;//i是横坐标,j是纵坐标
            if(b[i][j]=='a')k++;
            else{
                for(c='1';c<='9';c++){
                    if(check(a,i,j,c)&&c>b[i][j]){
                        b[i][j]=a[i][j]=c;k++;
                        break;//可以安放则继续往后走
                    }
                }
                if(c>'9'){//无法安放，回溯
                    b[i][j]='0';//重置所有可以安放的情况
                    k--;
                    i=k/9;
                    j=k%9;
                    while(k>=0&&b[i][j]=='a'){
                        k--;
                        i=k/9;
                        j=k%9;
                    }//退回到初始没有填的格子
                    if(k>=0)a[i][j]='.';
                }
            }
        }
        board=a;
    }
};
```