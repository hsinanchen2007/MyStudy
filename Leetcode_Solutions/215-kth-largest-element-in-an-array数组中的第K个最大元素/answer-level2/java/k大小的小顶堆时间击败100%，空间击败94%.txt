### 解题思路
1.建立一个k个元素大小的小顶堆数组
2.将原数组的前k个放入堆中
3.建立小顶堆
4.将原数组的后续元素与堆进行比较，若有比堆顶元素更大的数，放入堆中，并对堆重排
5.返回堆顶
### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        int[] heap = new int[k];
        for(int i=0;i<k;i++)
            heap[i] = nums[i];
        //建立只有k个元素的小顶堆
        for(int i=k/2;i>=0;i--)
            shift(heap,i,k);
        for(int i=k;i<nums.length;i++)
            //如果原数组的后续元素有比堆顶大的，就放入堆中，重新建立堆
            if(nums[i]>heap[0]){
                heap[0] = nums[i];
                shift(heap,0,k);
            }
        //返回小堆顶元素
        return heap[0];
    }
    //建立小顶堆
    private static void shift(int[] heap,int start,int k){
        //获得当前枝节点的左子节点
        int child = start*2+1;
        while(child<k){
            //左右子节点比较，获取最小的子节点
            if(child+1<k && heap[child]>heap[child+1])
                child++;
            //若枝干节点已经比孩子节点小就不用再比下去了
            if(heap[child]>heap[start])
                return;
            swap(heap,child,start);
            start = child;
            child = start*2+1;
        }
    }
    //交换元素
    private static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```