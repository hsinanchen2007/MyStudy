### 解题思路
此处撰写解题思路

### 代码

```golang
func matrixReshape(nums [][]int, r int, c int) [][]int {
    var l int
	var tmp []int
	var result [][]int
	for i:=0;i<len(nums);i++{
		l+=len(nums[i])
		for j:=0;j<len(nums[i]);j++{
			tmp = append(tmp,nums[i][j])
		}
	}
	if l==r*c{
		for i:=0;i<r;i++{
			var tmp2 []int
			for j:=0+i*c;j<c*(i+1);j++{
				tmp2 = append(tmp2,tmp[j])
			}
			result = append(result,tmp2)
		}
		return result
	}else{
		return nums
	}
}
```