```
func twoSum(numbers []int, target int) []int {
	res := make([]int,0)
	var head = 0
	var tail = len(numbers) - 1
	for(head < tail){
		if numbers[head] + numbers[tail] > target{
			tail --
		}else if numbers[head] + numbers[tail] < target {
			head ++
		}else {
			res = append(res,head+1)
			res = append(res,tail+1)
            break
		}
	}
	return res
}
```
很好理解吧。。。
