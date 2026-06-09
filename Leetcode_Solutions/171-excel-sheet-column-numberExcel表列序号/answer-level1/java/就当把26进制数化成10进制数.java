### 解题思路
随便举个例子
就相当于把  32341化成10进制那么简单
### 代码

```java
class Solution {
    public int titleToNumber(String s) {
         int ans=0;
	   int len=s.length();
	     for(int i=len-1;i>=0;i--) {
	    	 int num=s.charAt(i)-'A'+1;
	    	 ans+=num*Math.pow(26,len-i-1);
	     }
	        return ans;
    }
}
```