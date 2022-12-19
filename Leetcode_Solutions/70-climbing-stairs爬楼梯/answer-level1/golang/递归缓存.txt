### 解题思路
无非就是 斐波那契数列 ,用递归处理，切片记录之前的

### 代码

```golang
func climbStairs(n int) int {
    tmp := make([]int, n+1)
	return  robot(n,tmp)
}

func robot(n int,tmp []int)int{
    if n==0{
        return 1
    }
    if n<0{
        return 0
    }
    if tmp[n]>0{
        return tmp[n]
    }
    k:=robot(n-1,tmp)+robot(n-2,tmp)
    tmp[n]=k

    return k
}
```