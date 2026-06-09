### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
       StringBuffer sb2 = new StringBuffer(s);
       int length = s.length();
       int number = length/(2*k);
       int result = length%(2*k);
       String str = "";
       int n = 1;
       for(int i=1;i<=number;i++) {
    	   String s1 = s.substring((n-1)*k, n*k);
    	   StringBuffer sb = new StringBuffer(s1);
    	   StringBuffer reverse = sb.reverse();
    	   sb2.replace((n-1)*k, n*k, new String(reverse));
    	   n+=2;
       }
       if(result<k) {
    	   String substring = sb2.substring(number*2*k, length);
    	   StringBuffer sb = new StringBuffer(substring);
    	   StringBuffer reverse = sb.reverse();
    	   sb2.replace(number*2*k, length, new String(reverse));
       }
       if(result>=k&&result<2*k) {
    	   String substring = sb2.substring(number*2*k, number*2*k+k);
    	   StringBuffer sb = new StringBuffer(substring);
    	   StringBuffer reverse = sb.reverse();
    	   sb2.replace(number*2*k, number*2*k+k, new String(reverse));
       }
       return new String(sb2);
    }
}
```