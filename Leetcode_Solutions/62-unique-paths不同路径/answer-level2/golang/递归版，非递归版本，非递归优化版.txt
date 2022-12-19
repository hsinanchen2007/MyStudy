### 解题思路
此处撰写解题思路

### 代码

```golang
func uniquePaths(m int, n int) int {
    return QuickFun(m,n) // 急速版，内存占用最少，循环跳转最少
}

// 递归版本
func recursionFun(m,n int) int{
    valmap := make(map[int]int)
    var rec func(m int, n int) int
    rec = func(m,n int) int{
        if m == 1 && n == 1{
            return 1
        }

        hashVal := (m*100)+n
        if v,e := valmap[hashVal];e{
            return v
        }

        var mRet,nRet int
        if m > 1{
            mRet = rec(m-1,n)
        }
        if n > 1{
            nRet = rec(m,n-1)
        }
        result := mRet+nRet
        valmap[hashVal] = result
        return result
    }
    return rec(m,n)
}

// 非递归版
func NonRecursionFun(m,n int) int{
    if m == 1 || n == 1{
        return 1
    }
	arr := make([][]int,m,m)
	for k,_ := range arr{
		arr[k] = make([]int,n,n)
	}
	arr[0][0] = 0
	arr[1][0] = 1
	arr[0][1] = 1
	initM := 2
	for in := 0; in < n;in++{
		for im := initM; im < m; im++{
			r := im-1
			l := in-1
			v := 0
			if r >= 0{
				v += arr[r][in]
			}
			if l >= 0{
				v += arr[im][l]
			}
			arr[im][in] = v
		}
		if initM >0 {
			initM--
		}
	}

	return arr[m-1][n-1]
}

// 急速版
func QuickFun(m,n int) int{
    if m == 1 || n == 1{
        return 1
    }
	size := n
    if m < n{
        size = m
    }
    arr := make([]int,size,size)
    for k,_ := range arr{
        arr[k] = 1
    }

    var index int
    for i := size; i < m*n;i++{
        index = i % size
        if index == 0{
            arr[index] = 1
            continue
        }
        arr[index] = arr[index] + arr[index-1]
    }

	return arr[size-1]
}
```