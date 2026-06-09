![image.png](https://pic.leetcode-cn.com/156c0d9116d091521d8bed210ca2572d8ad41d1e89d9cd7d04d4f8ce2dac0f78-image.png)

### 解题思路
像洋葱一样一层一层剥。对每一层暴力模拟。

### 代码

```golang

func spiralOrder(matrix [][]int) []int {
	res := []int{}
	height := len(matrix)
	width := len(matrix[0])
	if height==0{
		return nil
	}
	i , j := 0,0
	for i <= int(math.Ceil(float64(height)/2-1)) && j <=int(math.Ceil(float64(width)/2-1)){
		temp := matrix[i:height-i]
		OneLayer(&res,temp,i,width - 2*j)
		i ++
		j ++
	}
	return  res
}
func OneLayer(res *[]int,m [][]int,h int,w int){
	height := len(m)
	width := len(m[0])
	if w == 1{
		for i := 0 ; i <height ; i++{
			*res = append(*res, m[i][h])
		}
	}else{
	for i := h ; i <w+h ; i ++{
		*res = append(*res, m[0][i])
	}
	for i := 1  ; i < height ; i++{
		*res = append(*res, m[i][w+h-1])
	}
	if height > 1{
		for i := width - h-2 ; i >= h ; i--{
			*res = append(*res, m[height-1][i])
		}
	}
	for i := height - 2  ; i >=1 ; i--{
		*res = append(*res, m[i][h])
		}
	}
}



```