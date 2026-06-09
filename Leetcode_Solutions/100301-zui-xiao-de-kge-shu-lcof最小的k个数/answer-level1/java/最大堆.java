
典型的最大堆问题。
使用最大堆的优先队列实现。因为维护最大堆即可以，因此没有将优先队列写做内部类。

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if(k == 0){
            return new int[0];
        }
        // 最大堆
        int[] maxHeap = new int[k + 1];
        int offset = 1;
        for(int i : arr){
            if(offset > k){
                if(maxHeap[1] > i){
                    // 替换堆顶元素，保持堆有序
                    maxHeap[1] = maxHeap[offset - 1];
                    sink(1, maxHeap, offset - 1);
                    maxHeap[offset - 1] = i;
                    swim(offset - 1, maxHeap);
                }
            }
            else{
                maxHeap[offset++] = i;
                swim(offset - 1, maxHeap);
            }
        }
        int[] res = new int[k];
        for(int i = 1; i <= k; i++){
            res[i - 1] = maxHeap[i];
        }
        return res;
    }

    private void swim(int offset, int[]maxHeap){
        while(offset > 1 && maxHeap[offset] > maxHeap[offset / 2]){
            exch(maxHeap, offset, offset /2 );
            offset = offset / 2;
        }
    }
    private void exch(int[]maxHeap, int i , int j){
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[j];
        maxHeap[j] = temp;
    }
    private void sink(int index, int[] maxHeap, int offset){
        int j = 0;
        while(index * 2 <= offset){
            j = index * 2;
            if(j < offset && maxHeap[j] < maxHeap[j + 1]) j++;
            if(maxHeap[j] < maxHeap[index]) break;
            exch(maxHeap, j, index);
            index = j;
        }
    }
}
```
