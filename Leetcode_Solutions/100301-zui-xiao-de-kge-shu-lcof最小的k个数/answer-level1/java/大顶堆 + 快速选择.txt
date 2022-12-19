# 大顶堆

```Java
public int[] getLeastNumbers(int[] arr, int k) {
    if (k <= 0) {
        return new int[0];
    }

    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(k, (o1, o2) -> o2 - o1);
    for (int val : arr) {
        if (maxHeap.size() < k) {
            maxHeap.offer(val);
        } else if (val < maxHeap.peek()) {
            maxHeap.poll();
            maxHeap.offer(val);
        }
    }

    int[] res = new int[maxHeap.size()];
    int i = 0;
    while (!maxHeap.isEmpty()) {
        res[i++] = maxHeap.poll();
    }
    return res;
}
```


# 快速选择

```Java
public int[] getLeastNumbers(int[] arr, int k) {
    if (arr == null || arr.length <= k) {
        return arr;
    }

    int l = 0, r = arr.length - 1;
     while (l <= r) {
        int p = partition(arr, l, r);
        if (p == k - 1) {
            break;
        }
        if (p > k - 1) {
            r = p - 1;
        } else {
            l = p + 1;
        }
    }
    return Arrays.copyOf(arr, k);
}

private int partition(int[] arr, int lo, int hi) {
    int pivot = arr[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, hi);
    return i;
}

private void swap(int[] arr, int i, int j) {
    if (i != j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
```

