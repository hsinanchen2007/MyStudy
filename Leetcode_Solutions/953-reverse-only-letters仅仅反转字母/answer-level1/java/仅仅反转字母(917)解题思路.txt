### 解题思路
先反向遍历一遍字符串，只要遇到字母就直接存入到一个新的字符串 strRes中，这样就实现了对所有字母的翻转。
再正向遍历一遍原字符串S，把非字母字符加入到strRes 中对应的位置。

### 代码

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        StringBuilder strRes = new StringBuilder();
        int index = 0;
        for (int i = S.length() - 1; i >= 0; i--) 
        {
            if (Character.isLetter(S.charAt(i))) 
            {
                strRes.insert(index,S.charAt(i));
                index++;
            }
        }
        for (int i = 0; i < S.length(); i++) 
        {
        	if(!Character.isLetter(S.charAt(i)))
        	{
        		strRes.insert(i,S.charAt(i));
        	}
        }
        return strRes.toString();
    }
}
```