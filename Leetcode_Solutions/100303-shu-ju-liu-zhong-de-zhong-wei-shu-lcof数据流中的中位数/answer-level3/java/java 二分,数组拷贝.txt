添加元素时候, 在有序的数组中二分找到新元素的插入位置, 然后用效率高的内存拷贝移动数组元素.

```java
class MedianFinder {

    private int[] arr;
    private int size;
    private int length;

    public MedianFinder() {
        size = 4096;
        arr = new int[size];
        length = 0;
    }

    public void addNum(int num) {
        // 如果需要扩容
        if (size == length) {
            size *= 2;
            arr = Arrays.copyOf(arr, size);
        }

        // 二分寻找插入位置
        int index = Arrays.binarySearch(arr, 0, length, num);
        if (index < 0) index = -index - 1;

        // 插入
        System.arraycopy(arr, index, arr, index + 1, length - index);
        arr[index] = num;

        length++;
    }

    public double findMedian() {
        return length % 2 == 0 ? (arr[(length - 1) / 2] + arr[length / 2]) / 2.0 : arr[length / 2];
    }

}
```
