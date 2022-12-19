### 解题思路
遍历字符串，LR数目相等归零，对数+1。
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
37.3 MB
, 在所有 Java 提交中击败了
5.10%
的用户

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int i=0,j=0,k=0;
    	for (char c : s.toCharArray()) {
    		if (c=='L') {
				i++;
			}else {
				j++;
			}
    		if (i==j&&i!=0) {
				k++;
				i=0;
				j=0;
			}
		}
		return k;
    }
}
```