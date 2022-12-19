### 解题思路
此处撰写解题思路

### 代码

```c
// 冒泡排序
void sort(int * nums, int n)
{
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k = 0;
    for(int i = m; i < m + n; i++){
        nums1[i] = nums2[k++];
    }
    sort(nums1, m + n);
}
```

```
// 插入排序
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 0 ; i < n; i++){
        int curr = nums2[i];
        int k = 0;
        while(k < m && curr > nums1[k]) k++; // 找到插入位置
        int j = m - 1;
        while(j >= k) {
            nums1[j+1] = nums1[j]; // 挪动位置
            j--;
        }
        nums1[k] = curr;
        m = m + 1;
    }
}
```
