# hash表实现
```
//hash表法
func totalNQueens(n int) int {
    if n==0{
        return 0
    }
    res:=0
    cols:=make(map[int]bool,0)
    pies:=make(map[int]bool,0)
    nas:=make(map[int]bool,0)
    dfs(0,n,cols,pies,nas,&res)
    return res
    
}

//rows:存放对应皇后的列的值
func dfs(row int,n int,cols,pies,nas map[int]bool,res *int){
    //出递归条件
    if row==n{
        (*res)++
        return
    }
    //每层遍历所有的列，找到满足条件的值
    for col:=0;col<n;col++{
        //判断是否会被皇后干死，干不死就是要找的皇后
        if cols[col] || pies[row+col] || nas[row-col]{
            continue
        }
        //进行占位（所谓占位，是指能被皇后攻击到的区域）
        cols[col]=true
        pies[row+col]=true
        nas[row-col]=true
        //递归执行下一层
        dfs(row+1,n,cols,pies,nas,res)
        //递归结束后要将相应占位的元素进行解放，以满足下一次调用
        //比如在第一个点是不满足的，但是将其占位了，所以要将其解开
        cols[col]=false
        pies[row+col]=false
        nas[row-col]=false
    }
}
```

# 数组实现
```
//数组表示法
func totalNQueens(n int) int {
    if n==0{
        return 0
    }
    res:=0
    cols:=make([]bool,n)
    pies:=make([]bool,2*n-1)
    nas:=make([]bool,2*n-1)
    dfs(0,n,cols,pies,nas,&res)
    return res
    
}

//rows:存放对应皇后的列的值
func dfs(row int,n int,cols,pies,nas []bool,res *int){
    //出递归条件
    if row==n{
        (*res)++
        return
    }
    //每层遍历所有的列，找到满足条件的值
    for col:=0;col<n;col++{
        //判断是否会被皇后干死，干不死就是要找的皇后
        if cols[col] || pies[row+col] || nas[n-1-(row-col)]{
            continue
        }
        //进行占位（所谓占位，是指能被皇后攻击到的区域）
        cols[col]=true
        pies[row+col]=true
        nas[n-1-(row-col)]=true
        //递归执行下一层
        dfs(row+1,n,cols,pies,nas,res)
        //递归结束后要将相应占位的元素进行解放，以满足下一次调用
        //比如在第一个点是不满足的，但是将其占位了，所以要将其解开
        cols[col]=false
        pies[row+col]=false
        nas[n-1-(row-col)]=false
    }
}

```

# 位运算实现方式一
```
//位运算表示法第一种
func totalNQueens(n int) int {
    if n==0{
        return 0
    }
    //保存结果
    res:=0
    //定义三个数，其中的每一个位表示该斜线的第几个的状态（入第七位为1，表示第七条斜线已经占有了，不能放入）
    cols,pies,nas:=0,0,0
    dfs(0,n,cols,pies,nas,&res)
    return res
    
}
//row：第几列
func dfs(row int,n int,cols,pies,nas int,res *int){
    //出递归条件
    if row==n{
        (*res)++
        return
    }
    //每层遍历所有的列，找到满足条件的值
    for col:=0;col<n;col++{
        //判断是否会被皇后干死，干不死就是要找的皇后
        pie:=row+col
        na:=n-1-(row-col)
        //读取这些bit array中第i位的值，(cols >> uint(col))：右移若干位，将相应的列值和1想与，得到该列的值
        if ((cols >> uint(col)) & 1) | ((pies >> uint(pie)) & 1) | ((nas >> uint(na)) & 1) !=0 {
            continue
        }
        //进行占位（所谓占位，是指能被皇后攻击到的区域）
        //在这里的意思（以cols为例）就是改变第i列的值，此处第i列的值都为0，将其置为1，进行设置
        cols^=(1 << uint(col))
        pies^=(1 << uint(pie))
        nas^=(1 << uint(na))
        //递归执行下一层
        dfs(row+1,n,cols,pies,nas,res)
        //递归结束后要将相应占位的元素进行解放，以满足下一次调用
        //比如在第一个点是不满足的，但是将其占位了，所以要将其解开
        //将占位元素进行解开，相当于回溯
         cols^=(1 << uint(col))
        pies^=(1 << uint(pie))
        nas^=(1 << uint(na))
    }
}
```

