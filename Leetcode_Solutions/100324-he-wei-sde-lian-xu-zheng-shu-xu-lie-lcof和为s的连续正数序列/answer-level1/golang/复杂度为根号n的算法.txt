根据`N = k(2x+k-1)/2`，而k<2x+k-1所以我们只有遍历根号target的数就行了。
而target - i * (i - 1) / 2 = ki，k为其中的起点，i为项数，所以前半部分能被i整除的时候就是满足条件的时候，此时就可以计算出k值，加入slice res就行。

```go
func findContinuousSequence(target int) [][]int {
    res := make([][]int, 0)
    for i:=int(math.Sqrt(float64(2*target))); i>=2; i-- {
        judge := target - i * (i - 1) / 2
        if judge % i == 0 {
            begin := judge / i
            temp := make([]int, 0)
            for j:=0; j<i; j++ {
                temp = append(temp, begin+j)
            }
            res = append(res, temp)
        }
    }
    return res
}
```

![Jietu20200302-204748@2x.jpg](https://pic.leetcode-cn.com/ff28c8c7a2d7d599adbe68214fa0affb3a97579ad6ff27fda7caa373d707516d-Jietu20200302-204748@2x.jpg)
