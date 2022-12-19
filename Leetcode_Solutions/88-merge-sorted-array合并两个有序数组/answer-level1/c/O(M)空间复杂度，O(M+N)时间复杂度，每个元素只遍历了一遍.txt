### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *num1_copy = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++){
        num1_copy[i] = nums1[i];
    }
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(num1_copy[i] < nums2[j]){
            nums1[k] = num1_copy[i];
            i++;
            k++;
        }else{
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
    if(i == m){
        while(j < n){
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }else{
        while(i < m){
            nums1[k] = num1_copy[i];
            i++;
            k++;
        }
    }
}
```