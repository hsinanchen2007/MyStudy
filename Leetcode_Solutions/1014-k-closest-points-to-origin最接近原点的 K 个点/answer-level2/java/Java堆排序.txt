### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/89317ac70416c98bc8061c20d4efc38b32058947ca748c23259d34864e5b3f22-%E6%8D%95%E8%8E%B7.PNG)
问题本身就是个排序问题，堆排序时间空间复杂度都比较低，同时我也是为了加深对堆排序的记忆选择了堆排序
当然这应该是最麻烦的方法，只是效率比较高而已，大家看一看就行，参考价值不大，直接用Java自带的API创建堆就行了

1.建立一个大小为K的大顶堆，初始化排序
2.排好序后，只需要将points中的每个节点距离和heap[0]进行比较，比它小就交换，然后重新整理大顶堆
3.同时创建一个res数组，产生了交换就可以加入结果集，最后返回res


ps:有一个小bug，就是有两个节点等于heap[0]时，会将两个都加入结果集，这有可能会造成结果出错，只是题目给的案例并没有发生错误。不过我一时还没想好判断的步骤，希望大家给点建议。
其实也可以创建一个内部类，重写排序方法，这样就不会出现这种报错了，不过消耗就大一些了。
### 代码

```java
class Solution {
    public static int[][] kClosest(int[][] points, int K) {
        int[] heap = new int[K];
        for (int i = 0; i < K; i++) {
            int dist = dist(points[i][0],points[i][1]);
            heapInsert(heap,dist,i);
        }

        for (int i = K; i < points.length; i++) {
            int dist = dist(points[i][0],points[i][1]);
            if(dist < heap[0]){
                heap[0] = dist;
                makeMaxHeap(heap,0,K);
            }
        }

        int[][] res = new int[heap.length][2];
        int cur = 0;
        for (int i = 0; i < points.length; i++) {
            int dist = dist(points[i][0],points[i][1]);
            boolean contains = false;
            if(dist <= heap[0]){
                res[cur][0] = points[i][0];
                res[cur][1] = points[i][1];
                cur++;
            }
        }
        return res;
    }

    /**
     * 创建初始堆
     * @param heap
     * @param value
     * @param index
     */
    private static void heapInsert(int[] heap, int value, int index) {
        heap[index] = value;
        while(index != 0){
            int parent = (index-1)/2;//父节点
            if(heap[parent] < heap[index]){
                swap(heap,parent,index);
                index = parent;//进行下一次比较
            }else {
                break;
            }
        }
    }

    /**
     * 交换位置
     * @param heap
     * @param index
     * @param target
     */
    private static void swap(int[] heap, int index, int target) {
        int temp = heap[index];
        heap[index] = heap[target];
        heap[target] = temp;
    }

    /**
     * 调整堆排序，最大堆排序
     * @param heap
     * @param index
     * @param k
     */
    private static void makeMaxHeap(int[] heap, int index, int k) {
        int left = index*2 + 1;
        int right = index*2 + 2;
        if(left >= k){
            return;
        }
        int max = left;
        if(right >= k){
            max = left;
        }else {
            if (heap[right] > heap[left]){
                max = right;
            }
        }
        if (heap[index] >= heap[max]){
            return;
        }
        swap(heap,index,max);

        makeMaxHeap(heap,max,k);
    }

    /**
     * 计算距离
     * @param x
     * @param y
     * @return
     */
    private static int dist(int x, int y) {
        return x*x + y*y;
    }
}
```