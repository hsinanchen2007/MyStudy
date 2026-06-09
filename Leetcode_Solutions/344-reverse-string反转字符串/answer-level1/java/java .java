### 解题思路


### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int left = -1;
		int right = s.length;
		while (++left < --right) {
			char c = s[left];
			s[left] = s[right];
			s[right] = c;
		}
    }
}
```