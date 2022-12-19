### 解题思路
用java实现大小堆，保证大小堆的大小差不大于1并且小堆最小值大于大堆最大值。
### 代码

```java
class MedianFinder {
    
    private Heap maxHeap;
    private Heap minHeap;
    
    public MedianFinder() {
        maxHeap = new Heap(Heap.MAX_HEAP);
        minHeap = new Heap(Heap.MIN_HEAP);
    }
    
    public void addNum(int num) {
        if (minHeap.size() == 0 || minHeap.first() < num) {
            minHeap.add(num);
        } else {
            maxHeap.add(num);
        }
        
        if (maxHeap.size() - minHeap.size() > 1) {
            Integer a = maxHeap.removeFirst();
//            System.out.println("--1--a = " + a);
            minHeap.add(a);
        } else if (minHeap.size() - maxHeap.size() > 1) {
            Integer a = minHeap.removeFirst();
//            System.out.println("---2--a = " + a);
            maxHeap.add(a);
        }
    }
    
    public double findMedian() {
//        System.out.println("minTree.size = " + minTree.size() + " maxTree.size = " + maxTree.size());
//        minHeap.println();
//        maxHeap.println();
        if(minHeap.size() > maxHeap.size()) {
            return minHeap.first();
        } else if (minHeap.size() < maxHeap.size()) {
            return maxHeap.first();
        } else {
            return (maxHeap.first() + minHeap.first()) / 2.0;
        }
    }
    
    
    public class Heap{
        public static final int MAX_HEAP = 0;
        public static final int MIN_HEAP = 1;
        private int size;
        private int arraySize = 8;
        private int[] array = new int[arraySize];
        private int heapType = MAX_HEAP;
        
        public Heap(int type) {
            heapType = type;
        }
        
        public void println() {
            for (int i = 0; i < size; i++) {
                System.out.print(array[i] + ", ");
            }
            System.out.println();
        }
        
        public int size(){
            return size;
        }
        
        public int first(){
            return array[0];
        }
        
        public void add(int num) {
            if (size == arraySize) {
                arraySize = arraySize * 2;
                int[] temp = new int[arraySize];
                System.arraycopy(array, 0, temp, 0, array.length);
                array = temp;
            }
            
            array[size] = num;
            size++;
            if(heapType == MAX_HEAP) {
                adjustUpMax();
            } else if(heapType == MIN_HEAP){
                adjustUpMin();
            }
        }
        
        public int removeFirst() {
            int res = 0;
            if(size > 0) {
                res = array[0];
            }
            
            if (size == 1) {
                size--;
                return res;
            }
            
            array[0] = array[size - 1];
            size--;
            if(heapType == MAX_HEAP) {
                adjustDownMax();
            }else if (heapType == MIN_HEAP) {
                adjustDownMin();
            }
            return res;
        }
        
        private void adjustDownMax() {
            int index = 0;
            
            for (int k = index * 2 + 1; k < size; k = k * 2 + 1) {
               
                
                if ((k + 1) < size && array[k] < array[k + 1]) {
                    k++;
                }
                
                if (array[index] > array[k]) {
                    break;
                } else {
                    swap(index, k);
                    index = k;
                }
            }
        }
        
        private void adjustDownMin() {
            int index = 0;
            
            for (int k = (index << 1) + 1; k < size; k = (k << 1) + 1) {
               
                
                if ((k + 1) < size && array[k] > array[k + 1]) {
                    k++;
                }
                
                if (array[index] < array[k]) {
                    break;
                } else {
                    swap(index, k);
                    index = k;
                }
            }
        }
        
        private void adjustUpMax(){
            int index = size - 1;
            for(int k = (size - 1) >> 1; k >= 0; k = ((k + 1) >> 1) - 1) {
                if (array[index] > array[k]) {
                    swap(index, k);
                    index = k;
                }
            }
        }
        
        private void adjustUpMin(){
            int index = size - 1;
            for(int k = (size - 1) >> 1; k >= 0; k = ((k + 1) >> 1) - 1) {
                if (array[index] < array[k]) {
                    swap(index, k);
                    index = k;
                }
            }
        }
        
        private void swap(int j, int k) {
            int temp = array[j];
            array[j] = array[k];
            array[k] = temp;
        }
    }

}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```