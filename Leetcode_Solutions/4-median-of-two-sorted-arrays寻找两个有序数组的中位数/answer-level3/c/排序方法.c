### 解题思路
此处撰写解题思路

### 代码

```c
int* func(int* arr,int len){
    int i = 0,j= 0;
    int res = 0;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1;j++){
            if(arr[j]>arr[j+1]){
                res = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = res;
            }
        }
    }
    return arr;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len = nums1Size+nums2Size;
    int arr[len];
    int j = 0;
    int i = 0;
    for(i=0;i<=nums1Size-1;i++){
        arr[i] = nums1[i];
    }
    for(;i<=len-1;i++){
        arr[i] = nums2[j];
        j++;
    }
    int* crr = func(arr,len);
    if(len%2==0){
        return (double)(crr[(len/2)-1]+crr[len/2])/2.0;

    }
    else{
        return (double)crr[len/2]*1.0;
    } 

}
```