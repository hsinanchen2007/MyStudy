```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] res = new int[k];
        if(arr.length<0 || k<=0) return res;
        // 创建一个大顶堆,根结点元素最大
        Queue<Integer> pq = new PriorityQueue<>((v1, v2) -> v2 - v1);
        for(int i=0;i<arr.length;i++){
            if(pq.size()<k){
                pq.add(arr[i]);
            }else if(pq.peek()>arr[i]){
                pq.remove(pq.peek());
                pq.add(arr[i]);
            }
        }
        int index =0;
        for(int e: pq){
            res[index++]=e;
        }
        return res;
    }
}
```
