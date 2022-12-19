### 解题思路
模拟矩阵旋转的方式，可以解决这一题，保证每次走一步，这一步如何走，就成了解决此问题的关键。
这一步可走的范围是二维的，可以定义两个数组，dr：代表横向走，dc：代表竖向走，下一步的坐标r，c可以用dr，dc表示出来
由于存在旋转问题，所以还需要一个控制方向的变量di。具体代码如下。

### 代码

```golang
//模拟矩阵旋转的方法输出
func spiralOrder(matrix [][]int) []int {
    if len(matrix)==0{
        return []int{}
    }

    res:=[]int{}
    row:=len(matrix)
    col:=len(matrix[0])
    r,c,di:=0,0,0
    dr:=[4]int{0,1,0,-1}
    dc:=[4]int{1,0,-1,0}

    screen:=make([][]bool,row)
    for i,_:=range screen{
        screen[i]=make([]bool,col)
    }

    for i:=0;i<row*col;i++{
        screen[r][c]=true
        res=append(res,matrix[r][c])
        //1 预期下一步坐标
        cr,cc:=r+dr[di],c+dc[di]    
        //2 判断下一步坐标是否合理
        //2.1 合理直接走到下一步，即给r，c赋值
        if (cr>=0 && cr<row) && (cc>=0 && cc<col) && (!screen[cr][cc]){
            r,c=cr,cc
        }else{ //2.2 不合理，则旋转方向，再走到下一步
            di=(di+1)%4
            r,c=r+dr[di],c+dc[di]
        }
    }
    return res
}
```