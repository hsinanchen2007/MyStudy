### 解题思路
此处撰写解题思路
设置一个标志量来决定是否将Parentheses加入字符串
### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder A = new StringBuilder();
        int flag=0;
        for(int i=0;i<S.length();i++){
            if(S.charAt(i)=='('){
                if(flag>0)
                    A.append('('); 
                flag++;
            }
            else{
                flag--;
                if(flag>0)
                    A.append(')');
            }
        }
        return A.toString();
    }
}
```