**分治法**
```
int MaxSum(int *a,int left,int right){
	int sum=INT_MIN;
	if(left==right) sum=a[left];
	else{
		int centre=(left+right)/2;
		int lsum=MaxSum(a,left,centre);
		int rsum=MaxSum(a,centre+1,right);
		int s1=INT_MIN,lefts=0;
		for(int i=centre;i>=left;i--){
			lefts+=a[i];
			if(s1<lefts) s1=lefts;
		}
		int s2=INT_MIN,rights=0;
		for(int i=centre+1;i<=right;i++){
			rights+=a[i];
			if(s2<rights) s2=rights;
		}
		sum=s1+s2;
		if(sum<lsum) sum=lsum;
		if(sum<rsum) sum=rsum;
	}
	return sum;
}
int maxSubArray(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
	return MaxSum(nums,0,numsSize-1);	
}
```
**动态规划法**
int maxSubArray(int* nums, int numsSize){
	if(numsSize==0) return 0;
	int dp[numsSize];
	dp[0]=nums[0];
	int max=dp[0];
	for(int i=1;i<numsSize;i++){
		dp[i]=fmax(dp[i-1]+nums[i],nums[i]);
		if(dp[i]>max) max=dp[i];
	}	
	return max;
}