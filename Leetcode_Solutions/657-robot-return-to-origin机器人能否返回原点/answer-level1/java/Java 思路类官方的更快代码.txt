### 解题思路

四个方向其实就是两个方向
用两个变量就 can work . ++-- 之后看是否都是 0 就可以了。

注：switch 语句 比 if 条件判断 要快一些

### 代码

```java
class Solution {
    public boolean judgeCircle(String moves) {
        int a = 0,b=0;
    	char ch[] = moves.toCharArray();
    	for(char c:ch) {
    		switch (c) {
			case 'R':
				a++;
				break;
			case 'L':
				a--;
				break;
			case 'U':
				b++;
				break;
			case 'D':
				b--;
				break;
			default:
				break;
			}
    	}
    	return (a==0 && b==0);
    }
}
```