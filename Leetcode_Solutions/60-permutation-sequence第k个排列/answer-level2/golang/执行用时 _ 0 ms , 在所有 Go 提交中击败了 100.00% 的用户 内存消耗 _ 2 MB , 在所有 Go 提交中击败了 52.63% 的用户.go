这里是go的数学方法解，递归方式，代码很多很烂很菜！！！
```
func getPermutation(n int, k int) string {
	s:=""
	if n==0||k==0 {
		return s
	}
	arr:=make([]int,n+1)
	nums:=make([]int,n+1)
	temp:=1
	for i:=1;i<len(arr);i++ {
		temp=temp*i
		arr[i]=temp
	}
	getN(&s,nums,arr,n,k)
	return s
}
//取第n位的值
func getN(s *string,nums []int,arr []int,n int,k int){
	if k>arr[n] {
		return
	}
	if k==arr[n]||k==0 {
		for i:=len(nums)-1;i>0;i-- {
			if nums[i]==0 {
				*s=*s+strconv.Itoa(i)
				nums[i]=1
			}
		}
		return
	}
	if k>arr[n-1] {
		temp:=k/arr[n-1]
		k=k%arr[n-1]
		if k==0{
			temp=temp-1
		}
		flag:=0
		for i:=1;i<len(nums);i++ {
			if nums[i]==0 {
				if flag==temp {
					*s=*s+strconv.Itoa(i)
					nums[i]=1
					break
				}else {
					flag++
				}
			}
		}
	}else{
		for i:=1;i<len(nums);i++ {
			if nums[i]==0 {
				*s=*s+strconv.Itoa(i)
				nums[i]=1
				break
			}
		}
	}
	getN(s,nums,arr,n-1,k)
}
```
