### 解题思路
执行用时 :32 ms, 在所有 Go 提交中击败了50.00%的用户
内存消耗 :6.9 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang
var res int

func treeDiameter(edges [][]int) int {
    res = 0
    maps := make(map[int][]int)
    for _, v := range edges {
        maps[v[0]] = append(maps[v[0]], v[1])
        maps[v[1]] = append(maps[v[1]], v[0])
    }

    recursive(maps, 0, make([]bool, len(edges)+1))

    return res
}

func recursive(maps map[int][]int, index int, boolSlice []bool) int {
    boolSlice[index] = true
    slices := maps[index]
    var max1, max2 int
    for _, v := range slices {
        if boolSlice[v] {
            continue
        }
        num := recursive(maps, v, boolSlice) + 1
        if num > max1 {
            max2 = max1
            max1 = num
        } else if num > max2 {
            max2 = num
        }
    }
    total := max1 + max2
    if total > res {
        res = total
    }
    return max1
}
```