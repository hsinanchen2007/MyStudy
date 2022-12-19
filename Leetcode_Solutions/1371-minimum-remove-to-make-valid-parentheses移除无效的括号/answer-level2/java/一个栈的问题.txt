### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   	/**
	 * 2个规则， 1，左括弧和you括弧数目一致，其次，必须先左括弧，再右括弧， 若是右括弧多，直接删除，
	 * 
	 * @param s
	 * @return
	 */
	public String minRemoveToMakeValid(String s) {
		Stack<Integer> leftStack = new Stack<>();
		HashSet<Integer> deleteSet = new HashSet<>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				leftStack.add(i);
			} else if (s.charAt(i) == ')') {
				if (leftStack.size() == 0)
					deleteSet.add(i);
				else
					leftStack.pop();
			}
		}
		for (int i = 0; i < leftStack.size(); i++) {
			deleteSet.add(leftStack.get(i));
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			if (!deleteSet.contains(i)) {
				sb.append(s.charAt(i));
			}
		}

		return sb.toString();

	}

}
```