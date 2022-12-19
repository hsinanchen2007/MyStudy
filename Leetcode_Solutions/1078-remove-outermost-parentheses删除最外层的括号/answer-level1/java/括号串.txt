### 解题思路
看了大神的结题，找样子自己写了遍，关键是思路，栈的利用
### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder stringBuilder = new StringBuilder();
        int depth = 0;
        for( char c :S.toCharArray() ){
            if(c==')') depth --;
            if(depth >=1) stringBuilder.append(c);
            if(c=='(') depth ++;            
        }
        return stringBuilder.toString();
    }
}
```