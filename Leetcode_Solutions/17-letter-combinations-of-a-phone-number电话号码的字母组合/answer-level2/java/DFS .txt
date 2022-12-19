### 解题思路
使用递归的思路

### 代码

```java
class Solution {
    /**
	 * DFS 深度优先搜索算法
	 * @param digits 
	 * @return
	 */
	public List<String> letterCombinations(String digits) {
		LinkedList<String> queue = new LinkedList<String>();
		if (digits.isEmpty()) {
			return queue;
		}
		String[] table = new String[] { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		
		deep(queue, table, digits, 0, new String(""));
		
		return queue;
	}

	private void deep(LinkedList<String> queue, String[] table, String digits, int i, String s) {
		if (digits.length() == i) {
			queue.add(s);
			return;
		}
		String abc = table[digits.charAt(i) - '0'];
		for (char c : abc.toCharArray()) {
			deep(queue, table, digits, i + 1, s + c);
		}
		
	}
}
```