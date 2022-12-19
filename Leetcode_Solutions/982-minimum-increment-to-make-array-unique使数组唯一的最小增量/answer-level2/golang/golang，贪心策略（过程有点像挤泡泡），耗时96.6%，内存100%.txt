思路：先统计各个数出现的次数，并记录最大值和最小直，然后从最小值开始，依次递增，将当前超过1次的数字保留一个，其余的各自加一，累积到后一个相邻的数
直到最后达到全部累加到最大值处，最大值后面的直接采用连续数列的累加和公式（1+2+3++...+n=n(n+1)/2)
```
	if len(A)==0{
		return 0
	}
	res:=0
	arr:=make([]int,40001)
	maxA:=0
	minA:=A[0]
	for i:=0;i<len(A);i++{
		arr[A[i]]+=1
		if A[i]>maxA{
			maxA=A[i]
		}
		if A[i]<minA{
			minA=A[i]
		}
	}
	for minA<maxA{
		if arr[minA]>1{
			cnt:=arr[minA]-1
			res+=cnt
			arr[minA+1]+=cnt
		}
		minA++
	}
	cnt:=arr[maxA]-1
	res+=cnt*(cnt+1)/2
	return res
```
