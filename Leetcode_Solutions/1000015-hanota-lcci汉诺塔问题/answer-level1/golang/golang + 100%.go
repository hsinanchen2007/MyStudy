### 解题思路

h汉诺塔问题是经典的递归问题，
- A(n-1) -> C(0) - B(n-1)  
- A(1) -> C(1)
- B(n-1) -> A(0) -> C(1)
可以抽象成 `from,mid,to`，递归的终止条件是`num == 1`时

### 代码

```golang

func hanota(A []int, B []int, C []int) []int {
	if A == nil {
		return nil
	}

	var move func(int, *[]int, *[]int, *[]int)
	move = func(num int, from, mid, to *[]int) {
		if num < 0 {
			return
		}
		if num == 1 {
			*to = append(*to, (*from)[len(*from)-1])
			*from = (*from)[:len(*from)-1]
			return
		}

		move(num-1, from, to, mid)
		move(1, from, mid, to)
		move(num-1, mid, from, to)
	}
	move(len(A), &A, &B, &C)
	return C
}
```