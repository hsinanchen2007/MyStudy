class MaxQueue {

    // 从数组head处读取数据，每次读完head+1，表示下一次读取数据的位置
    int head = 0;
    // 从数组tail处插入数据，每次插入数据后tail+1，表示下一次插入数据的位置
    int tail = 0;
    int[] arr;

    public MaxQueue() {
        arr = new int[20000];
    }

    public int max_value() {
        int max = -1;
        // 有效的数据范围head到tail(不包括tail，因为tail表示下次插入数据的位置，现在还没数据)
        for (int i = head; i < tail; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }

    public void push_back(int value) {
        arr[tail++] = value;
    }

    public int pop_front() {
        // 当head==tail时，表示已经没有数据可以读取了。之前的数据都读过了
        return head == tail ? -1 : arr[head++];
    }
}