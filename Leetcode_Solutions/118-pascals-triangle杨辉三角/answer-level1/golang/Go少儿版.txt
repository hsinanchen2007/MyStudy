### 解题思路
当numRows>2的时候，除了首尾是1外，其他元素都是上一个数组相邻两个元素的和。

### 代码

```golang
func generate(numRows int) [][]int {
    var yh [][]int
	for i:=1;i<=numRows;i++{
		if i==1{
			yh=append(yh,[]int{1})
		}else if i==2{
			yh=append(yh,[]int{1,1})
		}else{
			var tmp []int
			tmp = append(tmp,1)
			for j:=0;j<len(yh[i-2])-1;j++{
				sum:=yh[i-2][j]+yh[i-2][j+1]
				tmp = append(tmp,sum)
			}
			tmp = append(tmp,1)
			yh = append(yh,tmp)
		}
	}
	return yh
}
```