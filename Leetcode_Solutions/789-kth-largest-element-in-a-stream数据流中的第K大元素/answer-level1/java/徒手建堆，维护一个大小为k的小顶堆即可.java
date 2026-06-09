### 解题思路
此处撰写解题思路
### 代码

```java
class KthLargest {
    private int[] kthMax;
    private int size;
    private int capacity;
    public KthLargest(int k, int[] nums) {
        capacity = k;
        kthMax = new int[k + 1];
        for (int i : nums) {
            offer(i);
        }
    }
    
    public int add(int val) {
        offer(val);
        return kthMax[1];
    }
    
    void adjust(int[] arr, int i, int length) {
        int temp = arr[i];
        for (int k = i * 2; k <= length; k *= 2) {
            if (k < length && arr[k] > arr[k + 1])
                k++;
            if (temp <= arr[k])
                break;
            arr[i] = arr[k];
            i = k;
        }
        arr[i] = temp;
    }

    void offer(int value) {
        if (size <= capacity)
            size++;
        if (size <= capacity) {
            kthMax[size] = value;
            for (int i = size / 2; i >= 1; i /= 2)
                adjust(kthMax, i, size);          
        }else {
            if (value > kthMax[1]) {
                kthMax[1] = value;
                adjust(kthMax, 1, size - 1);
            }
        }
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```