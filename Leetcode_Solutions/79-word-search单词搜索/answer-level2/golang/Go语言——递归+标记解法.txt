### 解题思路
从每个位置处开始向右，下，左，上四个方向搜索，这个位置没有找到，走到下一个位置，继续重复上面的过程。本题的递归部分在锁定一个字母，然后以这个字母为起点向右下左上四个方向做搜索部分，当board中所有位置都没有找到指定的单词，才代表未找到单词。
算法思路：
1. 初始化一个标记数组maked
2. 遍历board中的每一个元素，以此为起点进行递归搜索
3. 接下来是递归部分
    3.1 先指定递归结束条件——找到指定单词
    3.2 将board中的坐标点在maked中标记已经走过
    3.3 遍历direction中的方向，进行递归.注意:这里不能直接更新x,y的值，因为点(x,y)是起始点，若果向右(或其他方向)没有找到，本层递归函数结束，应该还能回到起始点(x,y).继续向其他三个方向搜索。也就是说点(x,y)的更新是在外层循环遍历时更新的，不是在递归函数中更新。
    3.4 如果找到了单词，立即结束，在这里递归函数也跟着终止了
    3.5 将maked复原

small tips：
1. 在二维数组中，经常需要定义一个上下左后四个方向的二维数组，如本题中的direction。这样在后面的搜索中很方便。
### 代码

```golang
func exist(board [][]byte, word string) bool {
    if len(board)<=0{
        return false
    }

    row:=len(board)
    col:=len(board[0])
    //1. 初始化一个标记数组maked
    maked:=make([][]bool,row)
    for i:=0;i<row;i++{
        maked[i]=make([]bool,col)
    }
    //2. 遍历board中的每一个元素，以此为起点进行递归搜索
    for i:=0;i<row;i++{
        for j:=0;j<col;j++{
            if backTrace(board,word,0,i,j,row,col,maked){
                return true
            }
        }
    }

    return false
}

var direction=[4][2]int{{0,1},{1,0},{0,-1},{-1,0}}
//3. 接下来是递归部分
func backTrace(board [][]byte,word string,index int,x int,y int,row int,col int,maked [][]bool)bool{
    //3.1 先指定递归结束条件——找到指定单词
    if len(word)-1 == index{
        return board[x][y]==word[index]
    }

    if board[x][y]==word[index]{
        //3.2 将board中的坐标点在maked中标记已经走过
        maked[x][y]=true
        //3.3 遍历direction中的方向，进行递归.
        for _,d := range direction{
            nx,ny:=x+d[0],y+d[1]
            if (nx>=0 && nx<row) && (ny>=0 && ny<col) && (!maked[nx][ny]){
                //3.4 如果找到了单词，立即结束，在这里递归函数也跟着终止了
                if backTrace(board,word,index+1,nx,ny,row,col,maked){
                    return true
                }
            }
        }
        //3.5 将maked复原
        maked[x][y]=false
    }
    return false
}
```