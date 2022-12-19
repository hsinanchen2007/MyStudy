## 入队（push）
单次 入队 操作时间复杂度 `O(1)`
```
    public void push(int x) {
        ListNode value = new ListNode(x);
        ListNode temp = head.next;

        if (head.next == null) {
            minValue = x;
        } else {
            if (x < minValue) {
                minValue = x;
            }
        }

        head.next = value;
        value.next = temp;
    }
```

## 出队（pop）
单次 出队 操作最坏情况下的时间复杂度为 `O(n)` 最好情况下的时间复杂度为 `O(1)`
```
    public void pop() {
        if (head.next != null) {
            int currValue = head.next.val;
            head.next = head.next.next;

            if (currValue == minValue) {
                minValue = this.throughMin();
            }
        }
    }
```

## 最小值（getMin）
单次 最小值 操作时间复杂度 `O(1)`
```
    public int getMin() {
        if (head.next != null) {
            return minValue;
        }

        return -1;
    }
```

## 整体实现

``` java
class MinStack {
    private int minValue;
    private ListNode head = null;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        head = new ListNode(-1);
    }

    public void push(int x) {
        ListNode value = new ListNode(x);
        ListNode temp = head.next;

        if (head.next == null) {
            minValue = x;
        } else {
            if (x < minValue) {
                minValue = x;
            }
        }

        head.next = value;
        value.next = temp;
    }

    public void pop() {
        if (head.next != null) {
            int currValue = head.next.val;
            head.next = head.next.next;

            if (currValue == minValue) {
                minValue = this.throughMin();
            }
        }
    }

    public int top() {
        if (head.next != null) {
            return head.next.val;
        }

        return -1;
    }

    public int getMin() {
        if (head.next != null) {
            return minValue;
        }

        return -1;
    }

    private int throughMin() {
        int min = -1;
        ListNode curr = head.next;
        if (curr != null) {
            min = curr.val;

            while (curr != null) {
                if (curr.val < min) {
                    min = curr.val;
                }

                curr = curr.next;
            }
        }

        return min;
    }
}
```
