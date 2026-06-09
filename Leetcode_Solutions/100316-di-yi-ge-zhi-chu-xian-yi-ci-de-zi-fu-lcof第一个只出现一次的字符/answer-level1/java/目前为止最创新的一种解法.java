### 解题思路
- 先反向遍历，得到每一个字符的第一次出现的位置
- 然后正向遍历，判断当前字符的反向第一次出现位置是否与现在相等
- 如果不相等则要删除当前字符，然后继续遍历
### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
      if (s == null || s.length() == 0)
			return ' ';
		HashMap<Character, Integer> counter = new HashMap<>();
		for (int i = s.length() - 1; i >= 0; i--) {
			counter.putIfAbsent(s.charAt(i), i);
		}
		for (int i = 0; i < s.length(); i++) {
			if (i == counter.getOrDefault(s.charAt(i), -1))
				return s.charAt(i);
			else
				counter.remove(s.charAt(i));
		}
		return ' ';
    }
}
```