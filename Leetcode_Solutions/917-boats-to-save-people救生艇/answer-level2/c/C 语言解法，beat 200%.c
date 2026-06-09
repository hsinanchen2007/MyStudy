### 解题思路
![image.png](https://pic.leetcode-cn.com/11c7ecf4ce634a101690983b385db6123ac9943cdb0aa3e4af64258ba2e587a7-image.png)


### 代码

```c
int cmp(const void *a,const void *b){
 	return *(int *)a > *(int *)b ? 1:-1;//递增
}
int numRescueBoats(int* a, int n, int limit){
	qsort(a,n,sizeof(int),cmp);

	int ans=0;
	int low=0,high=n-1;
	while(low<high){
		if((a[low]+a[high])<=limit){//可以载两人上船
			low++,high--,ans++;
		}else{
			high--,ans++;//排在后面的人上车，即当前重量最重的
		}
	}
    /*
        细节！当 high=low 时候，说明还有一个人没有上车！
        若是全部上车的话，应是 low>high
    */
    if(high==low) ans++;
	return ans;
}
```