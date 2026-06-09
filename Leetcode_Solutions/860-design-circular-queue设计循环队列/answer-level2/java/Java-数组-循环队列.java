队头指针font，队尾指针rear，数组data[]，获取队头getFont()，获取队尾getRear()，队列规模size
根据leecode数据结构教程的循环队列演示的来定义各个条件
1. 初始条件：`font = rear = -1`
2. 队空条件：`font == -1 && rear == -1`
3. 队头和队尾指针指向队列的队头和队尾，即队头数值为队头下标，队尾数值为队尾下标（`data[font] = getFont(); data[rear] = getRear();`）

根据以上条件可以推断出其他的条件
1. 队满条件：`(rear + 1) % size == font`
2. 入队时：若队空，可以设置`rear = font = 0`；若队不为空且不满，队尾指针加一：`(rear + 1) % size`；最后赋值`data[rear] = value`.若队满，返回false
3. 出队时：若队空，返回false。若只有一个元素，则出队后队列为空，可以直接设置队空的条件`rear = false = -1`

示例
```
class MyCircularQueue {
    private int[] data;
    private int font;
    private int rear;
    private int size;

    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     */
    public MyCircularQueue(int k) {
        data = new int[k];
        font = rear = -1;
        size = k;
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     */
    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            if(isEmpty()){
                font = 0;
            }
            rear = (rear + 1) % size;
            data[rear] = value;
            return true;
        }
    }

    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     */
    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            //如果此时rear==font，则设置队列为空
            if(rear == font){
                rear = font = -1;
            } else {
                font = (font + 1) % size;
            }
            return true;
        }
    }

    /**
     * Get the front item from the queue.
     */
    public int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[font];
        }
    }

    /**
     * Get the last item from the queue.
     */
    public int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[rear];
        }
    }

    /**
     * Checks whether the circular queue is empty or not.
     */
    public boolean isEmpty() {
        return rear == -1 && font == -1;
    }

    /**
     * Checks whether the circular queue is full or not.
     */
    public boolean isFull() {
        return (rear + 1) % size == font;
    }
}


```


