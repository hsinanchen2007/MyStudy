![2020011101.PNG](https://pic.leetcode-cn.com/1ac1c4f06b2c692697faa2e03919300ae6b44c6da712deaaca81e2a0ca0d7bdd-2020011101.PNG)

### 解题思路
声明整型out记录平衡字符串个数,
在遍历字符串c过程中:设置计数器count,遇到'L'时count加1,遇到'R'时count减1;
当count==0时,out加1.
### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int out = 0;
    	int count = 0;
    	for(char ch:s.toCharArray()) {
    		if(ch == 'L') {
    			count ++;
    		}else {
    			count--;
    		}
    		if(count==0) {
    			out++;
    		}
    	}
        return out;
    }
}
```