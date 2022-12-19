### 解题思路

参考 [*windliang*](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/) 的第四种解法，但是在*当{ i = 0 || j = 0}，切在了最前边 或者 当 {i = m || j = n}，切在最后边的时候，需要判断{j != 0 || i != 0}是否越（下）界或者判断{j != n || i !=m }是否越（上）界，不然会报错....

### 代码

```c

//注意各种越界....


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //从长度较小的数组遍历
    int m, n, *A, *B; 
    if(nums1Size > nums2Size){
        m = nums2Size;
        n = nums1Size;
        A = nums2;
        B =nums1;
    }
    else{
        m = nums1Size;
        n = nums2Size;
        A = nums1;
        B = nums2;
    }

    int low = 0, high = m;
    int maxleft = 0, minright = 0;
    int i = 0, j =0 ;

    while(low <= high){

        i = (high + low)/2;
        j = (m + n + 1)/2 - i;

        if(j != 0 && i != m && B[j-1] > A[i]) // 数组2的rightpart 大于数组1的leftpart，i需要增大
            low = i + 1;
        else if(i != 0 && j != n && A[i-1] >B[j]) //数组1的leftpart 大于数组2的rightpart，i需要减小
            high = i - 1;

        else{ //达到要求 nums1[i-1]<nums2[j]&&nums1[i]>nums2[j-1]，并考虑边界条件；
                if (i == 0) //数组1割完后，左半部分为空，左半部分最大值为数组2的左半部分最大值；
                {   
                    if(j != 0) maxleft = B[j-1];//检查越界
                    else    maxleft = B[j];  
                }
                else if (j == 0) 
                { 
                    if(i != 0) maxleft = A[i-1];//检查越界
                    else    maxleft = A[i];  
                }
            else 
                maxleft = ( A[i-1] > B[j-1] ? A[i-1] : B[j-1]);
            
            if((m + n) % 2 == 1) //合并后数组个数为奇数，不需要考虑右半部分最小值
                break;
            else
            {
                if(i == m) //数组1割完后，右半部分为空，右半部分最小值为数组2的右半部分最小值
                {    
                    if(j != n ) minright = B[j];//检查越界
                    else    minright = B[j-1]; 
                }
                else if(j == n) //与以上情况类似
                {
                    if(i != m)  minright = A[i];//检查越界
                    else    minright = A[i-1];
                }
                else 
                    minright = (A[i] < B[j] ? A[i] : B[j]);   
            
                break;
            }
        }
        
    }
    if((m + n) % 2 == 1) //合并后数组个数为奇数，不需要考虑右半部分最小值
        {   
            return maxleft;
        }
        else
        {
            return (maxleft + minright) / 2.0; 
        }
}
```