### 解题思路
动态规划，画二维数组表格，自顶向下，初始化第一行和第一列。之后的每个格子等于min(word1[i]==word2[j]?左上方格子：左上方格子++，上方格子++，左方格子++)，输出数组的最右下方一个格子的值

执行用时 :
6 ms
, 在所有 Java 提交中击败了
92.51%
的用户

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
         	if(word1.equals("")) {
    		return word2.length();
    	}
    	
    	if(word2.equals("")) {
    		return word1.length();
    	}
        int distance = 0;
    	int len1 = word1.length();
    	int len2 = word2.length();
    	int[][] step = new int[len1][len2];
    	
    	if(word1.charAt(0) == word2.charAt(0)) {
    		step[0][0] = 0;
    	}else {
    		step[0][0] = 1;
    	}
    	int flag =0;
    	for(int i = 1 ; i < len2; i++) {
    		if(flag == 0 && word1.charAt(0)==word2.charAt(i)) {
    			step[0][i] = step[0][i-1];
    			flag =1;
    		}else {
    		step[0][i] = step[0][i-1] +1;
    		}
    	}
    	
    	int flag1 =0;
    	for(int i = 1 ; i < len1; i++) {
    		if(flag1 == 0 && word2.charAt(0)==word1.charAt(i)) {
    			step[i][0] = step[i-1][0];
    			flag1 =1;
    		}else {
    		step[i][0] = step[i-1][0] +1;
    		}
    	}
    	
    	for(int i =1; i < len1;i++) {
    		for(int j = 1; j <len2; j++) {
    			int curflag =0;
    			int cur1 =0;
    			int cur2 =0;
    			int cur3 =0;
    			if(word1.charAt(i)==word2.charAt(j)) {
    				curflag =1;
    			}
    			cur1 = step[i-1][j]+1;
    			cur2 = step[i][j-1]+1;
    			if(curflag ==1) {
    			cur3 = step[i-1][j-1];
    			}else {
    			cur3 = step[i-1][j-1]+1;
    			}
    			int temp = Math.min(cur1, cur2);
    			step[i][j] = Math.min(temp, cur3);
    			
    		}
    	}
    	distance = step[len1-1][len2-1];
    	return distance;
    }
}
```