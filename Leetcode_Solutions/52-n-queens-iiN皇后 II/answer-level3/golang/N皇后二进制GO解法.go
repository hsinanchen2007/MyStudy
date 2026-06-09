### 解题思路
续N皇后1 
取N=4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
先取出没有被皇后占用的格子
bits 第一次为  15    1111   4个1
每次取出最后一个1
```
for bits>0{
    //四个位置 都放了queen dfs
    //第一个1  对col pies nas 变化
    col = 1     //0001
    pies = 1<<1 //0010
    nas = 1>>1  //0000
    //放到下一层继续 每一层循环
    //第二层
    bits = ^(0001|0010|0000) = 000..0001100
    //取第一个1
    bit = 0100 //4
    col = 0100|0001 //0101
    pies =0100|0010 <<1 //0110-->1100 
    nas = 0100|0000 >>1 //0100-->0010
    //放到下一层继续 每一层循环
    //第三层
    bits = ^(0101|1100|0010)  0000
    //没有地方可以放了

    //第二个放queen的位置 也走一次这个流程
    //最后结束条件 row可以大于n即有解
}
```
### 代码

```golang
func totalNQueens(n int) int {
    if n < 0 {
        return 0
    }
    count := 0
    _dfs(n,0,0,0,0,&count)
    return count
}

func _dfs(n int,row int,cols int,pies int ,nas int ,count *int){
    if row >= n{
        (*count)++
        return
    }
    //0100
    //0010
    //1000
    //左边 是获得所有没有被皇后占位置的位置 取非把0变1  //右边是筛子 00..001111 假设n=4 一与就获得了所有1的位置 从二进制来看
    bits := (^(cols|pies|nas)) & (1<<n -1)
    fmt.Println(bits)
    for bits > 0{
        //取出第一个bit
        p := bits & (-bits)
        _dfs(n,row+1,(cols|p),(pies|p)<<1,(nas|p)>>1,count)
        bits = bits&(bits-1)
    }
    
}
```