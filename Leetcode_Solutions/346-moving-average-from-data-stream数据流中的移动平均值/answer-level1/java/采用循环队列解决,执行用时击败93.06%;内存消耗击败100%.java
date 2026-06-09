```
class MyCircularQueue {
    private int[] _Data;
    private int _Head;
    private int _Tail;
    private int _Size;

    // 构造器,设置队列长度为k
    public MyCircularQueue(int k) {
        _Data = new int[k];
        _Head = -1;
        _Tail = -1;
        _Size = k;
    }

    public int GetSize() {
        return _Size;
    }

    public int GetSum() {
        int _sum = 0;
        for (int _i : _Data) {
            _sum += _i;
        }
        return _sum;
    }

    // 向循环队列插入一个元素.如果成功插入则返回真
    public boolean enQueue(int value) {
        if (this.isFull()) {
            return false;
        }
        if (this.isEmpty() == true) {
            _Head = 0;
        }
        _Tail = (_Tail + 1) % _Size;
        _Data[_Tail] = value;
        return true;
    }

    // 从循环队列中删除一个元素.如果成功删除则返回真
    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (_Head == _Tail) {
            _Head = _Tail = -1;
        } else {
            _Head = (_Head + 1) % _Size;
        }
        return true;
    }

    // 从队首获取元素.如果队列为空,返回-1
    public int Front() {
        if (isEmpty()) {
            return -1;
        }
        return _Data[_Head];
    }

    // 获取队尾元素.如果队列为空,返回-1
    public int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return _Data[_Tail];
    }

    // 检查循环队列是否为空
    private boolean isEmpty() {
        return _Head == -1;
    }

    // 检查循环队列是否已满
    public boolean isFull() {
        return ((_Tail + 1) % _Size) == _Head;
    }
}

class MovingAverage {
    MyCircularQueue _Queue;
    int _Count = 0;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        _Queue = new MyCircularQueue(size);
    }

    public double next(int val) {
        boolean _isFull=_Queue.isFull();
        if (_isFull) {
            _Queue.deQueue();
        }
        _Queue.enQueue(val);
        if (_isFull) {
            return (double) _Queue.GetSum() / _Queue.GetSize();
        } else {
            _Count++;
            return (double) _Queue.GetSum() / _Count;
        }
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```

采用循环队列来处理该问题.因为我不熟悉Java中Queue的类,所以采用自己实现的队列类来处理.