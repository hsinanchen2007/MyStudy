
![捕获.PNG](https://pic.leetcode-cn.com/ab06143afce70e61ab86fc2d2daf5bed287ccb3e6973763d156311ef5665a9f7-%E6%8D%95%E8%8E%B7.PNG)

### 代码
1.建小顶堆
```
void Heap(int a[],int pos,int length){
	int temp=a[pos];
	for(int i=2*pos+1;i<length;pos=i,i=2*i+1){
		if((i+1)<length&&a[i]>a[i+1])i++;
		if(temp>a[i])
			a[pos]=a[i];
		else break;
	}
	a[pos]=temp;	
}
int findKthLargest(int* a, int numsSize, int k){
	for(int i=k/2-1;i>=0;i--)
		Heap(a,i,k);
	for(int i=k;i<numsSize;i++){
		if(a[0]<a[i])    
            a[0]=a[i];
		Heap(a,0,k);
	}
	return a[0];
}
```

2.类似于快排
```
int findKthLargest(int* a, int numsSize, int k){
    int low=0,high=numsSize-1;
    while(low<high){
        int i=low,j=high,temp=a[i];
        while(i<j){
            while(j>i&&a[j]<=temp)j--;
            if(i<j)
            	a[i]=a[j];
            while(i<j&&a[i]>=temp)i++;
            if(i<j)
            	a[j]=a[i];
        }
        a[i]=temp;
        
        if(i==(k-1))
            return a[i];
        else if(i<(k-1))
            low=i+1;
        else   
            high=i-1;
    }
    return a[low];
}
```

