### [https://mojotv.cn/go/golang-torrent](https://mojotv.cn/go/golang-torrent)


### 代码

```golang
func subtractProductAndSum(n int) int {
    s := 0
    m := 1
    for n > 0 {
        r := n % 10
        n = n/10
        //fmt.Println(r)
        m *= r
        s += r
    }
    return m-s
    
}
```