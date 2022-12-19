### 解题思路
先插入再用快排排序

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i,j=0;
    void quick_sort(int a[],int l,int r);
    for(i=m;i<m+n;i++){
        nums1[i]=nums2[j];
        j++;
    }
    quick_sort(nums1,0,m+n-1);

}
void quick_sort(int a[],int l,int r){
    if(l<r){
        int i=l,j=r;
        int x=a[l];
        while(i<j){
            while(i<j&&a[j]>=x){
                j--;
            }
            if(i<j){
                a[i]=a[j];
                i++;
            }
            while(i<j&&a[i]<x){
                i++;
            }
            if(i<j){
                a[j]=a[i];
                j--;
            }
        }
        a[i]=x;
        quick_sort(a,l,i-1);
        quick_sort(a,i+1,r);
    }
}
```