### 解题思路
1、申请array空间：size取决于数组长度小的那个
2、一个作为被比较的对象，另一个作为比较的对象
3、两层for循环进行比较，若存在相等的整数，则在array中进行判断：是否存在相同整数，没有就放进去

缺点：不知道哪个数组长，如果短的数组作为被比较的对象，就很费时
      内存消耗的话我觉得申请空间大小前还可以更精准的判断
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int temp = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *arr = (int*)malloc(sizeof(int)*temp);
    int size = 0;
    for ( int i = 0 ; i < nums1Size ; i++ ) {
        for ( int j = 0 ; j < nums2Size ; j++ ) {
            if ( nums2[j] == nums1[i] ) {
                int flag = 0;
                for ( int k = 0 ; k < size ; k++ ) {
                    if ( arr[k] == nums2[j] ) {
                        flag = 1;
                    }
                }
                if ( !flag ) {
                    arr[size++] = nums2[j];
                }
            }
        }
    }
    (*returnSize) = size;
    return arr;
}
```