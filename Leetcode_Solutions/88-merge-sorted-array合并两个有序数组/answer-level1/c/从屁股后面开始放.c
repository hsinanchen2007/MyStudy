从nums1的屁股后面开始放数据，谁大放谁，思路清晰！

```
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1;
    int j = n - 1;
    int len = m + n;
    for(int k = len-1; k >= 0; k--) {
        int n1 = i == -1? INT_MIN: nums1[i];
        int n2 = j == -1? INT_MIN: nums2[j];
        if(n1 > n2) {
            nums1[k] = n1;
            i--;
        } else {
            nums1[k] = n2;
            j--;
        }
    }
}
```
