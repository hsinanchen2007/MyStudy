### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public boolean CheckPermutation(String s1, String s2) {
		List<Character> list1 =name(s1);
		List<Character> list2 =name(s2);
		return list1.equals(list2);

	}
	private  List<Character> name(String s) {
		List<Character> list = new LinkedList<Character>();
		for (int i = 0; i < s.length(); i++) {
			list.add(s.charAt(i));
		}
		Collections.sort(list);
		return list;
	}
}
```