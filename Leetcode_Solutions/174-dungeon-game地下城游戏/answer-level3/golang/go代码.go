### 解题思路
1、动态规划
2、每一次的位置是 getMaxO8(1, 1-dungeon[row][col])

### 代码

```golang
package main

//一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
//
//骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
//
//有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
//
//为了尽快到达公主，骑士决定每次只向右或向下移动一步。
//
//
//
//编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
//
//例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。
//
//-2 (K)	-3	3
//-5	-10	1
//10	30	-5 (P)
//

func calculateMinimumHP(dungeon [][]int) int {
	if len(dungeon) == 0 {
		return 0
	}
	var dp [][]int
	for i := 0; i < len(dungeon); i++ {
		var oneLineDp []int
		for j := 0; j < len(dungeon[0]); j++ {
			oneLineDp = append(oneLineDp, 0)
		}
		dp = append(dp, oneLineDp)
	}
	var row = len(dungeon) - 1
	var col = len(dungeon[0]) - 1
	dp[row][col] = getMaxO8(1, 1-dungeon[row][col])
	for i := col - 1; i >= 0; i-- {
		dp[row][i] = getMaxO8(1, dp[row][i+1]-dungeon[row][i])
	}

	for i := row - 1; i >= 0; i-- {
		dp[i][col] = getMaxO8(1, dp[i+1][col]-dungeon[i][col])
	}

	for i := row - 1; i >= 0; i-- {
		for j := col - 1; j >= 0; j-- {
			var dp_min = getMinO8(dp[i+1][j], dp[i][j+1])
			dp[i][j] = getMaxO8(1, dp_min-dungeon[i][j])
		}
	}
	return dp[0][0]
}

func getMaxO8(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func getMinO8(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

```