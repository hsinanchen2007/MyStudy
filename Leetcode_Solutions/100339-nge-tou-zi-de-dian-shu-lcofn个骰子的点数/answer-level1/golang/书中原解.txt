```
import "math"

const gMax = 6

func twoSum(n int) (rst []float64) {
	var (
		i, j, k       int
		total         = math.Pow(float64(gMax), float64(n))
		flag          = 0
		probabilities = make([][]int, 2)
	)
	probabilities[0] = make([]int, n*gMax+1)
	probabilities[1] = make([]int, n*gMax+1)

	for i = 1; i <= gMax; i++ {
		probabilities[flag][i] = 1
	}

	for k = 2; k <= n; k++ {
		for i = 0; i < k; i++ {
			probabilities[1-flag][i] = 0
		}

		for i = k; i <= k*gMax; i++ {
			probabilities[1-flag][i] = 0
			for j = 1; i-j >= 0 && j <= gMax; j++ {
				probabilities[1-flag][i] += probabilities[flag][i-j]
			}
		}
		flag = 1 - flag
	}

	rst = make([]float64, gMax*n-n+1)
	for i = n; i <= gMax*n; i++ {
		rst[i-n] = float64(probabilities[flag][i]) / total
	}

	return rst
}
```
