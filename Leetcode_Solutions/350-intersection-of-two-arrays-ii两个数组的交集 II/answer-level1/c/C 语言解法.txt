### 解题思路
method 1: 排序
method 2: 哈希表（具体代码有些错误，思路理解即可）

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void adjustDown (int a[], int k, int n) {
    int temp = a[k - 1];
    for (int i = k * 2; i <= n; i = k * 2) {
        if ( i + 1 <= n && a[i + 1 - 1] > a[i - 1]) ++i;
        if (temp >= a[i - 1]) break;
        a[k - 1] = a[i - 1];
        k = i;
    }
    a[k - 1] = temp;
}

void buildHeap (int a[], int n) {
    for (int i = n / 2; i >= 1; --i)
        adjustDown(a, i, n);
}

void heapSort (int a[], int n) {
    buildHeap(a, n);
    for (int i = n - 1; i > 0; --i) {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        adjustDown(a, 1, i);
    }
}

// method 1: sort
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res = (int *)malloc(1 * sizeof(int));
    int length = 0;

    heapSort(nums1, nums1Size);
    heapSort(nums2, nums2Size);
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size; ) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            res = (int *)realloc(res, ++length * sizeof(int));
            res[length - 1] = nums1[i];
            ++i;
            ++j;
        }
    }

    returnSize[0] = length;
    return res;
}

// method 2: hash
// 哈希表元素，保存数据值和该数据出现次数，二者不可或缺
// 数组长度较小者，选为哈希表长

/* ------------- something wrong ------------- */
// typedef struct hashNode {
//     int data;
//     int cnt;
// } hashList;

// int getPrimeNumber (int m) {
//     if (m == 1 || m == 2) return m;
//     if (m % 2 == 0) m--;
//     for (int i = m; i >= 3; i -= 2) {
//         int k = sqrt(i);
//         int j = 3;
//         for ( ; j <= k && i % j; j += 2);
//         if (j > k) return i;
//     }
//     return 1;
// }

// int hashFind (hashList hash[], int nums[], int k, int m) {
//     int p = getPrimeNumber(m);// 最靠近 m 的素数，没有，则 1
//     for (int i = 0; i < m; ++i) {
//         int addr = nums[k] % p;
//         for (int undone = 1, j = 0; undone && j < m; ) {
//             addr = (addr + j) % m;
//             if (hash[addr].cnt == 0) {// empty
//                 return 0;
//             } else if (hash[addr].data == nums[i]) {// non-empty && same element
//                 return addr;
//             } else {
//                 ++j;
//             } // conflict
//         }
//     }
//     return 0;
// }

// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
//     int *nums = NULL;
//     int m = 0;
//     if (nums1Size < nums2Size) {
//         m = nums1Size;
//         nums = nums1;
//     } else {
//         m = nums2Size;
//         nums = nums2;
//     }

//     hashList hash[m];
//     int p = getPrimeNumber(m);// 最靠近 m 的素数，没有，则 1

//     for (int i = 0; i < m; ++i) {
//         int addr = nums[i] % p;
//         for (int undone = 1, j = 0; undone; ) {
//             addr = ((addr + j) % m + 1);// addr 从 1 开始
//             if (hash[addr].cnt == 0) {// empty, insert
//                 hash[addr].cnt++;
//                 hash[addr].data = nums[i];
//                 undone = 0;
//             } else if (hash[addr].data == nums[i]) {// non-empty && same element, cnt++
//                 hash[addr].cnt++;
//                 undone = 0;
//             } else {
//                 ++j;
//             } // conflict
//         }
//     }

//     if (nums == nums1) {
//         m = nums2Size;
//         nums = nums2;
//     } else {
//         m = nums1Size;
//         nums = nums1;
//     }

//     int *res = (int *)malloc(1 * sizeof(int));
//     int length = 0;
//     for (int i = 0; i < m; ++i) {
//         int addr = hashFind (hash, nums, i, m);
//         if (addr) {
//             res = (int *)realloc(res, ++length * sizeof(int));
//             res[length - 1] = hash[addr].data;
//             hash[addr].cnt--;
//         }
//     }

//     returnSize[0] = length;
//     return res;
// }
```