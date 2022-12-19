```
class MovingAverage {

    LinkedBlockingQueue<Integer> queue;
        double sums;
        /** Initialize your data structure here. */
        public MovingAverage(int size) {
            this.queue = new LinkedBlockingQueue(size);
        }

        public double next(int val){
            if (queue.remainingCapacity() != 0){
                queue.offer(val);
                sums += val;
            }else{
                sums += (val - queue.poll());
                queue.offer(val);
            }
            return sums/queue.size();
        }
}
```
