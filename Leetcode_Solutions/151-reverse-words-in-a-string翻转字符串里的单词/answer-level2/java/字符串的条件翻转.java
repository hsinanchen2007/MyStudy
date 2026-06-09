### 解题思路
1.首先定义一个字符串常量池，以备后面倒序使用。
2.判断参数字符串引用为空或者内容为空
    如果满足上述条件之一，直接返回
    否则:将该字符串去掉首尾多余的空格并且以一个以上的空格作为分隔符，将单词分隔开来。将返回的字符串副本赋值给字符串数组
3.通过for循环，将单词从尾部一个一个追加给字符串常量池
4.通过toString（）方法将字符串常量池转化为字符串并作为返回值。
### 代码

```java
public class Solution {
   public static String reverseWords(String s) {
       
		StringBuilder sb = new StringBuilder();
    	if(s == null || "".equals(s.trim())){
    		return "";
    	}else{
			//使用正则表达式
    		String [] strs = s.trim().split("\\s+");
    		int len = strs.length-1;
    		
    		for(int i=len;i>=0;i--){
    			if(i == 0){
    				sb.append(strs[i]);
    			}else{
    				sb.append(strs[i]+" ");
    			}
    		}
    		return sb.toString();
    	}
	}
}
```