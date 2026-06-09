double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    //排序2个数组，然后放到一个数组里面
    int num_max = 0;
    num_max = nums1Size+nums2Size;
    int *a = (int *)malloc(num_max*sizeof(int));
    int i;
    int j1 = 0;
    int j2 = 0;
    //int j1_temp,j2_temp;

    for(i = 0; i < num_max; i++)
    {        
        if (j1 >= nums1Size)
        {
            a[i] =  nums2[j2];
            j2++;
        }
        else if (j2 >= nums2Size)
        {
            a[i] =  nums1[j1];
            j1++;
        }
        else if ( nums1[j1] <  nums2[j2])
        {
            a[i] =  nums1[j1];
            j1++;
        }
        else if (nums1[j1] >=  nums2[j2])
        {
            a[i] = nums2[j2];
            j2++;
        }
    }
    
    double d_median = 0;
    if (num_max % 2) //奇数返回中间的值
    {
        d_median = a[(num_max + 1) /2 -1];
    }
    else
    {
        d_median =  (double)(a[(num_max+1)/2-1] + a[num_max/2])/2;
    }
    free(a);
    return d_median;
}