### 解题思路
维护一个大小等于K的最小堆。堆满时，比较堆顶元素和加入进来的元素，选择最大的替换堆顶元素，再调整堆，所有元素入堆后，堆顶元素即为第K个最大元素。

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        MinHeap minHeap = new MinHeap(k,true);
        for(int i : nums){
            minHeap.add(i);
        }
        return minHeap.pop();
    }
    class MinHeap {
    private int[] data;
    private int size;
    /**
     * 记录堆中最后一个数据位置。
     */
    private int lastData;
    private boolean deleteMin;

    public MinHeap(int size, boolean deleteMin) {
        data = new int[size];
        lastData = -1;
        this.size = size;
        this.deleteMin = deleteMin;
    }

    public void add(int num) {
        if (lastData < size - 1) {
            lastData++;
            data[lastData] = num;
            up(lastData);
        }else {
            //堆已满
            if (deleteMin) {
                if (num > data[0]) {
                    data[0] = num;
                    down(0);
                }
            }
        }

    }

    public Integer pop() {
        if (lastData == -1) {
            return Integer.MIN_VALUE;
        }
        int result = data[0];
        data[0] = data[lastData--];
        down(0);
        return result;
    }

    private void up(int location) {
        while (data[location] < data[(location - 1) / 2]) {
            int temp = data[location];
            data[location] = data[(location - 1) / 2];
            data[(location - 1) / 2] = temp;
            location = (location - 1) / 2;
        }
    }

    private void down(int location) {
        while ((location + 1) * 2 <= lastData &&(data[location * 2 + 1] < data[location] || data[(location + 1) * 2] < data[location])) {
            if (data[location * 2 + 1] > data[(location + 1) * 2]) {
                int temp = data[location];
                data[location] = data[(location + 1) * 2];
                data[(location + 1) * 2] = temp;
                location = (location + 1) * 2;
            } else {
                int temp = data[location];
                data[location] = data[location * 2 + 1];
                data[location * 2 + 1] = temp;
                location = location * 2 + 1;
            }
        }
        if (location * 2 + 1 == lastData) {
            if (data[location * 2 + 1] < data[location]) {
                int temp = data[location];
                data[location] = data[location*2 +1];
                data[location * 2 + 1] = temp;
            }
        }
    }
}
}
```