### 解题思路
看题解是说将左括号平均分给A和B，仅左括号而言，奇数位的左括号为0，偶数位为1，右括号则相反，即可
### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
    	char[] cs = seq.toCharArray();
    	int[] results = new int[seq.length()];
    	int count = 0;
    	for (int i = 0; i < cs.length; i++) {
			if (cs[i] == '(') {
				results[count] = count % 2;
				
			} else {
				results[count] = (count+1) % 2;
			}
			count++;
		}
    	return results;
    }
}
```