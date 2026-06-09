![image.png](https://pic.leetcode-cn.com/937921a622173fde4e644f4230f3bec8d96fb96575ccd6af103477c982beb007-image.png)

```
func corpFlightBookings(bookings [][]int, n int) []int {
	passengers := make([]int, n + 1)
	for _, booking := range bookings {
		from := booking[0]
		to := booking[1]
		count := booking[2]
		passengers[from - 1] += count
		passengers[to] -= count
	}
	for i := range passengers {
		if i != 0 {
			passengers[i] += passengers[i - 1]
		}
	}
	return passengers[0: n]
}
```
