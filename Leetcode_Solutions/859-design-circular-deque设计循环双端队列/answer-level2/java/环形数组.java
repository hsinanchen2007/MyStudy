```
class MyCircularDeque {

    private int[] queue;
    private int head;
    private int size;

    public MyCircularDeque(int k) {
        queue = new int[k];
        head = 0;
        size = 0;
    }

    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        }
        head = (head + queue.length - 1) % queue.length;
        queue[head] = value;
        size ++;
        return true;
    }

    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        }
        queue[(head + size ++) % queue.length] = value;
        return true;
    }

    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % queue.length;
        size --;
        return true;
    }

    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        }
        size --;
        return true;
    }

    public int getFront() {
        return ! isEmpty() ? queue[head] : -1;
    }

    public int getRear() {
        return ! isEmpty() ? queue[(head + size - 1) % queue.length] : -1;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == queue.length;
    }

}
```
