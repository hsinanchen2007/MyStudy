合并数组再冒泡排序，
好笨，被各种大神解法吊打！！！

```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p,q,j;
    q = 0;
    for(p = m;p<nums1Size;p++){
        nums1[p] = nums2[q];
        q++;
    }
    for (q=0; q<p-1; ++q)  //比较n-1轮
    {
        for (j=0; j<p-1-q; ++j)  //每轮比较n-1-i次,
        {
            if (nums1[j] > nums1[j+1])
            {
                int buf;
                buf = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = buf;
            }
        }
    }
    
    return nums1;
}

```
