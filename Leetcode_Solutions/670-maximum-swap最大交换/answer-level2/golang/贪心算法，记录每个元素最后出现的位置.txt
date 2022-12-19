### 解题思路
记录每个元素最后出现的位置

### 代码

```golang
func maximumSwap(num int) int {
    // 转换成数组
    arr := int2Arr(num)
    // 贪心算法记录每个数字最后出现的位置
    var cache = make([]int, 10)
    for i := 0; i < len(arr); i++ {
        cache[arr[i]] = i
    }
    for i := 0; i < len(arr); i++ {
        flag := false
        tmp := arr[i]
        for j := 9; j > tmp; j-- {
            idx := cache[j]
            if idx > i {
                arr[i], arr[idx] = arr[idx], arr[i]
                flag = true
                break
            }
        }
        if flag {
            break
        }
    }
    return arr2Int(arr)
}

func arr2Int(arr []int) int {
    var res = 0
    for i := 0; i < len(arr); i++ {
        res = res * 10 + arr[i]
    }
    return res
}

func int2Arr(num int) []int {
    var res []int
    if num == 0 {
        res = append(res, 0)
    } else {
        for num > 0 {
            res = append(res, num % 10)
            num = num / 10
        }
    }
    for i := 0; i < len(res) / 2; i++ {
		res[i], res[len(res) - i - 1] = res[len(res) - i - 1], res[i]
	}
    return res
}
```