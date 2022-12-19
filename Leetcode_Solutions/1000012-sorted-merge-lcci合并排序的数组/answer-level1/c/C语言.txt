### 解题思路
合并+快排

### 代码

```c
int split(int a[], int low, int high){
    int part_element = a[low];
    for(;;){
        while (low < high && part_element <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}

void quicksort(int a[], int low, int high){
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle-1);
    quicksort(a, middle+1, high);
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int pa = m, pb = 0;
        for (int i = 0; i < n; i++) {
            A[pa] = B[pb];
            pa++;
            pb++;
        }
    quicksort(A, 0, ASize-1);
}
```