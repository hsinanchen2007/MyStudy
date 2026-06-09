class BoundedBlockingQueue {
    int capacity;
    Node first;
    Node last;
    AtomicInteger size = new AtomicInteger();
    Semaphore s;
    Semaphore s2 = new Semaphore(0);
    public BoundedBlockingQueue(int capacity) {
        this.capacity = capacity;
        s = new Semaphore(capacity);
    }

    public void enqueue(int element) throws InterruptedException {
        s.acquire();
        Node newNode = new Node(element);
        Node f = first;
        newNode.next = f;
        first = newNode;
        if (last == null) {
            last = newNode;
        } else {
            f.pre = newNode;
        }
        size.getAndIncrement();
        s2.release();


    }

    public int dequeue() throws InterruptedException {
        s2.acquire();
        int x = last.val;
        size.getAndDecrement();
        // --------------
        Node l = last;
        Node p = l.pre;
        l.pre = l;
        last = p;
        if (p == null) {
            first = null;
        } else {
            p.next = null;
        }
        s.release();
        return x;
    }

    public int size() {
        return size.get();
    }


    class Node {
        int val;
        Node pre = null;
        Node next = null;

        Node(int v) {
            this.val = v;
        }
    }
}