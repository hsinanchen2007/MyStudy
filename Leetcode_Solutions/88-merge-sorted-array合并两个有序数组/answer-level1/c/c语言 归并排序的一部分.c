### 解题思路
归并排序的一部分
创建一个中间数组用来进行合并，先选择两数组项中的较小值放入t[]中，如果任何一个数组元素用尽则把另一个数组余下的复制到t[]中
### 代码

```c
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=0;//nums1的下标
    int j=0;//nums2的下标
    int k=0;
    int t[nums1Size];
    while(k<nums1Size){//曾写错为(k<nums1size && i<m && j<n)导致下面前两个if语句无法执行
        if(i==m){
            for(j,k;j<n,k<nums1Size;j++,k++){
                t[k]=nums2[j];
            }
            break;
        }
        if(j==n){
            for(i,k;i<m,k<nums1Size;i++,k++){
                t[k]=nums1[i];
            }
            break;
        }
        if(nums1[i]<nums2[j]){
            t[k++]=nums1[i++];
        }
        else{
            t[k++]=nums2[j++];
        }
    }
    for(i=0,k=0;i<nums1Size,k<nums1Size;i++,k++){
        nums1[i]=t[k];
    }
}


```