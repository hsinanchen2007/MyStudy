1. 排序，也可以用map，排序相对简洁。复杂度：nlog(n)
2. 扫描找到个数最大的数X。复杂度：n
3. 将排序好的数列看成一个二维数组，宽度为X的个数，X必须排在第一行，通过竖扫描生成新数组即可。复杂度：n

```
import (
    "sort"
)

func rearrangeBarcodes(barcodes []int) []int {
    sort.Ints(barcodes)

    tlen := len(barcodes)

    mlen := 0
    mvar := 0
    mpos := -1

    v := 0
    l := 0
    p := -1
    for i, c := range barcodes {
        if v != c {
            if mlen < l {
                mlen = l
                mvar = v
                mpos = p
            }
            v = c
            l = 1
            p = i
        } else {
            l++
        }
    }
    if mlen < l {
        mlen = l
        mvar = v
        mpos = p
    }

    ret := make([]int, tlen)
    k := 0

    for i:=0; i<mlen; i++ {
        for j:=0; i+j*mlen<tlen; j++ {
            pos := i + j*mlen
            if pos < mlen {
                ret[k] = mvar
            } else if pos < mpos + mlen {
                ret[k] = barcodes[pos-mlen]
            } else {
                ret[k] = barcodes[pos]
            }
            k++
        }
    }

    return ret
}
```
