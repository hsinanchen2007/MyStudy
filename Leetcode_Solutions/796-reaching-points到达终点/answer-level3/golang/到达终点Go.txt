```go
package main

// https://leetcode-cn.com/problems/reaching-points/submissions/
// 暴力行不通哦
// 逆向思维
// 递归省空间
func main() {
	if !reachingPoints_1(1, 1, 3, 5) {
		panic("error")
	}
	if !reachingPoints_2(1, 1, 3, 5) {
		panic("error")
	}
}

/*
执行用时：0 ms
内存消耗：2.2 MB
*/
func reachingPoints_1(sx int, sy int, tx int, ty int) bool {
	if sx == tx && sy == ty {
		return true
	}
	if sx > tx || sy > ty {
		return false
	}
	if sx == tx {
		return (ty-sy)%sx == 0
	}
	if sy == ty {
		return (tx-sx)%sy == 0
	}
	if tx > ty {
		tx = tx - ty
	} else {
		ty = ty - tx
	}
	return reachingPoints_1(sx, sy, tx, ty)
}

/*
执行用时：0 ms
内存消耗：2.1 MB
*/
func reachingPoints_2(sx int, sy int, tx int, ty int) bool {
	for sx != tx || sy != ty {
		if sx > tx || sy > ty {
			return false
		}
		if sx == tx {
			return (ty-sy)%sx == 0
		}
		if sy == ty {
			return (tx-sx)%sy == 0
		}
		if tx > ty {
			tx = tx - ty
		} else {
			ty = ty - tx
		}
	}
	return true
}

```