### 解题思路
1. 第一次遍历字符串所有字母；
2. 第二次遍历从第一次遍历的后一位开始；
3. 判断两次遍历的字母是否相等，一旦相等则返回`false`；
4. 默认返回`true`；

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for (int i = 0; i < astr.length() - 1; i++) {
			for (int j = i + 1; j < astr.length(); j++) {
				if (astr.charAt(i) == astr.charAt(j)) {
					return false;
				}
			}
		}
		return true;
    }
}
```