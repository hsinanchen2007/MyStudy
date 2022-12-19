### 解题思路
用一个字母栈保存字母，第二次遍历时遇到字母弹栈就可以了。
### 代码

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        Stack<Character> letters=new Stack<>();
        for(char c:S.toCharArray())
        {
            if(Character.isLetter(c))
                letters.push(c);
        }
        StringBuilder ans=new StringBuilder();
        for(char c:S.toCharArray())
        {
            if(Character.isLetter(c))
                ans.append(letters.pop());
            else
                ans.append(c);
        }
        return ans.toString();
    }
}
```