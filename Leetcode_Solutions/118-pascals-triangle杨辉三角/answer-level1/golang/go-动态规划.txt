```
func generate(numRows int) [][]int {
   if numRows==0{
       return [][]int{}
   }
    dp:=[][]int{
        []int{1},// line 0
        []int{1,1},// line 1
        []int{1,2,1},//line 2
    }
    for i:=3;i<numRows;i++{
        line:=[]int{1}
        up:=dp[i-1]
        for x:=1;x<i;x++{
            line=append(line,up[x-1]+up[x])
        }
        line=append(line,1)
         dp=append(dp,line)
    }

    return dp[:numRows]
}
```
