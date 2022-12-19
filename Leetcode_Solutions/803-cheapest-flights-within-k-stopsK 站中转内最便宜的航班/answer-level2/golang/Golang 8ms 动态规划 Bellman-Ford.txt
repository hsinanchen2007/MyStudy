运行时间： 8ms
提醒： go标准库math里面有一个math.Int64表示最大的int64，使用的时候要除以/2，以免发生overflow。

我这里使用 2x节点数x边最大指 粗略算出一个最大值。

提示：标准库math 里面的 Min(float64, float64) float64 的运行时间较慢，对于int型的求小，自定义过一个min函数即可。

提示：go的slice 克隆方法很多，最安全的是就是 s1 = append(s0[:0:0], s0...)

```
func findCheapestPrice(n int, flights [][]int, src int, dst int, K int) int {
	// 	The max price for every route is 10000,
	//	so we can set the infCost to be 2*n*10000
	infCost := 2 * n * 10000
	//	A list to denote the final resuts:
	//	cost[0] is the price to city 0
	cost := make([]int, n)
	//	Fill every city with infinite price
	//	except the source city
	for i := range cost {
		cost[i] = infCost
	}
	// The cost from src to src is initialized to 0
	cost[src] = 0

	for i := 0; i <= K; i++ {
		//	This temp slice is for computing cost for
		//	the i-th round (means routes via i trans city).
		//	The default value is a copy from the last round
		tempCost := append(cost[:0:0], cost...)
		//	Loop all the routes to compute if there
		//	is a better way to flight from source city
		for _, route := range flights {
			// Compare if there is a better price
			// for from the source to destination.
			// If there is, then update the cost.
			tempCost[route[1]] = min(tempCost[route[1]], cost[route[0]]+route[2])
		}
		//	Save the result back to the cost slice
		//	for the next round comput.
		cost = append(tempCost[:0:0], tempCost...)
	}

	if cost[dst] >= infCost {
		return -1
	} else {
		return cost[dst]
	}

}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

```
