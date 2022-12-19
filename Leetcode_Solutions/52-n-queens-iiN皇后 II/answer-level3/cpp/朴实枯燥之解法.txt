## N皇后
### 问题描述
n 皇后问题研究的是如何将n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
[![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)
上图为 8 皇后问题的一种解法

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
![](https://pic.leetcode-cn.com/883a9bf9d5effefb4f4147e88a625ce83abf7cee9d648d1affd70e856fb4eed5.png)
[Ｎ皇后](https://leetcode-cn.com/problems/n-queens/ "Ｎ皇后")
### 解决方法
#### 回溯法

注释写的比较多，代码就可以看的懂

```cpp
class Solution {
public:
    vector<vector<string>> res;
    //检查该位置是否可以放置Q，判断的时候不需要全局，只需要查看前x行即可
    bool check(vector<string>& temp,int x,int y,int n){
        int _x=x, _y=y;
        //向上查找
        while(_x>=0){
            if(temp[_x][_y]=='Q')return false;
            --_x;
        }
        _x=x;
        //左上查找
        while(_x>=0 && _y>=0){
            if(temp[_x][_y]=='Q')return false;
            --_x,--_y;
        }
        _x=x,_y=y;
        //右上查找
        while(_x>=0 && _y<n){
            if(temp[_x][_y]=='Q')return false;
            --_x,++_y;
        }
        return true;
    }
    //dfs,只有行数增加即可
    void helper(vector<string>& temp, int n, int x){
        if(x==n){
            res.push_back(temp);
            return ;
        }
        //判断该行的每列是否可以放置Q
        for(int j=0;j<n;j++){
            if(check(temp,x,j,n)){
                temp[x][j]='Q';
                helper(temp,n,x+1);
                temp[x][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string t;
        for(int i=0;i<n;i++){
            t+='.';
        }
        vector<string>temp(n,t);
        helper(temp,n,0);
        return res;
        
    }
};
```


## N皇后II
### 问题描述
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
[![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)
上图为 8 皇后问题的一种解法

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

![](https://pic.leetcode-cn.com/c23ad351454988e33ba36181e71e60c8669cef79345d52195b240eaa68fd92f9.png)
[Ｎ皇后II](https://leetcode-cn.com/problems/n-queens-ii/ "Ｎ皇后II")
### 解决方法
####　回溯
与Ｎ皇后基本一样

```cpp
class Solution {
public:
    int res=0;
    //检查该位置是否可以放置Q
    bool check(vector<string>& temp,int x,int y,int n){
        int _x=x, _y=y;
        //向上查找
        while(_x>=0){
            if(temp[_x][_y]=='Q')return false;
            --_x;
        }
        _x=x;
        //左上查找
        while(_x>=0 && _y>=0){
            if(temp[_x][_y]=='Q')return false;
            --_x,--_y;
        }
        _x=x,_y=y;
        //右上查找
        while(_x>=0 && _y<n){
            if(temp[_x][_y]=='Q')return false;
            --_x,++_y;
        }
        return true;
    }

    int flag=0;
    void helper(vector<string>& temp, int n, int x){
        if(x==n){
            res++;
            return ;
        }
        for(int j=0;j<n;j++){
            if(check(temp,x,j,n)){
                temp[x][j]='Q';
                helper(temp,n,x+1);
                temp[x][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        string t;
        for(int i=0;i<n;i++){
            t+='.';
        }
        vector<string>temp(n,t);
        helper(temp,n,0);
        return res;
    }
};
```

个人小站：[https://liyiping.cn](https://liyiping.cn)