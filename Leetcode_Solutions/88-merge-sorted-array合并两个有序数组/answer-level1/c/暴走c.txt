    void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
        int i = m-1;
        int j = n-1;
        int cur = m+n-1;
        
        //从后向前遍历数组，将较大的数从数组nums1后面开始放置
        while(i >= 0 && j >= 0) 
            nums1[cur--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        // 将数组nums2中剩余的元素按顺序放入数组nums1中
        while(j >= 0)
            nums1[cur--] = nums2[j--];

    }