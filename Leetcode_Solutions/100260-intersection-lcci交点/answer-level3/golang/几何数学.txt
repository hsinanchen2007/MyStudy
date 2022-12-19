### 解题思路
向量矩阵、直线参数方程、克莱姆法则求解方程组

### 代码

```golang
func intersection(start1 []int, end1 []int, start2 []int, end2 []int) []float64 {
    const eps = 1e-6
    sub := func(a, b []int) []int {
        c := make([]int, 2)
        c[0] = a[0] - b[0]
        c[1] = a[1] - b[1]
        return c
    }
    det := func(a, b []int) int { // 行列式或叉积
        return a[0]*b[1]-a[1]*b[0]
    }
    inline := func(s, v, p []int) bool { // 检测p是否在线段 p=s+vt 上 (0<=t<=1)
        i := 0
        if v[i]==0 { i = 1 }
        t := float64((p[i]-s[i])) / float64(v[i])
        if -eps <= t && t <= 1+eps { return true }
        return false
    }
    v1 := sub(end1, start1)
    v2 := sub(end2, start2)
    b := sub(start2, start1)
    denominator := det(v1, v2)
    ans := []float64{}
    if denominator == 0 { // 平行
        if det(v1, b) == 0 { // 共线
            tmp := [][]int{start1, end1, start2, end2}
            // 排序后第二个点为候选点
            sort.Slice(tmp, func(i, j int) bool {
                if tmp[i][0] < tmp[j][0] {
                    return true
                } else if tmp[i][0]==tmp[j][0] && tmp[i][1]<tmp[j][1] {
                    return true
                }
                return false
            })
            // 检测是否同时在两线段上
            if inline(start1, v1, tmp[1]) && inline(start2, v2, tmp[1]) {
                ans = []float64{float64(tmp[1][0]), float64(tmp[1][1])}
            }
        }
    } else { // 直线相交
        t1 := float64(det(b, v2)) / float64(denominator) // p=s1+v1*t1 (0<=t1<=1)
        t2 := -float64(det(v1, b)) / float64(denominator)
        if 0<=t1&&t1<=1 && 0<=t2&&t2<=1 { // 交点是否在线段上
            ans = []float64{float64(start1[0])+float64(v1[0])*t1, 
                        float64(start1[1])+float64(v1[1])*t1}
        }
    }
    return ans
}
```