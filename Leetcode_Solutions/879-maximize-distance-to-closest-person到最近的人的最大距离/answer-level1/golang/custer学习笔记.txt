第一思路，很尬超级尬

1. 记录每个有人的座位的下标，存到mark数组中备用(预处理)
2. 如果第一个座位没有人，最大距离为第一个有人座位的下标
3. 如果最后一个座位没有人，最大距离为所有座位的个人减去最后一个有座位的下标
4. 最后再判断中间位置两人之间的最大距离

```go
func maxDistToClosest(seats []int) int {
	if len(seats) < 3 {
		return 1
	}
	var mark []int // 标记有人的座位下标
	for i, seat := range seats {
		if seat == 1 { // 如果座位有人，记录下下标
			mark = append(mark, i)
		}
	}
	des := mark[0]  // 如果第一个座位没有人，那到第一个有人座位的距离
	if mark[len(mark)-1] != len(seats)-1 {  // 如果最后一个座位没有人
		e := len(seats) - 1 - mark[len(mark)-1] // 坐在最后一位离最近的人的距离
		if des < e { 
			des = e
		}
	}
	for i := 0; i < len(mark)-1; i++ { // 判断每个座位之间的距离
		e := mark[i+1] - mark[i] - 1 
		if des < (e+e%2)/2 {
			des = (e + e%2) / 2
		}
	}
	return des
}
```

学习[@lhf2018的评论内容](https://leetcode-cn.com/problems/maximize-distance-to-closest-person/comments/94403)实现：

```go
func maxDistToClosest(seats []int) int {
	max := 0
	num := 0
	// 左边全都可以坐，例如:[0,0,0,0,0,0,0,1]那就坐最左边的位置；
	if seats[0] == 0 {
		i := 0
		for {
			if seats[i] != 0 {
				break
			}
			num++
			i++
		}
		max = num
	}
	// 右边全都可以坐，例如[1,0,0,0,0,0,0,0]，那就坐最右边的位置；
	num = 0
	if seats[len(seats)-1] == 0 {
		i := len(seats) - 1
		for {
			if seats[i] != 0 {
				break
			}
			num++
			i--
		}
		if num > max {
			max = num
		}
	}
	// 左右两边都有人，那就看哪一段空的座位最多，例如[1,0,0,0,0,0,1,0,1]，有两段，坐第一段最中间。
	num = 0
	tmp := 0
	for i := 0; i < len(seats); i++ {
		if seats[i] == 0 {
			tmp++
		} else {
			tmp = 0
		}
		if tmp > num {
			num = tmp
		}
	}
	if num%2 == 0 {
		if num/2 > max {
			max = num / 2
		}
	} else {
		if (num+1)/2 > max {
			max = (num + 1) / 2
		}
	}
	return max
}
```

[最后学习大佬的方法](https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0849.maximize-distance-to-closest-person/maximize-distance-to-closest-person.go)

```go
func maxDistToClosest(seats []int) int {
	size := len(seats)
	maxDis := 0
	// e 代表了连续空位的个数
	// 当连续空位两边都有人的时候，maxDis = (e+e%2)/2
	// 如果有一边没人的话，      maxDis = e
	e := 0
	for i := 0; i < size; i++ {
		if e == i {
			// 说明 seats[0:i] 全是 0
			maxDis = e
		} else {
			maxDis = max(maxDis, (e+e%2)/2)
		}
		if seats[i] == 1 {
			e = 0
		} else {
			e++
		}
	}

	// 当 seats[size-1]==0 的时候
	// e 最后的值，有可能 > maxDis
	return max(maxDis, e)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```