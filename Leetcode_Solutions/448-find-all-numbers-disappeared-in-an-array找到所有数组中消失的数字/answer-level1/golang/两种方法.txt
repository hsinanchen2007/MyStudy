### 解题思路
此处撰写解题思路

### 代码

```golang
func findDisappearedNumbers(nums []int) []int {

	N:= len(nums)
	sort.Ints(nums)
	read,write:=0,0
	var pointer int
	if len(nums)>0{
		pointer=nums[write]
	}

	for read< len(nums){
		fmt.Println(read)
		if nums[read]==pointer{
			if read== len(nums)-1{
				break
			}
			read++
		}else{
			//sameLength:=write-read
			write++
			nums= append(nums[:write], nums[read:]...)
			read=write
			pointer=nums[write]
		}

	}
	result:=make([]int,0)
	k:=0
	for i:=1;i<=N;i++{
		if i!=nums[k]{
			result= append(result, i)
		}else{
			if k< len(nums)-1{
				k++
			}

		}
	}
	fmt.Println("result : ",result)
	return result
}


func findDisappearedNumbers1(nums []int) []int {
	sort.Ints(nums)//nums排序
	fmt.Println("hahaha",nums)
	res:=make([]int,0)
	k:=0
	for i:=1;i<= len(nums);{//1到n的所有的数字遍历，与数组nums中的数字比较

		if k< len(nums)-1{
			if i<nums[k]{
				res= append(res, i)
				i++
			}else if i==nums[k]{
				i++
				k++
			}else{
				k++
			}
		}else{//当k=len(nums)-1时，nums中所有的数字都遍历过了，然后拿剩下的数字i与 nums的最后一个数字比较，因为 i 和 nums 都是一次增大的，所以 后面的i 要么 大于 nums[k],此时要加入到res中，要么i=nums[k]此时直接舍弃
			if i!=nums[k]{
				res= append(res, i)
			}
			i++
		}
	}
	return res
}
```