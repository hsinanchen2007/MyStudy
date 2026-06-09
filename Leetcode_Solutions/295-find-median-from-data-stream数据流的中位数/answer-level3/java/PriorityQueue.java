```
class MedianFinder {

    private PriorityQueue<Integer> left;
    private PriorityQueue<Integer> right;
    private Integer[] mid;

    /** initialize your data structure here. */
    public MedianFinder() {
        left = new PriorityQueue<>((a, b)-> b - a + 0);
        right = new PriorityQueue<>((a, b) -> a - b + 0);

        mid = new Integer[2];
        mid[0] = null;
        mid[1] = null;
    }
    
    public void addNum(int num) {
        if (mid[0] == null) {
            mid[0] = num;
            return;
        } 
        if (mid[1] == null) {
            if (left.isEmpty()) {
                mid[1] = num;
                return;
            }
            else {
                if (num > right.peek()) {
                    int temp = right.poll();
                    mid[1] = temp;
                    right.offer(num);
                } else if (num < left.peek()) {
                    int temp = left.poll();
                    mid[1] = temp;
                    left.offer(num);
                } else {
                    mid[1] = num;
                }
            }
        } else {
            int small = Math.min(Math.min(mid[0], mid[1]), num);
            int big = Math.max(Math.max(mid[0], mid[1]), num);
            int d = mid[0] + mid[1] + num - small - big;

            mid[0] = d;
            mid[1] = null;
            left.offer(small);
            right.offer(big);
        }
    }
    
    public double findMedian() {
        if (mid[1] == null) {
            return mid[0] + 0.0;
        }
        return (mid[0] + mid[1] + 0.0)/2.0;
    }
}
```

Space: O(n)
Time: O(n * log n)

执行用时 :77 ms, 在所有 java 提交中击败了99.88% 的用户
内存消耗 :66.5 MB, 在所有 java 提交中击败了74.11%的用户
