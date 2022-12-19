### 解题思路
此处撰写解题思路

### 代码
#### 1. 暴力法
```golang
func countBits(num int) []int {
    var res []int
    for i := 0 ;i <= num ; i ++ {
        c := getCount(i)
        fmt.Println(i,c)
        res = append(res,c)
    }  
    return res
}
func getCount(num int)int{
    h := 1
    sum := 0
    for i :=0 ; i< 32; i ++ {
        if (num & h)   == h {
            sum += 1
        }
        h = h << 1
    }
    return sum
}
```
#### 2. 来自于楼主分享  借鉴说明一下
公式为  `p(x) = p(x/2) + x mode 2` 拆解如下:
x/2 = x >> 1

x mode 2 :存在这样的公式转换
>a % (2^n) == a & (2^n -1)  = > x & 1
```golang
func countBits(num int) []int {
    ret:=make([]int,num+1)
    for i:=1;i<=num;i++{
        ret[i]=ret[i>>1]+i&1
    }
    return ret
}

```