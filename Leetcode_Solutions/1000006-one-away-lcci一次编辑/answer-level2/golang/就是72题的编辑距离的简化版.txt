### 解题思路
此处撰写解题思路

### 代码

```golang

func minDistance(word1 string, word2 string) int {
	l1,l2 := len(word1),len(word2)
	var makeArr func(l1,l2 int) [][]int
	makeArr = func(l1, l2 int) [][]int {
		arr := make([][]int,l1)
		for i:=0;i<l1;i++{
			arr[i] = make([]int,l2)
		}
		return arr
	}
	dp := makeArr(l2+1,l1+1)
	for i:=0;i<=l2;i++{
		dp[i][0] = i
	}
	for i:=0;i<=l1;i++{
		dp[0][i] = i
	}
	for i:=1;i<=l2;i++{
		for j:=1;j<=l1;j++{
			dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
			if word2[i-1] != word1[j-1]{
				dp[i][j]++
			}
		}
	}
	return dp[l2][l1]
}
func min(a... int)int  {
	m := a[0]
	for _,v := range a{
		if v<m{
			m = v
		}
	}
	return m
}


func oneEditAway(first string, second string) bool {
	l1,l2 := len(first),len(second)
	if l1-l2>1 || l2-l1>1{
		return false
	}
	return minDistance(first,second)<2
}

```