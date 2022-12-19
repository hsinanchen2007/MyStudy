```

func cuttingRope(n int) int {
	// 用的是动态规划的方法，分解问题 f(n)=max(f(i)*f(n-i)),
	//但是自顶向下会造成重复计算，采用自下向上的方法。用数组保存计算的结果。
	// 时间复杂度 o(n**2) 空间复杂度o(n)
	if n<2{
		return 0
	}
	if n==2{
		return 1
	}
	if n==3{
		return 2
	}
	reslist := make([]int,n+1)
	reslist[0]=0
	reslist[1]=1
	reslist[2]=2
	reslist[3]=3
	max:=0
	for i := 4; i <=n;i++{
		max=0
		for j := 1; j<=i/2;j++{
			res:=reslist[j]*reslist[i-j]
			if max<res{
				max=res
			}
			
		}
		reslist[i]=max
	}
	max=reslist[n]
	return max
}


func cuttingRope2(n int) int {
	// 贪心算法
	// n>=5时  可以证明2(n-2)>n 3(n-3)>n,说明n>=5时，将其分解位3或2的绳段子，3的值越多，越大
	// n=4时，2*2>1*3 
	if n<2{
		return 0
	}
	if n==2{
		return 1
	}
	if n==3{
		return 2
	}
	timesOf3:=n/3
	if n-timesOf3*3==1 {
		timesOf3--
	}
	timesOf2:=(n-timesOf3*3)/2
	return int(math.Pow(2,float64(timesOf2))*math.Pow(3,float64(timesOf3)))

}

```
