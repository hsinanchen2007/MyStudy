### 解题思路
想象俩一起移动的指针就行

### 代码

```java
class Solution {
    public int fib(int N) {
        int a = 0;
        int b = 1;
    	for(int i = 0;i < N;i++) {
    		
    		a = a+b;
    		b = a-b;
    	}
    	
    	return a;
    }
}
```