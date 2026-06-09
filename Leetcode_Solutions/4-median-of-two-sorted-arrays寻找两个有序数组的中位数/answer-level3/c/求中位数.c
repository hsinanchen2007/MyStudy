### 解题思路
    思路是按序取走较小的数，直到到达中间那个数。由于它可能是中间两个数的平均，故应对此加以区分，即如果总长度是偶数，那么还得求得下一个数，再平均两个数即可求得。此外还要考虑一个数组遍历完得情况
    注:指针p到达末尾不是NULL!
### 代码

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int*p = nums1,*q = nums2,i=0;
    double middle = 0;//中位数
    bool flag = 0;//是否奇数
    if((nums1Size+nums2Size)%2==0)flag=0;
    else flag = 1;
    while(1){
        if(p==nums1+nums1Size){//判断数组是否达到末尾
            while(i++!=(nums1Size+nums2Size+1)/2){//求中间数
                middle = *q++;
            }break;
        }else if(q==nums2+nums2Size){//同上
            while(i++!=(nums1Size+nums2Size+1)/2){
                middle = *p++;
            }break;
        }
        //两数组都没有达到末尾的情况
        ++i;
        if(*p<*q)middle = *p++;
        else middle = *q++;
        if(i==(nums1Size+nums2Size+1)/2)break;
    }
    if(flag==1){//区分是求一个数还是两个数的均值
        return middle;
    }else{
        if(p!=nums1+nums1Size&&q!=nums2+nums2Size)
            return (middle+(*p<*q?*p:*q))/2;
        else if(p==nums1+nums1Size)
            return (middle+*q)/2;
        else
            return (middle+*p)/2;
    }
}
```