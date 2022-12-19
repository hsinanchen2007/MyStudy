### 解题思路
简单标记,之后奇数层分为A,偶数层分为B即可

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
    	int[] res ;
    	int level = -1;
    	res = new int[seq.length()];
    	for(int i=0 ; i<seq.length() ; i++) {
    		if(seq.charAt(i)=='(') {
    			level++;
    			res[i] = level%2;
    			
    		}else {
    			res[i] = level%2;
    			level--;
    			
    			
    		}
    	}
    	return res;
    }
}
```