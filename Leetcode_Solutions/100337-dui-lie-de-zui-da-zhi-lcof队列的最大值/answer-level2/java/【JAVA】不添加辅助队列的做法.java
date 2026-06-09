/**
 * 看该方法结果内存100%，运行98%，觉得有必要记录一下。
 * 
 * 此题思路在于如何找到队列中的最大值。考虑到如果直接使用Collection的Queue容器会造成无法遍历元素的问题，
 * 在此选择采用变量存储最大值并使用List存储元素的方式实现，只要能够按照要求返回元素即可不一定非要选用Queue容器。
 * 
 * 首先定义List与最大值元素，然后实现前三个方法，因为List的add方法也是从前向后添加元素，所以元素顺序是可以保证的，
 * 之后判断出队操作，这个地方需要判断出队情况：1.出队元素刚好为最大元素，那么需要遍历List找到第二大的元素，并且替换
 * 现有最大元素执行出队（这个地方可以考虑换成其他的搜索算法来提升效率不一定使用暴力搜索）。2.出队元素不是最大元素，
 * 按照规则出队即可。
 */
class MaxQueue {
        private int maxva = -1;
        private List<Integer> queue;
        public MaxQueue() {
         queue = new ArrayList();
     }

     public int max_value() {
        return maxva;
     }

     public void push_back(int value) {
            if (value > maxva){
                maxva = value;
            }
        queue.add(value);
     }

     public int pop_front() {
            if (queue.size() == 0){
                return -1;
            }
            if (maxva == queue.get(0)){
                int temp = maxva;
                int tem = -1;
                queue.remove(0);
                for (int i=0;i<queue.size();i++){
                    if (queue.get(i) >= tem){
                        tem = queue.get(i);
                    }
                }
                maxva = tem;
                return temp;
            } else {
                int temp = queue.get(0);
                queue.remove(0);
                return temp;
            }

     }
}
