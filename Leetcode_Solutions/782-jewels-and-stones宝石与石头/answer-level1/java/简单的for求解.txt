### 解题思路

没什么算法，就是开始时靠if保证j是最大

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
            	if(J.length() < S.length()) return numJewelsInStones(S,J);
		int gens = 0;
		int x = 0;
		char a[] = J.toCharArray();
		char b[] = S.toCharArray();
		for(int i : a) {
			for(int j : b) {
				if(i == j) {
					gens++;
				}
			}
		}
		
		return gens;
    }
}
```