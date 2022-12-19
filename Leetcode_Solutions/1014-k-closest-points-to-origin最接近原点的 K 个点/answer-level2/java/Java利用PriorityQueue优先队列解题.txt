1. 先创建一个优先队列，给定优先级条件
2. 循环将二维数组中的元素拆成一维数组装到优先队列
3. 取出前K个数组
 **下面是代码实现**
```
public int[][] kClosest(int[][] points, int K) {
    PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((a,b)->{
        double aq = Math.pow(a[0],2)+Math.pow(a[1],2);
        double bq = Math.pow(b[0],2)+Math.pow(b[1],2);
        if(bq>aq){
            return -1;
        }else if (bq==aq){
            return 0;
        }else{
            return 1;
        }
    });
    for (int i = 0; i < points.length; i++) {
        priorityQueue.offer(points[i]);
    }
    int[][] result = new int[K][];
    for (int i = 0; i < K; i++) {
        result[i] = priorityQueue.poll();
    }
    return result;
}
```
