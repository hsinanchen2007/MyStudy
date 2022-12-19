### 解题思路
1、遍历所有的字符串，统计大写字符的个数
2、若个数为零，肯定正确
3、若个数等于字符串的长度，肯定正确
4、若个数为1，则当且仅当第一个字符为大写时正确
5、其他均为不正确的情形

### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
         int count=0;
	     for(int i=0;i<word.length();i++)
	     {
	    	 if(word.charAt(i)>=65&&word.charAt(i)<=90)
	    		 count++;
	     }
	     if(count==0||count==word.length()||count==1&&word.charAt(0)>=65&&word.charAt(0)<=90)
	    	 return true;
	     else
	    	 return false;
    }
}
```