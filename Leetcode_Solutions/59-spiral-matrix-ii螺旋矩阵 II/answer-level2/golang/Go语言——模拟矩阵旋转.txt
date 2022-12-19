### 解题思路
本题和 matrix spiral print 题的思路类似，只是相当于那道题的逆运算，比较简单的思路是模拟矩阵螺旋变化。
思路：
    1.申请两个切片：res：用于记录返回值，state用于标志是否走过
    2 定义两个方向row和col,定义一个"行走的步子"di，根据row,col,di可以确定下一步该怎么走
    3.开始模拟螺旋变化  
        3.1 r，c为当前坐标，cr，cc为下一步的坐标，先预更新下一步的坐标，判断cr，cc是否到了边界
        3.2 如果不处于边界，则按原来的di继续走
        3.3 如果处于边界，则改变di，即调整前进方向，再走
        3.4 每走一步更新计数态cnt

### 代码

```golang
func generateMatrix(n int) [][]int {
    if n==0{
        return [][]int{}
    }
    //1 申请两个切片
    res:=make([][]int,n)
    state:=make([][]bool,n)
    cnt:=1
    for i:=0;i<n;i++{
        res[i]=make([]int,n)
    }
    for i:=0;i<n;i++{
        state[i]=make([]bool,n)
    }
    //2 定义前进方式
    row:=[]int{0,1,0,-1}
    col:=[]int{1,0,-1,0}
    c,r,di:=0,0,0
    cnt=1
    //3 开始模拟
    for cnt<=n*n{
        res[r][c]=cnt
        cnt++
        //3.1 预更新下一步坐标
        cr:=r+row[di]
        cc:=c+col[di]
        //3.2 如果不处于边界，按原步伐走
        if (cr>=0 && cr<n) && (cc>=0 && cc<n) && (!state[cr][cc]) {
            state[r][c]=true
            r,c=cr,cc           
        }else{//3.3 如果处于边界，更新方向，di不断循环加1
            di=(di+1)%4
            r,c=r+row[di],c+col[di]
        }
    }
    return res
}
```