### 解题思路
此处撰写解题思路

### 代码

```golang
func findMaxAverage(nums []int, k int) float64 {
	res:=0
	//index:=0
	for i:=0;i<k;i++{
		res+=nums[i]
	}
	for i:=1;i<= len(nums)-k;i++{
		tmp:=0
		for j:=i;j<i+k;j++{
			tmp+=nums[j]
		}
		if res<tmp{
			res=tmp
			//index=i
		}
	}
	return float64(res)/float64(k)

}
```