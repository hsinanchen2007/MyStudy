### 解题思路
此处撰写解题思路

每一位上的数字要不同，那么 可供选择的数字 会越来越少，如果n=0 那么就是数字1 ，只有这一个数字
如果 n=1 那么 可以是 0,1,2，3,4,5,6,7,8,9 这十个数字 ，就是10
如果n>=2 那么 第一位 可以是9选1,（0不能在首位），第二位 可选 9个，第三位 可选8个，，，

### 代码

```golang
func countNumbersWithUniqueDigits(n int) int {
	
	nums := make([]int,10)
	if n==0{
		return 1
	}else if n==1{

		return 10
	}else if n>=2{
		nums[0]=1
		nums[1]=9
		sum:=nums[0]+nums[1]
		for i:=2;i<=n&&i<=10;i++{
			nums[i]=nums[i-1]*(10-(i-1))
			sum+=nums[i]
		}
		return sum
	}

	return 0





}
```