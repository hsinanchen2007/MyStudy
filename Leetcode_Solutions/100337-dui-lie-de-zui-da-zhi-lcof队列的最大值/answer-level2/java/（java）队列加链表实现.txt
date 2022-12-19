# 思路
- 队列的实现使用java内置的LinkedList实现，我们在不改变队列顺序的情况下，只能采用另一个链表储存大小顺序。
- 在push时可以进行判断，顺便将链表排序，这样就大大减少了用时
- 删除的时候可以使用ArrayList的内置函数remove将需要pop的数值删除。
# 代码实现
```
    class MaxQueue {
        Queue<Integer>queue=new LinkedList<>();
        ArrayList<Integer>maxlist=new ArrayList<>();
        public MaxQueue() {

        }

        public int max_value() {
            if(queue.size()==0)
                return -1;
            return maxlist.get(0);
        }

        public void push_back(int value) {
            queue.offer(value);
            if(maxlist.size()==0)
                maxlist.add(value);
            else {
                for(int i=0;i<maxlist.size();i++)
                {
                    if(maxlist.get(i)<value)
                    {
                        maxlist.add(i,value);
                        return;
                    }
                }
                maxlist.add(value);
            }
        }
        public int pop_front() {
            if(queue.size()==0)
                return -1;
            int va=queue.poll();
            maxlist.remove(maxlist.indexOf(va));
            return va;
        }
    }
```
