### 解题思路
此处撰写解题思路

### 代码

```c
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void AdjustDown(int *A,int k,int len){//将元素k向下调整
    A[0]=A[k];
    for(int i=2*k;i<=len;i*=2){
        if(i<len&&A[i]<A[i+1])
            i++;
        if(A[0]>=A[i]) break;
        else{
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}
void buildmaxheap(int *nums2,int len){
    for(int i=len/2;i>0;i--){
        AdjustDown(nums2,i,len);
    }
}
int findKthLargest(int* nums, int numsSize, int k){
    int *nums2=(int*)malloc(sizeof(int)*(numsSize+1));
    for(int i=0;i<numsSize;i++){
        nums2[i+1]=nums[i];
    }
    buildmaxheap(nums2,numsSize);
	int count=0;
	for(int i=numsSize;i>1;i--){
		swap(&nums2[i],&nums2[1]);
		AdjustDown(nums2,1,i-1);
		if(++count==k){
			return nums2[i];
		}
	}
    return nums2[1];
}
```