
先合并两个数组，然后冒泡排序。

冒泡排序：依次比较两个相邻的元素，每进行一趟排序都会找出一个较大值。如第一趟比较之后，排在最后的一个数一定是最大的一个数。

外循环为排序趟数，每次抽出一个数和未处理过的所有数比较，除了最后一个数 。
内循环为每趟比较对数，外循环每走一遍，内循环就少比较一个数。


```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		nums1[m+i]=nums2[i];
	}
	for(i=0;i<m+n-1;i++){    
		for(j=0;j<m+n-1-i;j++){
			if(nums1[j]>nums1[j+1]){
				temp=nums1[j];
				nums1[j]=nums1[j+1];
				nums1[j+1]=temp;
		    }
	    }
    }
}
```

官方解释里的从后往前排序，最优解。
```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int i=m+n-1;
	int j=m-1;  //nums1
	int k=n-1;  //nums2
	while(j>=0&&k>=0){
		nums1[i--]=(nums1[j]>nums2[k] ? nums1[j--]:nums2[k--]);	
	}
	while(j<0&&k>=0){
    		nums1[i--]=nums2[k--];
	}
	while(j>=0&&k<0){
    		nums1[i--]=nums1[j--];     
	}
}
```