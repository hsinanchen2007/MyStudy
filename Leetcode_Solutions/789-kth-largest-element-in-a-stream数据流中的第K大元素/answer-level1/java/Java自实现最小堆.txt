```
class KthLargest {
    int[] heap;
    int size = 0; //堆当前大小
    int maxSize;  //堆最大大小

    public KthLargest(int k, int[] nums) {
        heap = new int[k + 1];
        maxSize = k;
        createHeap(nums);
    }

    public int add(int val) {
        if (size < maxSize) {
            heap[++size] = val;
            swim(size);
        } else if (size >= maxSize) {
            if (heap[1] >= val)
                return heap[1];
            else {
                heap[1] = val;
                sink(1);
            }
        }
        return heap[1];
    }

    public void createHeap(int arr[]) {
        for (int i = 0; i < arr.length; i++) {

            if (size < maxSize) {
                heap[++size] = arr[i];
                swim(size);
            } else if (size >= maxSize) {
                if (heap[1] >= arr[i])
                    continue;
                else {
                    heap[1] = arr[i];
                    sink(1);
                }
            }
        }

    }

    public void swim(int i) { //向上调整
        if (i / 2 >= 1 && heap[i / 2] > heap[i]) {
            swap(i / 2, i);
            swim(i / 2);
        }
    }

    public void sink(int i) { //向下调整
        int minChild = 0;

        if (i * 2 <= size) {
            minChild = i * 2;
        } else
            return;

        if (minChild + 1 <= size && heap[minChild + 1] < heap[minChild])
            minChild++;

        if (heap[i] > heap[minChild]) {
            swap(i, minChild);
            sink(minChild);
        }
    }

    public void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}
```