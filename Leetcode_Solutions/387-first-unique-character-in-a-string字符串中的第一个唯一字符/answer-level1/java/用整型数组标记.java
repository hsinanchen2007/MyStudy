### 解题思路
与输出不重复随机数的思想类似，或用boolean数组或用整型数组标记出现字母，再次遍历将其挑出。

### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        int[]letter=new int[26];   //由于题目已经声明只会出现26个小写字母
    	char[]chars = s.toCharArray();
    	for (char c : chars) {
    		letter[c-'a']++;       //标记出出现过的字母
		}
    	for (int i = 0; i < chars.length; i++) {
			if (letter[chars[i]-'a']==1) {
				return i;          //出现标记过并只出现一次的字母即返回
			}
		}
    	return -1;                 //若没有则返回-1
    }
}
```