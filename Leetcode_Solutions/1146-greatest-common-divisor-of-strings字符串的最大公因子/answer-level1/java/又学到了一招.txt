### 解题思路
辗转相除找最大公约数

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1+str2).equals(str2+str1)) {
			return "";               //如两个字符串存在最大公约数，则调换顺序组合结果应相等
		}
    	return str1.substring(0,gcd(str1.length(),str2.length()));   	
    	
    }
    private int gcd(int a,int b) {        //辗转相除找最大公约数
    	if (a<b) {
			return gcd(b, a);
		}
    	if (b==0) {
			return a;
		}else {
			return gcd(b, a%b);
		}
    }
}
```