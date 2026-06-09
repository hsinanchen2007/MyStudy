### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

 /* 1、冒泡排序(非标准) */
void bubble_sort1(int *nums, int numsSize)
{
    int i, j;
    for (i = 0; i < numsSize - 1; ++i) {
        for (j = i + 1; j < numsSize; ++j) {
            if (nums[i] > nums[j]) {
                swap(nums + i, nums + j);
            }
        }
    }
}

/* 2、冒泡排序（标准） 两两比较 最大元素归位*/
void bubble_sort2(int *nums, int numsSize)
{
    int i, j;
    for (i = numsSize - 1; i > 0; --i) {
        for (j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums + j, nums + j + 1);
            }
        }
    }
}

/*3、冒泡排序（标准 + 优化）*/
void bubble_sort3(int *nums, int numsSize)
{
    int i, j;
    bool flag = false;

    for (i = numsSize - 1; i > 0 && !flag; --i) { // flag = true 说明前半部分已经是有序的不用在比较了
        for (j = 0; j < i; j++) {
            flag = true;
            if (nums[j] > nums[j + 1]) {
                swap(nums + j, nums + j + 1);
                flag = false;
            }
        }
    }
}

/* 4 、插入排序 
 * 将整个序列分成两个部分有序的前缀，和无序的后缀，
 * 通过迭代，反复地将后缀首元素转移至前缀中。
 */
void insertsort(int *nums, int numsSize)
{
    int i, j, temp;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i-1]) {
            temp = nums[i];
            for (j = i - 1; j >= 0 && temp < nums[j]; j--) {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
    }
}

/*5、选择排序 
 *在要排序的一组数中选择最小的一个与第一个交换，再在后面中选出最小的
 *与第二个交换，如此迭代下去直到全部有序
 */
void selectsort(int *nums, int numsSize)
{
    int i, j, min;

    for (i = 0; i < numsSize; i++) {
        min = i;
        for (j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(nums + i, nums + min);
        }
    }
}

/*6、快速排序 */
int partition(int *nums, int lo, int hi)
{
    /* 选择基准 也可以随机选择 */
    int temp = nums[lo];

    while (lo < hi) {
        while (lo < hi && temp <= nums[hi]) {
            hi--;
        }
        nums[lo] = nums[hi];
        
        while (lo < hi && temp > nums[lo]) {
            lo++;
        }
        nums[hi] = nums[lo];
    }
    nums[lo] = temp; // 基准归位置

    return lo;
}

void quicksort(int *nums, int lo, int hi)
{
    if (lo == hi) {
        return;
    }

    int mid  = partition(nums, lo, hi);
    quicksort(nums, lo, mid - 1);
    quicksort(nums, mid + 1, hi);
}

/*7、 归并排序 */
void merge(int *nums, int lo, int mid, int hi)
{
    int *tmp = (int *)malloc((hi - lo + 1) * sizeof(int));

    int i, j, k = 0;

    for (i = lo, j = mid + 1; i <= mid && j <= hi;) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = nums[i++];
    }

    while (j <= hi) {
        tmp[k++] = nums[i++];
    }

    for (i = 0; i < hi - lo + 1; i++) {
        nums[lo + i] = tmp[i];
    }
    free(tmp);
}

void mergesort(int *nums, int lo, int hi)
{
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }
}

/*8、库函数qsort */
int cmp(const void * a, const void * b)
{
   return (*(int*)a - *(int*)b); //从小到大
}
// qsort(int *nums, int numsSize, sizeof(int), cmp);

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }

    *returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);

    return nums;
}
```