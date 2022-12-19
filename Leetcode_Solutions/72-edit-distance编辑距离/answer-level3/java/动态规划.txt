### 解题思路
考虑`dp[i][j]`表示`word1`从位置`i`开始到末尾的子字符串和`word2`从位置`j`开始到末尾的子字符串之间的编辑距离，并且考虑固定`word2`的子串不变，仅对`word1`的字串进行操作，分别考虑最后进行的是增加、删除、修改三种操作：
增加：`dp[i][j] = dp[i + 1][j] + 1`
修改：需要对`word1`的第`i`个字符和`word2`的第`j`个字符进行比较，如果二者相同，则不需要额外的修改操作，`dp[i][j] = dp[i + 1][j + 1]`;反之，则需要对`word1`的第`i`个字符进行修改操作，`dp[i][j] = dp[i + 1][j + 1] + 1`
删除：`dp[i][j] = dp[i - 1][j] + 1`
上面的方法有一个问题，就是在确定`dp[i][j]`时需要使用`dp[i - 1][j]`的值，而这个值还没有被确定，这个问题是“删除”操作所带来的。考虑字符串1在删除一个字符后与字符串2相同，那么在字符串2中增加一个被删除的字符也可以使二者相同，对字符串1的删除操作可以等效为对字符串2的增加操作，所以删除操作下的编辑距离也就等于`dp[i][j] = dp[i][j + 1] + 1`，而`dp[i][j + 1]`在之前的循环中已被确定，可以拿来使用
在三者之间取最小值即可得到`dp[i][j]`,返回`dp[0][0]`即为最终结果。


### 代码
```java
class Solution {
	
    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        for(int i = word1.length(); i >= 0; i--) {
        	for(int j = word2.length(); j >= 0; j--) {
        		if(i == word1.length() && j == word2.length()) {
        			dp[i][j] = 0;
        		}
        		else if(i == word1.length() && j < word2.length()) {
        			dp[i][j] = dp[i][j + 1] + 1;
        		}
        		else if(i < word1.length() && j == word2.length()) {
        			dp[i][j] = dp[i + 1][j] + 1;
        		}
        		else {	// i < word1.length() && j < word2.length()
        			if(word1.charAt(i) == word2.charAt(j)) {
        				dp[i][j] = dp[i + 1][j + 1];
        			}
        			else {
        				dp[i][j] = dp[i + 1][j + 1] + 1;
        			}
        			dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + 1);
        			dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + 1);
        		}
        	}
        }
        return dp[0][0];
    }
    
}

```