问题分析：在有序数组中查找一个元素，二分法没得说。同时查找的要求是找到第一个大或于等于目标元素的下下标，二分法第二类。

以下是将二分法归为三类：
 
1.	查找元素e是否存在序列中
循环不变式为A[0,lo]<=e<=A[hi,n)
当lo=0，hi=n时，则有A[lo]<=e<=A[hi]
若e存在于序列中当lo=hi时，则有A[lo]=A[hi]=e;
若此时A[lo]=A[hi]!=e,则说明元素e不存在于序列中。
代码如下：
	

```c
int BinaSearch(int *A,int lo,int hi,int e){
	while(lo<hi){
		int mid=(lo+hi)>>1;
		If(e<A[mid])
			hi=mid;
		else if(A[mid]<e)
			lo=mid;
		else
			return mid	
	}
	return -1;
}
```

2.	查找序列A中第一个大于或等于元素e的元素
循环不变式为A(0,lo)<e<=A[hi,n)
当lo=0时，hi=n时，有A[lo]<e<=A[hi]
当lo=hi时，有A[lo-1]<e<=A[lo]=A[hi],
即此时的A[lo]即为序列中第一个小于或等于e的元素
代码如下：

```c
int BinaSearch(int *A,int lo,int hi,int e){
	while(lo<hi){
		int mid=(lo+hi)>>1;
		e<=A[mid]?hi=mid:lo=mid+1;
	}
	return lo;
}
```

3.	查找序列中最后一个不大于e的元素
循环不变式为A[0,lo) <= e < A[hi,n)
当lo=0,hi=n时，则有A[lo]<=e<A[hi]
当lo=hi时，则有A[lo-1]<=e<A[lo]=A[hi]
代码如下;

```c
int BinaSearch(int *A,int lo,int hi,int e){
	while(lo<hi){
		int mid=(lo+hi)>>1;
		A[mid]<=e?lo=mid+1:hi=mid
	}
	return mid; 
}
```

总结:使用二分法查找某个元素时，依据以上三个循环不变式即可。再把他们转化为响应的代码。
小技巧：○1.开区间时，相应的hi=mid-1或lo=mid+1;闭区间直接为hi=mid为lo=mid。
       ○2.查找第一个，hi向左走，将A[mid]包含；查找最后一个，lo向右走，将A[mid]包含。





