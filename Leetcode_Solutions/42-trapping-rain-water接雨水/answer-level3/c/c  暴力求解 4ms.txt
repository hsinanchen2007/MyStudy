### 解题思路


### 代码

```c
int maxheight(int *height,int low,int high);//返回数组low--high的最大值的下标；
int trap(int* height, int heightSize){
	if(heightSize==0||heightSize==1||heightSize==2) return 0;
	int i=0,j=0,k,sum=0,volum=0;
	j=k=maxheight(height,0,heightSize-1);//j用于遍历最大值右边的部分

	while(j>0&&i>=0){
		i=maxheight(height,0,j-1);
		sum=0;
		for(int m=i+1;m<j;m++)sum+=height[m];
		volume+=height[i]*(j-i-1)-sum//volume为装水的体积
		j=i;
	}
	
	while(i<=heightSize-1&&k<heightSize-1){
		i=maxheight(height,k+1,heightSize-1);
		sum=0;
		for(int m=k+1;m<i;m++)sum+=height[m];
		volum+=height[i]*(i-k-1)-sum;
		k=i;
	}
	
	return volum;		
}
int maxheight(int *height,int low,int high){
	int max=low;
	int i;
	for(i=low;i<=high;i++){
		if(height[max]<height[i]) max=i;
	}
	return max;
} 
```