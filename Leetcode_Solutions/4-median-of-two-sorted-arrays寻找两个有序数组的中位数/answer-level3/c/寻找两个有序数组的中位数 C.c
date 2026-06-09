    感觉这题的重点是怎么把两个有序数组有效地合并成一个有序数组
    int num[nums1Size + nums2Size];
    int i = 0, j = 0, k = 0;
    int sum;
    double a;
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j])
        {
            num[k] = nums1[i];
            k++;
            i++;
        }
        else
        {
            num[k] = nums2[j];
            k++;
            j++;
        }
    }
        while(i < nums1Size)
        {
            num[k] = nums1[i];
            k++;
            i++;
        }
        while(j < nums2Size)
        {
            num[k] = nums2[j];
            k++;
            j++;
        }
    sum = (nums1Size + nums2Size) ;
    if((sum % 2) == 0)
    {
        a = (num[sum / 2] + num[(sum / 2) - 1]) / 2.0;
        return(a);
    }
    else
    {
        return (num[sum / 2]);
    }