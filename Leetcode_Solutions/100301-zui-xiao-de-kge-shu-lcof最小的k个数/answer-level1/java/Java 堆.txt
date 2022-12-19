理解堆的思想解决这道题非常容易，根据题意需要构建一个最大堆。
因为Java内置的PriorityQueue是最小堆，所以需要重写比较器使它转换为最大堆。

`import java.util.PriorityQueue;

class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {

        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a);

        for(int n:arr){
            //也可以不用判断，直接pq.add(n); 耗时会加长一些。    
            if (pq.isEmpty() || pq.size() < k || n < pq.peek()) {
                pq.add(n);
        }
            if(pq.size()>k)
                pq.remove();
        }

        int[] res = new int[k];
        for(int i = 0; i < res.length; i ++){
            res[i] = pq.remove();
        }
        return res;
    }
}`