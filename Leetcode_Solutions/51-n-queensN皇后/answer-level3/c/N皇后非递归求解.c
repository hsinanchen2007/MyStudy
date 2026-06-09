### 解题思路
采用非递归的方法，思路其实很简单，利用回溯法层层回溯，记录本题主要是因为在思路实现出现了一写困难。详情请看注释
### 代码

```cpp
class Solution {
private: int  q[30]; //记录每一行皇后的位置
         const int INIT=1000;
public:
    bool valid(int row,int col){//判断第row行第col列是否可以放皇后
        for(int i=0;i<row;++i){
            if(q[i]==col||abs(row-i)==abs(q[i]-col))//q[i]存放的是第i行皇后的位置。后面的语句用来判断是否在对角线上。
            return false;
        }
        return true;
    }
    void print(int n,vector<vector<string>> &v){//将一个解存放在v里面
        vector<string> s;
        string tmp;
        for(int i=0;i<n;++i)
        tmp.push_back('.');
        for(int i=0;i<n;++i)
        s.push_back(tmp);
        for(int i=0;i<n;++i)
        s[i][q[i]]='Q';
        v.push_back(s);
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<30;++i){//初始化，注意这里最好不要用memest()函数。详情参将[http://www.cplusplus.com/reference/cstring/memset/](memset的用法)
            q[i]=INIT;
        }
        vector<vector<string>> v;
        int row=0;
        int col=0;
        while(row<n){
            while(col<n){
                if(valid(row,col)){//如果该位置可以放皇后
                    q[row]=col;   //记录位置
                    col=0;  //下一行的第一列
                    break;
                }
                else{  //不可以放皇后列数加1
                    col++;
                }
            }
            if(q[row]==INIT){  //如果第row不能放皇后，则要向前回溯。
                if(row==0)//如果回溯到0，则退出
                break;
                row--; //回溯到上一行
                col=q[row]+1; //从第q[row]+1列判断
                q[row]=INIT; //将回溯的那一行的列值初始化
                continue;
            }
            if(row==n-1){//如果到达最后一行，则说明找到了一个解
                print(n,v); //保存一个解
                col=q[row]+1;  //查看下一列
                q[row]=INIT;  //同上
                continue;
            }
            row++;  //判断下一行
        }
        return v;
    }
};
```