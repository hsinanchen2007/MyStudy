

## 题目讲解
**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 深搜

**【思路】**
* 遍历`board[][]`数组，找到与`word`第一个字母相同位置，这是深搜的起点
* `start`存储`word`中要对比字母的序号，依次做`+1`操作
* 用`int[][] map={{1,0},{0,1},{-1,0},{0,-1}}`，表示下一个要遍历的方向
* 用` flag`存储已经遍历过的结点
* 遍历新的4个方向，若`board[iNew][jNew]==words[start]`，则`start++`，并继续深搜
* 若没有找到，则跳到第一步继续运行，直到找到为止


**【备注】**
* 要注意判断当前是否超出`board[][]`的范围，即`iNew>=0 && iNew<board.length && jNew>=0 && jNew<board[0].length`


**【代码】**
```java
public boolean exist(char[][] board, String word) {
    char[] words=word.toCharArray();
    boolean[][] flag=new boolean[board.length][board[0].length];
    for(int i=0;i<board.length;i++){
        for(int j=0;j<board[0].length;j++){
            if(board[i][j]==words[0]) {
                flag[i][j]=true;
                if(help(board,i,j,words,1,flag))
                    return true;
                flag[i][j]=false;
            }
        }
    }
    return false;
}

boolean help(char[][] board,int i,int j,char[] words,int start,boolean[][] flag){
    if(start>=words.length)
        return true;
    int[][] map={{1,0},{0,1},{-1,0},{0,-1}};
    for(int n=0;n<4;n++){
        int iNew=i+map[n][0];
        int jNew=j+map[n][1];

        if(iNew>=0 && iNew<board.length && jNew>=0 && jNew<board[0].length &&
                board[iNew][jNew]==words[start] && !flag[iNew][jNew]){
            flag[iNew][jNew]=true;
            if(help(board,iNew,jNew,words,start+1,flag))
                return true;
            flag[iNew][jNew]=false;
        }
    }
    return false;
}
```
**【备注】**
* 关注微信公众号“算法岗从零到无穷”，更多算法知识点告诉你。
![logo_gif.gif](https://pic.leetcode-cn.com/944ec510231fb196c8f26d59edf7f64c6e433804c3a43afd7a7b660e0ca7d2ca-logo_gif.gif)



