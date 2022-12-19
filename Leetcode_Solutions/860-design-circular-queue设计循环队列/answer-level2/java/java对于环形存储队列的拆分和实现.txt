
根据自己的思路简单拆分了一下，增加可读性
一个是数组存储器，另一个是环形指针组


```java
package com.aizain.jhome.computer.data.queue.demo;

import lombok.extern.slf4j.Slf4j;

import java.util.Arrays;

/**
 * SimpleCircularQueue
 *
 * @author Zain
 * @date 2019/10/28
 */
@Slf4j
class SimpleCircularQueue {

    private static final int FIRST = 0;
    private static final int EMPTY = -1;

    private QueueStore queueStore;
    private CircularPointer pointer;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public SimpleCircularQueue(int size) {
        queueStore = new QueueStore(size);
        pointer = new CircularPointer(size);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int data) {
        if (isEmpty()) {
            pointer.setFirst();
            boolean ret = queueStore.setData(pointer.getTail(), data);
            log.debug("enQueue first, queue {}", this);
            return ret;
        }

        if (isFull()) {
            log.debug("enQueue full, queue {}", this);
            return false;
        }
        boolean ret = queueStore.setData(pointer.incTail(), data);
        log.debug("enQueue, queue {}", this);
        return ret;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {

        if (!queueStore.removeData(pointer.getHead())) {
            log.debug("deQueue failed, queue {}", this);
            return false;
        }
        if (pointer.isSameSetEmpty()) {
            log.debug("deQueue empty, queue {}", this);

            return true;
        }

        pointer.incHead();

        log.debug("deQueue, queue {}", this);
        return true;
    }

    /** Get the front item from the queue. */
    public int Front() {
        return queueStore.getData(pointer.getHead());
    }

    /** Get the last item from the queue. */
    public int Rear() {
        return queueStore.getData(pointer.getTail());
    }

    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return queueStore.isEmpty();
    }

    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return queueStore.isFull();
    }

    private static class QueueStore {
        private int[] array;
        private int size;

        public QueueStore(int maxSize) {
            array = new int[maxSize];
            this.size = 0;
        }

        public boolean isFull() {
            return size >= array.length;
        }

        public boolean isEmpty() {
            return size <= 0;
        }

        public int getData(int index) {
            if (isEmpty() || isIndexOutRange(index)) {
                return EMPTY;
            }

            return array[index];
        }

        public boolean setData(int index, int data) {
            if (isFull() || isIndexOutRange(index)) {
                return false;
            }

            array[index] = data;
            size++;
            return true;
        }

        public boolean removeData(int index) {
            if (isEmpty() || isIndexOutRange(index)) {
                return false;
            }

            array[index] = EMPTY;
            size--;
            return true;
        }

        public int getSize() {
            return size;
        }
        private boolean isIndexOutRange(int index) {
            if (index >= array.length || index <= EMPTY) {
                return true;
            }
            return false;
        }
    }

    private static class CircularPointer {
        private int head;
        private int tail;
        private int max;

        public CircularPointer(int max) {
            this.max = max;
            setEmpty();
        }

        public boolean isSameSetEmpty() {
            if (head == tail) {
                setEmpty();
                return true;
            }
            return false;
        }

        public void setFirst() {
            this.head = FIRST;
            this.tail = FIRST;
        }

        public void setEmpty() {
            this.head = EMPTY;
            this.tail = EMPTY;
        }

        public int incTail() {
            tail++;
            if (tail >= max) {
                tail = FIRST;
            }

            return tail;
        }

        public int incHead() {
            head++;
            if (head >= max) {
                head = FIRST;
            }

            return head;
        }

        public int getHead() {
            return head;
        }

        public int getTail() {
            return tail;
        }

    }

    @Override
    public String toString() {
        return "Queue{" + "array=" + Arrays.toString(queueStore.array) +
                ", size=" + queueStore.getSize() +
                ", head=" + pointer.getHead() +
                ", tail=" + pointer.getTail() +
                '}';
    }
}
```
