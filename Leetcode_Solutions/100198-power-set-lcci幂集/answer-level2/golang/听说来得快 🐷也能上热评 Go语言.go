原理是离散数学中集合的部分 就是幂集的每个元素在原始集合中的位置刚好于某个二进制位数一一对应 于是可以通过掩码判断是否在这位上 如果在 那就append进相应的切片中

```
func subsets(ns []int) (ans [][]int) {
    len := len(ns)
    count := 1 << len // 获取2^n这个个数常量
    for n := 0; n < count; n++ { // 外循环对应产生的数字
        ans = append(ans, []int{})
        for mask, i := 1, len-1; mask < count; mask, i = mask<<1, i-1 { // 里循环对应集合长度 并按位取值
            if (n & mask) != 0 { // 如果非0 那么表示这位上有 然后加之
                ans[n] = append(ans[n], ns[i])
            }
        }
    }
    return 
}
```

好了 点赞吧
