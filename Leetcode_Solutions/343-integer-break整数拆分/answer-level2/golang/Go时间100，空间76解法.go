这题以DP为思路，不算很难，以10为例子，我们知道结果是10=3+3+4这么拆分，如果我们假设res[i]表示i能拆分的正整数的最大乘积，那么如何计算res[10]呢？
通过一个for循环，res[n]=res[i]*res[n-i]，看看最大的res[n]，即可。
res[10]=res[3]*res[3]\*res[4],实际上，也就是res[10]=res[3]\*res[7]

```golang
func integerBreak(n int) int {
    if n<=2 {
		return 1
	}
	if n==3 {
		return 2
	}
	arr:=make([]int,n+1)
	//从5开始，所有的乘数i都可以被分解了
	for i:=0;i<=4;i++{
		arr[i]=i
	}
	for i:=5; i<=n; i++ {
		temp:=i
		for j:=2;j<=i/2;j++{
			if arr[j]*arr[i-j]>temp {
				temp=arr[j]*arr[i-j]
			}
		}
		arr[i]=temp
	}
	return arr[n]
}
```