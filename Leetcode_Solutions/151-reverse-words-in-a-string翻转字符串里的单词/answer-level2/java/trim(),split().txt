### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public String reverseWords(String s) { 
		  String trim = s.trim(); //去前后空格
		  String[] split = trim.split("\\s+"); //按一个或多个空格切割
		  StringBuilder builder = new StringBuilder(split[split.length-1]); 
		  for(int i=split.length-2;i>=0;i--) {   ////倒序打印并追加
			  builder.append(" "+split[i]); 
		  }
		  return builder.toString(); 
	}
}
```