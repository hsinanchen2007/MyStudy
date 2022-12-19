### 解题思路
此处撰写解题思路

### 代码

```golang
func countPrimeSetBits(L int, R int) int {
	res:=0
	for i:=L;i<=R;i++{
		count:=0
		tmp:=i
		for tmp>0{
			if tmp&1==1{
				count++
			}
			tmp>>=1
		}
		if helpCountPrimeSetBits(count){
			res++
		}
	}
	return res
}
//判断一个数是不是质数
func helpCountPrimeSetBits(a int)bool{
	if a<=1{
		return false
	}
	for i:=2;i<=int(math.Sqrt(float64(a)));i++{
		if a%i==0{
			return false
		}
	}
	return true
}

```