### 解题思路
1. 从字符串0位置开始，此位置的字符和后面的字符交换，然后再处理后面位置的字符串
2. 可以看出这是重复操作，直到到了最后一个字符
3. HashSet去重
4. 优化点：自身不与自己交换

### 代码

```java
class Solution {
    public String[] permutation(String s) {
		if (s == null || s.length() == 0)
			return new String[0];
		Set<String> res = new HashSet<>();
		dopermutation(s.toCharArray(), 0, res);
		return res.toArray(new String[res.size()]);
	}

	private void dopermutation(char[] array, int start, Set<String> res) {
		if (start == array.length - 1) {
			res.add(new String(array));
			return;
		}
		int exchange = start;
		while (exchange < array.length) {
			char tmp = array[start];
			array[start] = array[exchange];
			array[exchange] = tmp;
			dopermutation(array, start + 1, res);
			tmp = array[start];
			array[start] = array[exchange];
			array[exchange] = tmp;
			exchange++;
		}
	}
}
```