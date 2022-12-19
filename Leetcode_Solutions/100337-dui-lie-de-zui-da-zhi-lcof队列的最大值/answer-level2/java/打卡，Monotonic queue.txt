    // 往第二个队列里添加数据要始终保持队列里值是单调递增的
    class MaxQueue {
        Queue<Integer> queue;
        LinkedList<Integer> maxlist;     // Monotonic queue
        public MaxQueue() {
            queue = new LinkedList<>();
            maxlist = new LinkedList<>();
        }
        
        public int max_value() {
            if(maxlist.isEmpty()) {
                return -1;
            }
            return maxlist.peekFirst();
        }
        
        public void push_back(int value) {
            queue.offer(value);
            while(!maxlist.isEmpty() && maxlist.peekLast() < value) {
                maxlist.pollLast();
            }
            maxlist.addLast(value);
        }
        
        public int pop_front() {
            if(queue.isEmpty()) {
                return -1;
            }
            int temp = queue.poll();
            if(temp == maxlist.peekFirst()) {
                maxlist.pollFirst();
            }
            return temp;
        }
    }