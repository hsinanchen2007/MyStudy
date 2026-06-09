可以使用优先级队列，因为优先级队列底层结构是小根堆，每次poll取出的都是数组最小值，因此将元素添加到队列中，输出k个即可。
```
public int[] getLeastNumbers(int[] arr, int k) {
        //使用优先级队列进行排序
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for(int i=0;i<arr.length;i++){
            queue.offer(arr[i]);
        }
        //输出前k个
        int[] minArr = new int[k];
        for(int i=0;i<k;i++){
            minArr[i] = queue.poll();
        }
        return minArr;
    }
```
