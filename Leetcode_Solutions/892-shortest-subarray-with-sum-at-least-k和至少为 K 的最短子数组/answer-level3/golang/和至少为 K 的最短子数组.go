### 解题思路
前缀和+单调队列

### 代码

```golang []
func shortestSubarray(A []int, K int) int {
	prefixSum := make([]int, len(A)+1)
	shLen := math.MaxInt32
	for i, a := range A {
		prefixSum[i+1] = prefixSum[i] + a
	}
	queue := make([]int, 1, len(prefixSum))
	for i := 1; i < len(prefixSum); i++ {
		for len(queue) > 0 && prefixSum[queue[len(queue)-1]] >= prefixSum[i] {
			queue = queue[:len(queue)-1]
		}
		queue = append(queue, i)
		diff := prefixSum[queue[len(queue)-1]] - K
		for len(queue) > 1 && diff >= prefixSum[queue[0]] {
			l := i - queue[0]
			if l < shLen {
				shLen = l
			}
			queue = queue[1:]
		}
	}
	if shLen == math.MaxInt32 {
		return -1
	}
	return shLen
}

```

```java []
class Solution {
    public int shortestSubarray(int[] arr, int k) {
        int[] prefixSum = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
        Deque<Integer> deque = new ArrayDeque<>();
        deque.addFirst(0);
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < prefixSum.length; i++) {
            while (!deque.isEmpty() && prefixSum[deque.getLast()] >= prefixSum[i]) {
                deque.removeLast();
            }
            deque.addLast(i);
            int diff = prefixSum[i] - k;
            while (deque.size() > 1 && diff >= prefixSum[deque.getFirst()]) {
                ans = Math.min(ans, i - deque.getFirst());
                deque.removeFirst();
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
```