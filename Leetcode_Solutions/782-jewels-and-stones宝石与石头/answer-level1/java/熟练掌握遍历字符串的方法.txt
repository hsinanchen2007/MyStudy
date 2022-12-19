### 解题思路
遍历思想很好理解，关键是遍历字符串的方法需熟练
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.88%
的用户
内存消耗 :
38 MB
, 在所有 Java 提交中击败了
5.01%
的用户
### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int ans=0;
    	for (char s : S.toCharArray()) {    //for each stone
			for (char j : J.toCharArray()) {    //for each jewel
				if (s==j) {
					ans++;
					break;
				}
			}
		}
    	return ans;
    }
}
```