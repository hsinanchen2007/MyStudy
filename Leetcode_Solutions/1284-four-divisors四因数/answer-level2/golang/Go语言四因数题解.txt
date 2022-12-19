### 解题思路
思路是遍历，从2遍历到平方根，看看是不是在这个过程中除了1与本身之外，还有另一组因数。
一定要遍历到平方根这个数字，看别的大佬的意思是有四次方跟问题，但是我也没整明白为啥这样就对了。

### 代码

```golang
func sumFourDivisors(nums []int) int {
    ans:=0
	for i:=0;i<len(nums);i++{
		sum:=1+nums[i]
		temp:=0
		flag:=0
		for j:=2;j*j<=nums[i];j++ {
			if nums[i]%j==0{
				if temp==0{
					temp = j
				}else{
					flag=1
					break
				}
			}
		}
		if flag==0 && temp!=0 && temp!=nums[i]/temp{
			ans+=(sum+temp+nums[i]/temp)
		} 
	}
	return ans
}
```