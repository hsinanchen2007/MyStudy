### 解题思路
额、第一个独立AC的题记录一下  写的还比较弱鸡。

### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    int m=nums1Size,n=nums2Size;
    int i,j=0,k=0,mid,lmid;
    int *newnum=(int *)malloc(sizeof(int)*(m+n));
    for(i=0;i<m;i++){
        if(j<n){
        while(*(nums1+i)>*(nums2+j)){
            *(newnum+k)=*(nums2+j);
            k++;
            j++;
            if(j==n){
                break;
            }
            
            
        }    
        }
        *(newnum+k)=*(nums1+i);
        k++;
    }
    
    while(j<n){
          *(newnum+k)=*(nums2+j);
          k++;
          j++;
        }
    
    if((m+n)%2==0){
            mid=(m+n)/2;
            lmid=mid-1;
            return (double)(*(newnum+mid)+*(newnum+lmid))/2;
        }
    else{
            mid=(m+n-1)/2;
            return *(newnum+mid);
        }
}
```