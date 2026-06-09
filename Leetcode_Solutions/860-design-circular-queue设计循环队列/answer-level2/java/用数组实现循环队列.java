
```
class MyCircularQueue {
    private int head = -1;
    private int tail = -1;
    private int[] intArray;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        intArray = new int[k];
    }
    
   /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if(isEmpty()){
            intArray[0] = value;
            head = tail = 0;
            return true;
        } else {
            if(isFull()){
                return false;
            } else {
                if (tail == intArray.length-1){
                    intArray[0] = value;
                    tail = 0;
                } else {
                    intArray[tail+1] = value;
                    tail = tail+1;
                }
                return true;
            }
        }

    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (isEmpty()){
            return false;
        } else {
            if(head==tail){
                head = tail = -1;
            } else {
                if (head == intArray.length - 1){
                    head = 0;
                } else {
                    head = head + 1;
                } 
            }
            return true;
        }
    }

    /** Get the front item from the queue. */
    public int Front() {
        return head == -1? -1 : intArray[head];
    }

    /** Get the last item from the queue. */
    public int Rear() {
        return tail == -1? -1 : intArray[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return head==-1 ;
    }

    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        if (head == 0 && tail == intArray.length-1){
            return true;
        } else if(head-tail == 1){
            return true;
        } else {
            return  false;
        }
    }
}

```
