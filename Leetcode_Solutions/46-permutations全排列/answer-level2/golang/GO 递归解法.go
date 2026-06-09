![image.png](https://pic.leetcode-cn.com/15ba65ec38b19d76b25426d854c9059208f14a43dc64287d3386a338ccc6e2fb-image.png)


### 代码

```golang
func permute(nums []int) [][]int {
    r := [][]int{}
    S(nums, []int{}, &r)

    return r
}

func S(nums, t []int, r *[][]int) {
    l := len(nums)

    if l == 0 {
        *r = append(*r, t)
        return
    }

    for i := 0; i < l; i++ {
        a := make([]int, l)
        copy(a, nums)

        c := make([]int, len(t))
        copy(c, t)

        c = append(c, a[i])
        S(append(a[:i], a[i + 1:]...), c, r)
    }
}
```