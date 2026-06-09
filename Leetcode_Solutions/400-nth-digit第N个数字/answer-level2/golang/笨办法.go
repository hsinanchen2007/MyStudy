![image.png](https://pic.leetcode-cn.com/7a8c9f52a838fcae671eb686d06edfb6b72422c41a3872a7381a058544741f15-image.png)
# 思路
1.按位数找到目标位的数字的位数,比如s是9,99,999还是其他.
2.将多余的数去掉,找到该位在哪个数上,比如ds.
3.在ds上找,具体是第几位.
```
func findNthDigit(n int) int {
    l := 0
    s := 0
    ds := 0
    tmp := 9
    for s<n {
        s += tmp*(l+1)
        ds += tmp
        l++
        tmp *= 10
    }
    d := (s-n)/l
    ds -= d
    let := l-(n-(s-(d+1)*l)-1)
    //fmt.Println(l, s, ds, d, let)
    for ds>0 && let>1 {
        ds /= 10
        let--
    }
    //fmt.Println(ds, let)
    return ds % 10
}
```
