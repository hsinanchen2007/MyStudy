# 前k系列一般来讲都是经典的双堆系列题：


记住口诀：找最大用小顶堆，找最小用大顶堆，简称“小顶找大，大顶找小”
具体来说就是利用了堆保持最大或最小在顶部的特性，并且用堆的size来控制找的个数（也就是k）
这道题就是大顶找最小
上代码：
```
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] res = new int[k];
        if(k == 0){
            return res;
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>(Collections.reverseOrder());
        for(int n:arr){
            if(heap.size() < k){
                heap.add(n);
            }else if(heap.peek() >= n){
                heap.remove();
                heap.add(n);
            }
        }
        int i=0;
        for(int n:heap){
            res[i] = n;
            i++;
        }
        return res;
    }
}
```
相似例题传送门在这里：
[347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/)
[215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)