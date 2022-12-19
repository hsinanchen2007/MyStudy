### 解题思路
首先建立堆，然后利用堆排序堆思路，求出堆的第K个值。

### 代码

```c
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int tree[], int n, int i) {
    if (i >= n) {
        return ;
    }
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;

    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }

    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }

    if (max != i)  {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
}

void build_heap(int tree[], int n) {
    int last_node = n - 1;
    int parent = (last_node) / 2;

    for (int i = parent; i >= 0; --i) {
        heapify(tree, n, i);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    build_heap(nums, numsSize);
    for (int i = numsSize - 1; i >= numsSize - k; --i) {
        swap(nums, i, 0);
        heapify(nums, i, 0);
    }
    return nums[numsSize - k];
}
```