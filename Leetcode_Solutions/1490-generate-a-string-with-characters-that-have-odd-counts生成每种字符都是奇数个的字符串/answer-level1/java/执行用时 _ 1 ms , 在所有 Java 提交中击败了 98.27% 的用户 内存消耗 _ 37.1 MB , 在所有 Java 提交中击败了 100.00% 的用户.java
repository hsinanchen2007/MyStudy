### 解题思路
此处撰写解题思路
狗血的题目，无非就是奇偶性的判断
然后循环添加
### 代码

```java
class Solution {
    public String generateTheString(int n) {
        StringBuffer sbf = new StringBuffer();
		char c = 'a';
		if(n%2==0) {
			sbf.append((char)(c+1));
			n--;
		}
		for(int i=0;i<n;i++) {
			sbf.append(c);
		}
		return sbf.toString();
    }
}
```