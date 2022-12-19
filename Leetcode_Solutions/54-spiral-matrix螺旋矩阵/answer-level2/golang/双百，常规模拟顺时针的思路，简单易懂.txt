```
func spiralOrder(matrix [][]int) []int {
    res := []int{}

    height := len(matrix)
    if height == 0 {
        return res
    }
    width := len(matrix[0])
    if width == 0 {
        return res
    }

    l, r, t, b := 0, 0, 0, 0
    order := 1 // 1往右 2往下 3往左 4往上
    for l+r < width && t + b < height {
        if order == 1 {
            for i:=l; i<width-r; i++ {
                res = append(res, matrix[t][i])
            }
            t++
            order = 2
            continue
        }
        if order == 2 {
            for i:=t; i<height-b; i++ {
                res = append(res, matrix[i][width-r-1])
            }
            r++
            order = 3
            continue
        }
        if order == 3 {
            for i:=width-r-1; i>=l; i-- {
                res = append(res, matrix[height-b-1][i])
            } 
            b++
            order = 4
            continue
        }
        if order == 4 {
            for i:=height-b-1; i>=t; i-- {
                res = append(res, matrix[i][l])
            }
            l++
            order = 1
            continue
        }
    }

    return res
}
```
