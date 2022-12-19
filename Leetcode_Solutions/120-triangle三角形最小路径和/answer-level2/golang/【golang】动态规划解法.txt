
### 解题思路

首先，求最小路径和，是一道常见的动态规划。


SUM[i][j]表示到达 第i行，第j列的最小路径和，它是：
    
    - 如果是第一个元素，那么只有上一层的第一个元素过来

    - 如果是最后一个元素，那么也只能从上一层的最后一个元素过来

    - 如果是中间元素，
        Min{
            SUM[i-1][j-1],
            SUM[i-1][j],
        } + A[i][j]

取得。

初始化值：
    SUM[0][0] = A[0][0]


### 实现代码

```
func minimumTotal(triangle [][]int) int {

	lines := len(triangle)

	switch lines {
	case 0:
		return 0
	case 1:
		// 如果只有一行，则返回第一个元素
		return triangle[0][0]
	default:
	}

	// dp表格，用来保存 到达上一行各个节点的最小路径和
	// 该表中的元素一直重复读写
	dp := make([]int, len(triangle))

	// 初始化条件，第一行中的唯一元素
	dp[0] = triangle[0][0]

	var minTotal int

	for i := 1; i < lines; i++ {
		// 开始遍历所有的行

		currentLine := triangle[i]
		currentDP := make([]int, i+1)

		for j := 0; j < len(currentLine); j++ {
			// 处理当前行，j为第i行中的第j个元素

			// 如果是第0个元素，只有一条路径到
			if j == 0 {
				currentDP[j] = dp[j] + currentLine[j]
			} else if j == i {
				// 如果是最后一个元素
				currentDP[j] = dp[j-1] + currentLine[j]
			} else {
				// 否则取最小路径
				currentDP[j] = min(
					dp[j-1],
					dp[j],
				) + currentLine[j]
			}

			// 如果是最后一行，则开始记录最小值
			if i == lines-1 {
				if j == 0 {
					// 如果是第一个结果，则初始化返回结果
					minTotal = currentDP[j]
				} else {
					// 否则更新
					if minTotal > currentDP[j] {
						minTotal = currentDP[j]
					}
				}

			}
		}

		if i != lines-1 {
			// 如果不是最后一行，则更新dp表
			dp = currentDP
		}
	}

	return minTotal
}

func min(a, b int) int {
	if a > b {
		return b
	}

	return a
}
```


### 测试用例

```
func TestTriangle(t *testing.T) {
	ts := []struct {
		Triangle [][]int
		Want     int
	}{
		{
			Triangle: [][]int{
				[]int{2},
				[]int{3, 4},
				[]int{6, 5, 7},
				[]int{4, 1, 8, 3},
			},
			Want: 11,
		},
		{
			Triangle: [][]int{
				[]int{1},
				[]int{2, 3},
			},
			Want: 3,
		},
	}

	for _, tc := range ts {
		got := minimumTotal(tc.Triangle)
		if tc.Want != got {
			t.Errorf("input: %v, want: %d, got: %d", tc.Triangle, tc.Want, got)
		}
	}

}
```
