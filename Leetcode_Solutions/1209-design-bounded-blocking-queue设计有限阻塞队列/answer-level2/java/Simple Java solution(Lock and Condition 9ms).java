### 解题思路

通过 `notFull` 和  `notEmpty` 两个条件变量来控制阻塞等待

### 代码

```java
class BoundedBlockingQueue {

    private final Lock lock = new ReentrantLock();

    private final AtomicInteger size = new AtomicInteger();

    private final int capacity;

    Condition notEmpty = lock.newCondition();
    Condition notFull = lock.newCondition();

    public BoundedBlockingQueue(int c) {
        capacity = c;
    }

    public void enqueue(int element) throws InterruptedException {
        int currSize = -1;
        final Lock lock = this.lock;
        final AtomicInteger size = this.size;
        Node newNode = new Node(element);
        lock.lockInterruptibly();
        try {
            while (size.get() == capacity) {
                notFull.await();
            }

            Node f = first;
            newNode.next = f;
            first = newNode;
            if (last == null) {
                last = newNode;
            } else {
                f.prev = newNode;
            }
            notEmpty.signal();
            currSize = size.getAndIncrement();
            if (currSize + 1 < capacity) {
                notFull.signal();
            }
        } finally {
            lock.unlock();
        }
    }

    public int dequeue() throws InterruptedException {
        int currSize = -1;
        final Lock lock = this.lock;
        final AtomicInteger size = this.size;
        lock.lockInterruptibly();
        try {
            while (size.get() == 0) {
                notEmpty.await();
            }

            Node l = last;
            Node p = l.prev;
            int val = l.val;
            l.prev = l;
            last = p;
            if (p == null) {
                first = null;
            } else {
                p.next = null;
            }

            currSize = size.getAndDecrement();
            notFull.signal();
            if (currSize > 1) {
                notEmpty.signal();
            }
            return val;
        } finally {
            lock.unlock();
        }
    }

    public int size() {
        return size.get();
    }

    class Node {
        int val;
        Node next;
        Node prev;

        public Node(int val) {
            this.val = val;
        }
    }

    private Node first;
    private Node last;
}
```