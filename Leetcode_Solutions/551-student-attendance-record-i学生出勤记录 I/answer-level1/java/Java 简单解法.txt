### 解题思路

解决这个问题最简单的方法就是统计字符串中 A 的数目并检查 LLL 是否是给定字符串的一个子串。如果 A 的数目比 22 少且 LLL 不是给定字符串的一个子串，那么返回 true，否则返回 false 。

Java contains() 方法可以用来检查一个串是否是另一个串的子串。


### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
		char a[] = s.toCharArray();
		int count = 0;
		for(int i=0;i<a.length;i++) {
			if(a[i]=='A') count++;
		}
		return count<2 && !s.contains("LLL");
    }
}
```