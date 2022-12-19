### 解题思路
1.判断其中一个值的取值范围
2.开方时转为int型会省略小数，不省略时就是答案

### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
    	int cc = (int) Math.sqrt(c);
    	for (int a = 0; a <= cc; a++) {
    		int bbb = c-a*a;
    		int bb = (int) Math.sqrt(bbb);
			if (bb*bb == bbb) {
				return true;
			}
		}
    	return false;
    }
}
```