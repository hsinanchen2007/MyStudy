### 解题思路
双指针尝试未果，果断选择暴力直白的方法

### 代码

```c


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    printf("%d_%d_%d\n",nums1Size,m,nums2Size);
    if (nums1 == NULL || m + nums2Size > nums1Size){
        return;
    }
    for(int i = m, j = 0; m < nums1Size, j < nums2Size; j++, i++){
        nums1[i] = nums2[j];
    }
    printf("%d_%d_%d\n",nums1Size,m,nums2Size);
    for(int i = 0; i < m + nums2Size; i++)
    {
        for(int j = 0; j < m + nums2Size - 1 - i; j++)
        {
            printf("i_%d::j_%d\n",i,j);
            if(nums1[j] > nums1[j+1]){
                int tmp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = tmp;
            }
        }
    }
}


```