void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, p1 = 0, p2 = 0;
    int* temp;

    if((m == 0) && (n > 0))
    {
        for(i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }

    if((m > 0) && (n > 0))
    {
        temp = (int* )malloc((m + n) * sizeof(int));

        i = 0;

        while((p1 < m) && (p2 < n))
        {
            if(nums1[p1] < nums2[p2])
            {
                temp[i++] = nums1[p1++];
            }
            else
            {
                temp[i++] = nums2[p2++];
            }
        }

        if(p1 == m)
        {
            while(p2 < n)
            {
                temp[i++] = nums2[p2++];
            }
        }

        if(p2 == n)
        {
            while(p1 < m)
            {
                temp[i++] = nums1[p1++];
            }
        }

        for(i = 0; i < (m + n); i++)
        {
            nums1[i] = temp[i];
        }

        free(temp);
    }
}