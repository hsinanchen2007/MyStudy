**题目：**  
    URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
**分析题意：**
    1：将字符串中所有的‘ ’替换为%20
**解题思路：**
    1：获取字符串数组
    2：创建可变字符串拼接
    3: 遍历判断是否存在‘ ’
```
class Solution {
    public String replaceSpaces(String S, int length) {
        //获取字符串数组
        char[] charArray = S.toCharArray();
        //创建可变字符串对象，接受结果
		StringBuilder builder=new StringBuilder();
		for (int i = 0; i <= length-1; i++) {
			if(charArray[i]==' '){
				builder.append("%20");
			}else{
				builder.append(charArray[i]);
			}
		}
         return builder.toString();
    }
   
}

```
**还有一种java内部提供的方式:**
    解释：replaceAll方法，整体替换字符串中所有的指定字符串。
    S.substring(0,length).replaceAll(' ', "%20");