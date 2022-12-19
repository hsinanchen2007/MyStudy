### 解题思路
1、去除整个字符串两端多余的空格
2、从最右边开始向左查找第一个空格
3、计算出空格右边的字符数即可

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
         if(s=="") return 0;
		 s=s.trim();
	     int count=0;
	     int c=s.length()-1;
	     while(c>=0)
	     {
	    	 if(s.charAt(c)!=' ')
	    	 {
	    		 c--;
	    		 count++;
	    	 }
	    	 else
	    		 break;
	    	 
	      }
	     return count;
	
    }
}
```