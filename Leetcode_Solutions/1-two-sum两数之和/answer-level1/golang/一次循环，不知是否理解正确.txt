```
func towSum(nums *[]int, target int)(r [2]int){
	var i,j  int;
	j = len(*nums) - 1
	for i = 0; i<j; i++{
		sum := (*nums)[i] + (*nums)[j]
		fmt.Println((*nums)[i],(*nums)[j])
		if sum < target {
			continue
		}else if sum == target {
			r[0] = (*nums)[i]
			r[1] = (*nums)[j]
			return
		}else{
			i--
			j--
		}
	}
	return
}
```
