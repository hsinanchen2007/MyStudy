### 解题思路
可以参考注释理解

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s.length() == 0){
           return 0;              //空字符串
        }
        String[] str = s.split(" ");
        if(str.length == 0){
           return 0;              //只有空格的字符串
        }
        return str[str.length - 1].length() ;

        
        /*String cut = " ";	// 分割串，此处为一个空格
		String[] newStr = oldstr.split(cut);	// 分割成数组
		for (String string : newStr) {
			System.out.println(string);	// 输出
		}*/
    }
}
```