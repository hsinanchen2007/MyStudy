### 解题思路
利用PriorityQueue的特性(使用自然排序法，最小元素先出列)，每次将最小的值反转。然后再累加起来求出数组和。

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        int res = 0;
		PriorityQueue<Integer> queue = new PriorityQueue<>();
		for(int a : A)
		{
            queue.offer(a);
        }
		while(K > 0)
		{
			int a = queue.poll();
	        queue.offer(-a);
	        K--;
	    }
		
		for(int a : queue)
		{
			res += a;
	    }
		return res;
    }
}
```