# 位运算实现方式二
```
//位运算表示法第二种
func totalNQueens(n int) int {
    if n==0{
        return 0
    }
    //保存结果
    res:=0
    //定义三个数，其中的每一个位表示该斜线的第几个的状态（入第七位为1，表示第七条斜线已经占有了，不能放入）
    cols,pies,nas:=0,0,0
    dfs(0,n,cols,pies,nas,&res)
    return res
    
}
//row：第几列
func dfs(row int,n int,cols,pies,nas int,res *int){
    //出递归条件
    if row==n{
        (*res)++
        return
    }
    //cols | (pies >> row) | (nas >> (n-1-row)):取并集表示所有不能走的位置,取反表示所有可以走的点
    //因为此处有32位，但我们只需要n位，所以截掉其余的位
    ok:=(^(cols | (pies >> uint(row)) | (nas >> uint(n-1-row)))) & (1 << uint(n)-1)
    //遍历这些能走的通的点
    //ok!=0:里边还有1,继续执行
    for ok!=0{
        //取ok中最后一个1(p就代表当前所取的那列)
        p:=ok & (-ok)
        //取完后，将该位清除
        ok^=p
        //进行占位（所谓占位，是指能被皇后攻击到的区域）
        //在这里的意思（以cols为例）就是改变第i列的值，此处第i列的值都为0，将其置为1，进行设置
        cols^=p
        pies^=(p << uint(row))
        nas^=(p << uint(n-1-row))
        //递归执行下一层
        dfs(row+1,n,cols,pies,nas,res)
        //递归结束后要将相应占位的元素进行解放，以满足下一次调用
        //比如在第一个点是不满足的，但是将其占位了，所以要将其解开
        //将占位元素进行解开，相当于回溯
        cols^=p
        pies^=(p << uint(row))
        nas^=(p << uint(n-1-row))
    }
}
```

# 位运算实现方式三（最终版）

```
//位运算第三种（将三个bit array 变为形式参数，那么就不用再每次将其重置了，下一次递归会自动重置）
func totalNQueens(n int) int {
    if n==0{
        return 0
    }
    //保存结果
    res:=0
    //定义三个数，其中的每一个位表示该斜线的第几个的状态（入第七位为1，表示第七条斜线已经占有了，不能放入）
    dfs(0,n,0,0,0,&res)
    return res 
}
//row：第几列
func dfs(row int,n int,cols,pies,nas int,res *int){
    //出递归条件
    if row==n{
        (*res)++
        return
    }
    //cols | (pies >> row) | (nas >> (n-1-row)):取并集表示所有不能走的位置,取反表示所有可以走的点
    //因为此处有32位，但我们只需要n位，所以截掉其余的位
    //变为形参后，每次都会重新调用，pies,nas就不需要再去移动了，
    //ok:=(^(cols | (pies >> uint(row)) | (nas >> uint(n-1-row)))) & (1 << uint(n)-1)
    ok:=(^(cols | pies  | nas)) & (1 << uint(n)-1)
    //遍历这些能走的通的点
    //ok!=0:里边还有1,继续执行
    for ok!=0{
        //取ok中最后一个1(p就代表当前所取的那列)
        p:=ok & (-ok)
        //取完后，将该位清除
        ok^=p
        //进行占位（所谓占位，是指能被皇后攻击到的区域）
        //在这里的意思（以cols为例）就是改变第i列的值，此处第i列的值都为0，将其置为1，进行设置
        //递归执行下一层
        //此时cols,pies,nas都为形参，所以当前pies，就代表当前的列所在的位置，就不需要去移动了，直接置位就行
        dfs(row+1,n,cols^p,(pies^p) >> 1,(nas^p) << 1,res)
        //递归结束后要将相应占位的元素进行解放，以满足下一次调用
        //比如在第一个点是不满足的，但是将其占位了，所以要将其解开
        //将占位元素进行解开，相当于回溯
        //此时为形参，每次递归完后会自动回溯，所以就不用手动去整理了
    }
}
```

# 位运算实现参考BITTIGER视频老师讲解，如需观看，请参考哔哩哔哩，搜索BITTIGER 八皇后与位运算问题详解
链接为：[https://www.bilibili.com/video/av50089394?from=search&seid=9778338273096318262]()
