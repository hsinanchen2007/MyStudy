### 解题思路
直接模拟十进制加法的计算过程
sum(i) = (a(i) + b(i) + carry(i - 1) % 10
carry(i) = (a(i) + b(i) + carry(i - 1) / 10


### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
    	int carry = 0;
    	int partSum = 0;
    	int i = num1.length() - 1;
    	int j = num2.length() - 1;
    	while(i >= 0 || j >= 0 || carry != 0) {
    		partSum = carry;
    		if(i >= 0) {
    			partSum += num1.charAt(i) - '0';
    			i--;
    		}
    		if(j >= 0) {
    			partSum += num2.charAt(j) - '0';
    			j--;
    		}
    		carry = partSum / 10;
    		partSum = partSum % 10;
    		char c = (char)(partSum + '0');
    		sb.append(c);
    	}
    	sb.reverse();
    	return sb.toString();
    }
}
```