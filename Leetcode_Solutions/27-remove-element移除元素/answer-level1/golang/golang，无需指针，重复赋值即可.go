### 解题思路
如果元素跟目标值相等，则去掉改元素，数组值改为nums[0:i] + nums[i+1:]，
数组更新后，由于长度-1，所以i不自增，
如果元素跟目标值不相等，则继续循环

### 代码

```golang
func removeElement(nums []int, val int) int {
	for i:=0;i<len(nums); {
		if nums[i] == val {
			nums = append(nums[0:i],nums[i+1:]...)
		}else {
			i++
		}
	}
	return len(nums)
}
```


```golang
func main() {
	var nums  = []int{5,5,5,5,4,3,2,5,2,7,1,1}
	var val = 4
	fmt.Printf("%p \n",nums)
	fmt.Println("length =",removeElement(nums,val))
}

func removeElement(nums []int, val int) int {
	fmt.Printf("%p \n",nums)
	for i:=0;i<len(nums); {
		if nums[i] == val {
			nums = append(nums[0:i],nums[i+1:]...)
			fmt.Printf("%p \n",nums)
		}else {
			i++
		}
	}
	return len(nums)
}
```

通过打印数组的内存地址，可以验证并没有增加额外空间
0xc000096000 
0xc000096000 
0xc000096000 
length = 11