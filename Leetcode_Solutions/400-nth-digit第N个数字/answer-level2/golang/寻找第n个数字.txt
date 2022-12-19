### 解题思路
此处撰写解题思路

### 代码

```golang
func findNthDigit(n int) int {
	x:=1//假设 第n个数字所对应的数是个x位数
	//已知1位数 有9个，2位数有90个，三位数有900个
	//x位的数字共有
	base:=9

	//比如三位数前面有 一位的 9个 二位的 90 个 三位数的第一个是100
	for n-base*x>0{
		n-=base*x
		x++
		base*=10
	}
	//这时n表示 x位中的第n个数字
	var num int //表示 真实的目标数
	if n%x==0{
		num=int(math.Pow10(x-1))+(n-x)/x //三位数的第一个是100,所以三位数里面先减去3个数字 （100，中的三个数字 1,0,0)
		//如果整除了，说明 要返回的数字 是 数 num 的最后一位
		return num%10
	}else{
		num=int(math.Pow10(x-1))+(n-x)/x+1
		i:=n%x
		num=num/int(math.Pow10(x-i))
		return num%10
	}
}
```