### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if(ops.length==0) {
			return m*n;
		}
        int x=ops[0][0];
        int y=ops[0][1];
		for(int i=1;i<ops.length;i++) {
        	if(ops[i][0]<x) {
        		x = ops[i][0];
        	}
        	if(ops[i][1]<y) {
        		y = ops[i][1];
        	}
        }
		return x*y;
    }
}
```