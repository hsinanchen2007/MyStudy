### 解题思路
异或运算:相同为0不同为1,然后转换为二进制字符串,这里偷懒了.....

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
    	String s = Integer.toBinaryString(x^y);
		
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if('1' == s.charAt(i)){
				count +=1;
			}
		}
		return count;
    }
}
```