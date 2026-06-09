### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        StringBuilder sb = new StringBuilder(String.valueOf(x));
		StringBuilder reverseStr = sb.reverse();
		
		boolean flag = true;
		int len = sb.length();
//		System.out.println(len);
		for (int i = 0; i <= (len - 1)/2; i++) {
			if (sb.charAt(i) != reverseStr.charAt(len-1-i)) {
				flag = false;
				break;
			}
		}
		return flag;
    }
}
```
![image.png](https://pic.leetcode-cn.com/279f8f211d95b9bf4ff91c16ff88c957c473e7d9b1fe29cb4de3baafc7964b7f-image.png)
