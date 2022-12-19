### 解题思路
####前提操作
1. 首先完成swim和sink实现
2. 一个变量N记录heap中元素个数
3. 一个变量size记录heap的大小
####思路（一边add一边构造堆）
**注意：**堆由索引1开始
1. 若当前堆不满，则直接插入到数组后一位，并且swim上移
2. 若当前堆满，则与heap[1]比较大小，大于则替换，并且sink下移
3. 若比heap[1]小或者等于，直接舍去。
4. 返回值即为heap[1]

### 代码

```java
class KthLargest {
    private int N = 1;//记录heap中的元素个数
    private int heap[];
    private int size;//记录heap的大小

    public KthLargest(int k,int[] nums)
    {
        heap = new int[k+1];
        size = k;
        for(int i =0; i < nums.length; i++)
            add(nums[i]);
    }

    public int add(int val) {
        if(N < heap.length)
        {
            heap[N] = val;
            swim(N);
            N++;
        }
        else
        {
            if(val > heap[1])
            {
                heap[1] = val;
                sink(1);
            }
        }
        return heap[1];
    }
    private void swap(int i,int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private void swim(int k)
    {
        while(k > 1 && heap[k/2] > heap[k])
        {
            swap(k/2,k);
            k = k/2;
        }

    }
    private void sink(int k)
    {
        while(2*k <= size)
        {
            int j = 2*k;
            if(j+1 <= size && heap[j] > heap[j+1]) j++;
            if(heap[j] > heap[k]) break;
            swap(j,k);
            k = j;
        }
    }
}
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```