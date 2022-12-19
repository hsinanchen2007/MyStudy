建议与《两个栈实现队列》一题一起做
```
class MyStack {
        // master用来保存数据，slave为辅助队列用来转移数据
        Deque<Integer> master, slave;
        Integer top = null;

        public MyStack() {
            master = new LinkedList<>();
            slave = new LinkedList<>();
        }

        public void push(int x) {
            master.offerLast(x);
            top = x;
        }
        
        /* 一段写得不好的代码
        public int pop() {
            if (master.size() == 1) {
                top = null;
                return master.pollFirst();
            }
            while (master.size() != 2) {
                slave.offerLast(master.pollFirst());
            }
            top = master.pollFirst();
            slave.offerLast(top);
            Integer pop = master.pollFirst();
            Deque<Integer> temp = master;
            master = slave;
            slave = temp;
            return pop;
        }*/

        public int pop() {
            while (master.size() > 1) {
                top = master.pollFirst();
                slave.offerLast(top);
            }
            Integer pop = master.pollFirst();
            Deque<Integer> temp = master;
            master = slave;
            slave = temp;
            return pop;
        }

        public int top() {
            return top;
        }

        public boolean empty() {
            return master.isEmpty();
        }
    }
```
