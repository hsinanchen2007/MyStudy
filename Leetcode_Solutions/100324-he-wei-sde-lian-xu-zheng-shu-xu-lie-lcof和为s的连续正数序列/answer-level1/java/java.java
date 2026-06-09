### 解题思路
java返回一个二维数组 属实不好写，想到使用hashmap数组长度和第一个数，结果map的key没有排序，于是又加了一个栈，因为n变大，所以a1逐渐变小，但时间耗费好多，希望给位多给点建议

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int a1 = 1;
		int n = 2;
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		Stack<Integer> stack = new Stack<Integer>();
		while (a1 > 0) {
			int temp = target - n * (n - 1) / 2;
			a1 = temp / n;
			if(temp % n == 0 && temp > 0) {
				map.put(a1,n);
				stack.add(a1);
			}

			n++;
		}
		int[][] arr = new int[map.size()][];
		int i = 0;
		while(!stack.isEmpty()) {
			int key = stack.pop();
			int[] p = new int[map.get(key)];
			for (int j = 0; j < p.length; j++) {
				p[j] = key++;
			}
			arr[i++] = p;
		}
		return arr;
	}
}
```