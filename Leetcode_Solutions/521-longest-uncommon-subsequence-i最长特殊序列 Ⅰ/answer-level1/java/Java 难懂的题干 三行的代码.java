### 解题思路

如果两个字符串长度不一样，则较长的字符串本身不可能是短字符串的子序列，直接返回其长度即可
如果两个字符串内容相等，那么他们独有的最长子序列不存在，返回 -1

### 代码

```java
class Solution {
    public int findLUSlength(String a, String b) {
        if(a.equals(b)) return -1;
		else {
			return a.length()>b.length()? a.length():b.length();
		}
    }
}
```