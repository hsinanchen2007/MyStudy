顺序队列实行先进先出的原则，需要加上front和rear两个变量分别指示队首和队尾在数组中的位置，初值为0。

在非空队列中，front指向队首元素，rear指向队尾元素的下一个存储位置。


由于顺序队列中会产生假溢出的情形，例如一个有6个存储空间的队列存满，并且出队2次之后，

我们无法在第七个存储空间继续入队，但实际上此队列在前方仍然有两个空余的存储空间。



解决这个问题，最好的办法就是将顺序队列看成是一个逻辑上首位相连的循环队列，

转换可以用rear=(rear+1)%maxSize来实现。



在循环队列中会有一个问题：无法区分队空和队满的状态，因为队空和队满的条件都是rear==front。



解决方法有少用一个存储单元，设置一个标志变量，设置一个计数器3种方法，

这里我们使用少用一个存储单元，即队空的条件为rear==front, 队满的条件为front=(rear+1)%maxSize。

```
package com.huawei.leetcode;

/**
 * https://leetcode-cn.com/problems/design-circular-queue/comments/
 * @since 2019-11-19
 */
public class MyCircularQueue {
    // 数据
    private int[] data;
    // 表示队列队首，始终指向队列中的第一个元素
    private int front;
    // 表示队列队尾，始终指向队列中的最后一个元素的下一个位置
    private int tail;

    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     */
    public MyCircularQueue(int k) {
        data = new int[k + 1];
        front = 0;
        tail = 0;
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     */
    public boolean enQueue(int value) {
        if (!isFull()) {
            data[tail] = value;
            tail = (tail + 1) % data.length;
            return true;
        } else {
            return false;
        }
    }

    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     */
    public boolean deQueue() {
        if (!isEmpty()) {
            front = (front + 1) % data.length;
            return true;
        } else {
            return false;
        }
    }

    /**
     * Get the front item from the queue.
     */
    public int Front() {
        if (!isEmpty()) {
            return data[front];
        } else {
            return -1;
        }
    }

    /**
     * Get the last item from the queue.
     */
    public int Rear() {
        if (!isEmpty()) {
            return tail == 0 ? data[data.length -1] : data[tail - 1];

        } else {
            return -1;
        }
    }

    /**
     * Checks whether the circular queue is empty or not.
     */
    public boolean isEmpty() {
        return tail % data.length == front % data.length;
    }

    /**
     * Checks whether the circular queue is full or not.
     */
    public boolean isFull() {
        return (tail + 1) % data.length == (front) % data.length;
    }

}

```
