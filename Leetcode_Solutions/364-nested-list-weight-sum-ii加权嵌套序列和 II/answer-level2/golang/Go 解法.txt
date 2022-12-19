
![image.png](https://pic.leetcode-cn.com/266763f32a6bf7dc2f521c25ac72417b0a7f039f5eaf00047b373f6c9f761db7-image.png)


```golang
func depthSumInverse(nestedList []*NestedInteger) int {
    s := map[int][]int{}
    r := 0

    S(nestedList, s, 0)

    for w, nums := range s {
        r += sum(nums) * (len(s) - w)
    }

    return r
}

func S(nestedList []*NestedInteger, s map[int][]int, w int) {
    s[w] = append(s[w], 0)

    for i := 0; i < len(nestedList); i++ {
        if nestedList[i].IsInteger() {
            s[w] = append(s[w], nestedList[i].GetInteger())
        } else {
            S(nestedList[i].GetList(), s, w + 1)
        }
    }
}

func sum(nums []int) int{
    r := 0

    for _, v := range nums {
        r += v
    }

    return r
}
```