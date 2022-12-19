### 解题思路
![1.png](https://pic.leetcode-cn.com/1e2a485e6d84afd9886f760fc6b0d86223cce7eed9635a21560b85370ade9358-1.png)

括号能匹配，一定是一左一右，可以当成游戏来做，从左到右，碰到左括号加血，右括号减血，血量小于零死亡，等于0则配对，更新maxLength，大于0则继续。这样做会出现血量大于0的情况，即“(()”这样的以血量大于0截止的情况，则防止它可以倒着以“右括号加血，左括号减血来得到maxLength”


### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        int maxLength = 0, life = 0, length = 0;
        for(int i = 0; i < s.length(); i++) {
        	if(s.charAt(i) == '(') {
        		life++;
        		length++;
        	}
        	else if(s.charAt(i) == ')') {
        		life--;
        		if(life < 0) {
        			life = 0;
        			length = 0;
        			continue;
        		}
        		else if(life == 0) {
        			length++;
        			maxLength = maxLength > length ? maxLength : length;
        			continue;
        		}
        		else {
        			length++;
        		}
        	}
        }
        life = 0;
        length = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
        	if(s.charAt(i) == ')') {
        		life++;
        		length++;
        	}
        	else if(s.charAt(i) == '(') {
        		life--;
        		if(life < 0) {
        			life = 0;
        			length = 0;
        			continue;
        		}
        		else if(life == 0) {
        			length++;
        			maxLength = maxLength > length ? maxLength : length;
        			continue;
        		}
        		else {
        			length++;
        		}
        	}
        }
        return maxLength;
    }
}
```