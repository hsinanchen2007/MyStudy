大写和小写直接判断一样不一样，

其余直接判断首字母和其他字母的规则，否和程度和长度比较



```java
public class Solution {

	public boolean detectCapitalUse(String word) {
		if (word.toUpperCase().equals(word) || word.toLowerCase().equals(word)) {
			return true;
		}
		int count = 0;
		for (int i = 0; i < word.length(); i++) {
			if (word.charAt(i) >= 'A' && word.charAt(i) <= 'Z' && i == 0) {
				count++;
			} else if (word.charAt(i) >= 'a' && word.charAt(i) <= 'z' && i != 0) {
				count++;
			}
		}
		return count == word.length();
	}

}
```