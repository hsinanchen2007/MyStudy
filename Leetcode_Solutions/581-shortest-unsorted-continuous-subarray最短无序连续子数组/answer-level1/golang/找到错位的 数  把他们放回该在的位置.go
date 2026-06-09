func findUnsortedSubarray(a []int) int {
	l:=0
	r:=0					// 4 5 6 2
	for  i:=0;i<len(a)-1;i++{//1 找到左边 第一次逆序出现的位置 l 【6的位置】
		if a[i]>a[i+1] 	{l=i
		break}
	}
	for  i:=len(a)-1;i>=1;i--{//2 找到右边 第一次逆序出现的位置	r 【2的位置】
		if a[i]<a[i-1] 	{r=i
		break}
	}
	if r-l==0 {	return 0}
							
	Max:=a[l]
	Min:=a[l]
	for  i:=l;i<=r;i++{			//找到 l到r之间 【最大】 和 【最小】的数
		Max=max(Max,a[i]	)
		Min=min(Min,a[i]	)
	}

				//4 5 6 2  	 2				4
	for  i:=0;i<l;i++{	//【最小】 本该在的位置
		if a[i]>Min{	l=i
		break}
	
	}						//   6			2
	for  i:=len(a)-1;i>r;i--{//【最大】 本该在的位置
		if a[i]<Max{	r=i
		break}
		
	}
	if r-l==0 {	return 0}
	return r-l+1
	
}	