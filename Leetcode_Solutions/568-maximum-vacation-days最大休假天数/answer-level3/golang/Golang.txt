### 解题思路
* runtime: 136ms
* ram: 6.6 MB

动态规划，用一个数组 *dp*（GO 里面叫做 slice）来保存已经计算好的，当前状态下留在城市i的最长假期。

dp 初始化为最小整型（`MinInt`, Go 里面需要用代码内的方法来获得这个值）。你也可以选一个安全的负整数来表示这个值，因为数据规模和值都比较小。

从 `flights` 数组的长度获得城市的个数`n`

`dp[0]` 初始化为 0，始发城市为城市0。

按照星期循环，`days` 二维数组给出了每周能在每一个城市度假的天数。根据这个数组规模，我们得到了假期的周数 `k`。

因为每一次的循环，我们会用到 `dp` 作为上一次循环的结果，用来比较当前周与上周。

对于每一周，我们都循环遍历每一对城市，只关注两种可能：

* 目的地和始发地相同，表示我们在原地度假
* 目的地事发地不同，而且有飞机从事发地飞往目的地

我们初始化一个临时数组 `temp` 来保存遍历每一对城市的结果。这个数组表示在这个周，我们可以留在每一个城市的最好情况。这个计算需要对比上一周（保存在`dp`)和当下的情况。在未计算前，这个`temp`初始化为`MinInt`,因为此时我们只知道上一周情况，并不知道马上要计算的这一周的情况。

#### 计算开始：
    
对第 `w` 周， 我们遍历所有的目的地`d`和始发地`s`的组合。
temp[d] 表示在w周我们留在d城市的最佳情况。

```
    temp[d] = max(temp[d], dp[s]+days[d][w])
```
我们计算，`dp[s] + days[d][w]`是表示如果上周从 `s` 出发，这周呆在 `d` 的情况。这个结果拿来和 `temp` 内已经保存的结果作比较，取大值来更新。

循环结束后，表示我们计算了当前周的最佳度假情况，用这个结果替换掉dp，那么下一个循环就是`w+1`周的情况了。

    要点：数组dp记录的是上一周的情况，我们要不断更新这个dp的值。


### 代码

```golang
func maxVacationDays(flights [][]int, days [][]int) int {
	// n is the number of cities.
	n := len(flights)
	// k is the number of weeks.
	k := len(days[0])
	// compute the MinInt value
	const MaxInt = int(^uint(0) >> 1)
	const MinInt = -MaxInt - 1
	// dp is a one-d slice to record the current longest days
	// for the city dp[i]. It initializes with -1, but
	// the start city is 0.
	dp := make([]int, n)
	for i := range dp {
		dp[i] = MinInt
	}
	dp[0] = 0

	// Loop though weeks, there r K weeks.
	for w := 0; w < k; w++ {
		// Make a temporary slice to record the
		// computing results.
		temp := make([]int, n)
		for i := range temp {
			temp[i] = MinInt
		}
		// Loop though the flight matrix.
		// d stands for destination
		// s stands for source
		for d := 0; d < n; d++ {
			for s := 0; s < n; s++ {
				if d == s || flights[s][d] == 1 {
					temp[d] = max(temp[d], dp[s]+days[d][w])
				}
			}
		}

		// Update the final results
		dp = append(temp[:0:0], temp...)
	}
	return findMax(dp)
}

// max is a helper function to get the max value from
// two integer.
func max(a, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}

// findMax is helper function to find the maximum value in
// a slice.
func findMax(arr []int) int {
	max := arr[0]
	for _, v := range arr {
		if v > max {
			max = v
		}
	}
	return max
}

```