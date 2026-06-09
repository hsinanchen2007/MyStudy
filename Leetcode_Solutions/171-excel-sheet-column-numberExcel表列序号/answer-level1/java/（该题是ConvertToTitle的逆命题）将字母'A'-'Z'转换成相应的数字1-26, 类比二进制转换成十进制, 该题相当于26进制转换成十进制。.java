![2020010501.PNG](https://pic.leetcode-cn.com/b86552822cb59d9c4865a6988e8b42d28089245142a9b8e402b9583df8783d13-2020010501.PNG)

### 解题思路
### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        int out = 0;
    	for(int i =0;i<s.length();i++) {
    		int k = s.charAt(i)-'A'+1;
    		int sum = 1;
    		for(int m=0;m<s.length()-1-i;m++) {
    			sum = sum * 26;
    		}
    		out = out + k*sum;
    	}
    	
    	return out;
    }
}
```