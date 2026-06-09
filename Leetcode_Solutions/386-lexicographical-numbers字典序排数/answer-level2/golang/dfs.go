### 解题思路
dfs

### 代码

```golang

func lexicalOrder(n int) []int {
    ret := make([]int,0,n)
    for i:=1;i<10;i++{
        if i <= n {
            ret = append(ret,i)
            help(i,n,&ret)
        }
    }
    return ret
}

//dfs
func help(start int,val int,ret *[]int){
    for i:=0;i<10;i++{
        t := start*10 + i
        if t <= val{
            *ret = append(*ret,t)
            help(t,val,ret)
        }
    }
}


```