### 解题思路
![image.png](https://pic.leetcode-cn.com/51173ab8c5e726c07fa1c944c91eb8e839cb20634fb28e3c8c0a0b4a3bf8182e-image.png)


### 代码

```c
void Quick_Sort(int* arr,int low, int high);
int findidx(int *arr, int l, int r);
int hIndex(int* citations, int citationsSize){
    int i,j,t;
    Quick_Sort(citations, 0, citationsSize - 1);
    for(i=0;i<citationsSize;i++){
        if(citationsSize-i == citations[i]) 
            return citations[i];
        else if(citationsSize-i < citations[i]){
            t=citations[i];
            while(t>citationsSize-i){
                t--;
            }
            return t;
        }
    }
    return 0;
}
void Quick_Sort(int* arr,int low, int high){
    int idx;
    if(low < high){
        idx=findidx(arr, low, high);
        Quick_Sort(arr,low, idx-1);
        Quick_Sort(arr,idx+1,high);
    }
}
int findidx(int *arr, int l, int r){
    int t = arr[l];
    while(l<r){
        while(l < r && arr[r] >= t) r--;
        arr[l]=arr[r];
        while(l < r && arr[l] <= t) l++;
        arr[r]=arr[l];
    }
    arr[l] = t;
    return l;
}
```