先吐槽一句，这题对于相邻的解释真的很蠢，只能向右下和向下，不能左下。
这题用DP解就可以了，简单描述下过程
初始：
[
     [2],
    [3,4],
   [6,5,7]
]
第一轮过后：3+2=5，4+2=6
[
     [2],
    [5,6],
   [6,5,7]
]
第二轮过后：6+5=11，[5+5=10,5+6=11,取小值10]，7+6=13
[
     [2],
    [5,6],
   [11,10,13]
]

```golang
func minimumTotal(triangle [][]int) int {
	if len(triangle)==1 {
		return triangle[0][0]
	}
	for i:=1; i<len(triangle); i++ {
		for j:=0;j<i;j++{
			temp:=triangle[i-1][j]+triangle[i][j]
			if j-1>=0 {
				temp=min(temp,triangle[i-1][j-1]+triangle[i][j])
			}
            triangle[i][j]=temp
		}
		triangle[i][i]+=triangle[i-1][i-1]
	}
	temp:=triangle[len(triangle)-1][0]
	for _,v:=range triangle[len(triangle)-1]{
		if v<temp {
			temp=v
		}
	}
	return temp
}
func min(x int,y int) int {
	if x>y {
		return y
	}else {
		return x
	}
}
```