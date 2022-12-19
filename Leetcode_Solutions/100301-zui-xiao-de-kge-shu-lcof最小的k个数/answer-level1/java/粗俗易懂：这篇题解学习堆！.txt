```
class Solution {
    private int[] minHeap;
    private int count;
    private int size;

    public void init(int size){
        this.minHeap = new int[size + 1];
        this.count = 0;
        this.size = size;
    }

    public void insert(int num){
        if (count == size){ // 堆满了
            if (num > minHeap[1]) return;
            // 替换堆顶元素
            minHeap[1] = num;
            heapify(minHeap, count, 1);
            return;
        }

        count++;
        minHeap[count] = num;

        // 向上堆化
        int i = count;
        while (i/2 > 0 && minHeap[i] > minHeap[i/2]){
            swap(minHeap, i, i/2);
            i = i/2;
        }
    }

    private void heapify(int[] heap, int endIndex, int i){
        while (true){
            int minPosition = i;
            if (i*2 <= endIndex && heap[i*2] > heap[i]) minPosition = i*2;
            if (i*2+1 <= endIndex && heap[i*2+1] > heap[minPosition]) minPosition = i*2+1;
            if (minPosition == i) break;
            swap(heap, i, minPosition);
            i = minPosition;
        }
    }

    public int[] sort(){
        int k = count;
        int[] res = new int[size];
        while (k > 1){
            swap(minHeap, k, 1);
            res[k-1] = minHeap[k];
            k--;
            heapify(minHeap, k, 1);
        }
        res[0] = minHeap[1];
        return res;
    }

    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public int[] getLeastNumbers(int[] arr, int k) {
        // 思路：利用大顶堆，堆顶是集合中最大的，如果当前尝试的数字大于大顶堆，直接丢弃，如果小于当前堆顶
        // 首先判断是否堆是否满了，没满直接添加，满了就丢弃堆顶。然后进行堆化
        int[] res = new int[k];
        int len = arr.length;
        if (k < 1) return res;
        if (len <= k) return arr;

        init(k);

        for (int i = 0; i < len; i++){
            insert(arr[i]);
        }

        // 其实这里不用排序了,题目不要求
        for (int i = 1; i <= k; i++){
            res[i-1] = minHeap[i];
        }
        return res;
    }
}
```
