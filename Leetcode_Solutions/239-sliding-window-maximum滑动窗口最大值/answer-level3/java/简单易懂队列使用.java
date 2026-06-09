维护一个递减的队列的索引，头部拥有是最大的数字的索引，在不断移动的过程，会尝试清除一下不符合规定的索引：
1. 太老了，或者说是过时的最大的数字的索引 i - k （窗口已经不再包含该索引）
2. 当前索引的数字比前面的数字还大的时候，可以清除前面的索引，因为要滚出窗口也是它们先滚出去，所以没有必要留着它们

```java
        int length = nums.length;
        if (length * k == 0) {
            return new int[0];
        }
        Deque<Integer> deque = new ArrayDeque<>();
        int[] result = new int[length - k + 1];
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!deque.isEmpty() || deque.size() > k) {
                if (deque.peekFirst() == i - k) {
                    deque.removeFirst();
                }
                while (!deque.isEmpty() && nums[i] > nums[deque.getLast()]) {
                    deque.removeLast();
                }
            }
            deque.offerLast(i);
            if (i >= k - 1 || i == length - 1) {
                result[count++] = nums[deque.peekFirst()];
            }

        }
        return result;
```