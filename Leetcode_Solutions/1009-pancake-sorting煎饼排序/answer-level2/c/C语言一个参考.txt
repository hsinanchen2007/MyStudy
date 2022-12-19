```
/*执行用时 : 8 ms , 在所有C提交中击败了 100.00% 的用户 
内存消耗 : 7.3 MB , 在所有C提交中击败了 100.00% 的用户
 首先，题目中给的案例十分具有迷惑性，并不是每次从尾处开始找第一个比A[0]小的
这样并不能确定你的翻转次数。我最开始就被迷惑了，最后发现如果输入是[1,3,2],则
不能正确排序，那我们可以浪费点时间，每次找出来一个最大的放到最后，类似于冒泡
，但是冒泡是通过交换实现，而这个是通过反转实现。找到最大值之后，一次翻转到首
位，再一次首位与当前未排序区域末尾交换。
涉及到具体实现：复制A，在B内升序排列，从B末尾依次取值，在A内寻找，找到后两次
翻转，直到A有序。*/
int cmp(const void *a,const void *b) {
	return *(int *)a-*(int *)b;
}//qsort升序排列 
int* pancakeSort(int* A, int ASize, int* returnSize) {
/* 因为每个数只需要两次翻转，且第一个数不需要翻转，实际取 ASize*2-1就可以 */
	int *ret=(int *)calloc(ASize*2,sizeof(int));
	* returnSize=0;
	
	/* 复制A到B，对B升序排列*/
	int *B=(int *)calloc(ASize+1,sizeof(int));
	for(int i=0; i<ASize; i++) {
		B[i]=A[i];
	}
	qsort(B,ASize,sizeof(A[0]),cmp);
/* 依次取B中最大的*/ 
	for(int i=ASize-1; i>0; i--) {
		int j;
		for(j=0; j<ASize; j++) {
			if(A[j]==B[i]) break;
		}//额外中止条件 
		ret[(* returnSize)++]=j+1;
/* 第一次翻转，从o到j*/
		int start=0,end=j;
		while(start<end) {
			int temp=A[start];
			A[start]=A[end];
			A[end]=temp;
			start++;
			end--;
		}
/* 第二次翻转，从o到i*/		
		ret[(* returnSize)++]=i+1;
		int start1=0,end1=i;
		while(start1<end1) {
			int temp=A[start1];
			A[start1]=A[end1];
			A[end1]=temp;
			start1++;
			end1--;
		}
	}
	return ret;
}```