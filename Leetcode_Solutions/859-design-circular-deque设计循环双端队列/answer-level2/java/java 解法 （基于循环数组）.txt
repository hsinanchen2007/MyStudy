```java
public class MyCircularDeque {
    private int size;
    private int[] data;
    private int head;
    private int tail;

    public MyCircularDeque(int k) {
        this.data = new int[k];
        this.size = 0;
        this.head = -1;
        this.tail = -1;
    }


    public boolean insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(head - 1 < 0){
            head = data.length -1;
        } else{
            head--;
        }
        if(size == 0){
            tail = head;
        }
        data[head] = value;
        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if(isFull()){
            return false;
        }
        tail = (tail+1)%data.length;
        data[tail] = value;
        if(size == 0){
            head = tail;
        }
        size++;
        return true;
    }

    public boolean deleteFront() {
        if(isEmpty()){
            return false;
        }
        head = (head+1)%data.length;
        size--;
        return true;
    }

    public boolean deleteLast() {
        if(isEmpty()){
            return false;
        }
        if(tail - 1 < 0){
            tail = data.length-1;
        }else{
            tail--;
        }
        size--;
        return true;
    }

    public int getFront() {
        if(isEmpty()){
            return -1;
        }
        return data[head];
    }

    public int getRear() {
        if(isEmpty()){
            return -1;
        }
        return data[tail];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == data.length;
    }

}
