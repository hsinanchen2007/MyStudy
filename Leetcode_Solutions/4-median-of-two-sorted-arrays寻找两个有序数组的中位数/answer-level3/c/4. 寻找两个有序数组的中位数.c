直接上代码吧，写了两个小时，最后画了张图捋了捋，才写出来的
执行用时 :16 ms, 在所有 C 提交中击败了96.74%的用户
内存消耗 :7.6 MB, 在所有 C 提交中击败了87.35%的用户


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i=0,j=0;
    //判断
    //如果两数组和为奇数，m取总和+1的中位数
    //如果两数组和为偶数，m取中位数，n取中位数加1
    double m=0,n=0;
    //k用来计算两数组和是奇数还是偶数
    int k=0;
    //l用来计算第几个数是中位数
    int l=0;
    //p用来计数
    int p=0;
    
    k=nums1Size+nums2Size;
    if(k%2==1)
    {
        l=(k+1)/2;
    }else{
        l=k/2;
    }
    printf("l=%d\n",l);
    //判断nums1与nums2内部是否有数
    if(nums1Size==0 && nums2Size==0 )
    {
        m=0;
    }else if(nums1Size==0)
    {
        if(k%2==1)
            m=nums2[l-1];
        else if(k%2==0)
        {
            m=nums2[l-1];
            n=nums2[l];
            m=(m+n)/2;
        }
    }else if(nums2Size==0)
    {
        if(k%2==1)
            m=nums1[l-1];
        else if(k%2==0)
        {
            m=nums1[l-1];
            n=nums1[l];
            m=(m+n)/2;
        }
    }else{
        puts("ok");
        while(i<nums1Size && j<nums2Size)
        {
            if(nums1[i]<=nums2[j])
            {
                m=nums1[i];
                p++;
                i++;
            }else{
                m=nums2[j];
                p++;
                j++;
            }
        
            if(p==l)
                break;
        }
        
        if(p==l)
        {
            if(i<nums1Size && j<nums2Size && k%2==0)
            {
                if(nums1[i]<=nums2[j])
                    n=nums1[i];
                else
                    n=nums2[j];
                m=(m+n)/2;
            }else if(i==nums1Size && k%2==0){
                n=nums2[j];
                m=(m+n)/2;
            }else if(j==nums2Size && k%2==0){
                n=nums1[i];
                m=(m+n)/2;
            }
        }else{
            if(i==nums1Size)
            {
                p=l-nums1Size-1;
                m=nums2[p];
                if(k%2==0)
                {
                    n=nums2[p+1];
                    m=(m+n)/2;
                }
            }else if(j==nums2Size){
                p=l-nums2Size-1;
                m=nums1[p];
                if(k%2==0)
                {
                    n=nums1[p+1];
                    m=(m+n)/2;
                }
            }
        }
    }
    return m;
}