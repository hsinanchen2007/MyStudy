golang解决

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 思路类似于　leetcode 0121_Beat_Time_to_Buy_and_Sell_Stock
// score = A[i]+A[j]+i-j = (A[i]+i)+(A[j]-j), (A[j]-j)的值由j决定
// 故,对于固定'j',要使score最大，只需(A[i]+i)最大即可
// 由于i<j,在遍历j的过程中，可通过哨兵变量pre_max维护(A[i]+i)的最大值
// 时间复杂度：O(n)  空间复杂度：O(1)

func maxScoreSightseeingPair(A []int) int {
	max_score := 0
	pre_max := A[0]  // 哨兵变量，维护在当前j时，(A[i]+i)的最大值 

	for j:=1; j<len(A); j++ {
		score := pre_max + A[j] - j 
		if score>max_score {
			max_score = score
		}

		if A[j]+j>pre_max {
			pre_max = A[j] + j
		}
	}

	return max_score
}
```

