每次从nums2中取一个元素，插入到nums1中去
```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 0; i < n; i++)
    {
        int temp = nums2[i];
        
        int j = 0, k;
        while(j < m && nums1[j] <= temp)        //找到插入点
            j++;
        
        for(k = m - 1; k >= j; k--)      //将插入点及其后面的元素，往后移一格，以便插入
            nums1[k + 1] = nums1[k];

        nums1[k + 1] = temp;
        m++;
    }
}
```
