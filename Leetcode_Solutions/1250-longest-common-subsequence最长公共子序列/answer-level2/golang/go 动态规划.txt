### 解题思路
此处撰写解题思路
text1 = "abcde"
text2 =  "ace"

[         a c e
       [0 0 0 0] 
     a [0 1 1 1] 
     b [0 1 1 1] 
     c [0 1 2 2] 
     d [0 1 2 2] 
     e [0 1 2 3]
]

if str1[i] == str2[j] {    //如果相等
 	dp[i+1][j+1] = dp[i][j] + 1
 			} else {  //不等
 				dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j])
  			}


### 代码

```golang
func longestCommonSubsequence(text1 string, text2 string) int {
           
	dp := make([][]int,len(text1)+1)
	for i:=0;i<=len(text1);i++ { //行
		dp[i] = make([]int,len(text2)+1) //列
	}
	for i:=0;i<=len(text1);i++ { //初始化每一行第一个位置是0
		dp[i][0] = 0
	}

	for j:=0;j<=len(text2);j++ {  //初始化每一列的第一个位置是0
		dp[0][j] = 0
	}
	str1 := []byte(text1)
	str2 := []byte(text2)
	for i:=0;i<len(str1);i++ { //行
		for j:=0;j<len(str2);j++ { //列
			if str1[i] == str2[j] {
				dp[i+1][j+1] = dp[i][j] + 1
			} else {
				dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j])
			}
		}
	}

	return dp[len(str1)][len(str2)]
}

func max(x,y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
```