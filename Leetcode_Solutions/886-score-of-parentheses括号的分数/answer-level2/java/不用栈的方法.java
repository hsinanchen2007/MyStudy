### 解题思路
遇到（ 就++
遇到 ）就--
当遇到（） 就结算一次。

### 代码

```java
class Solution {
    public int scoreOfParentheses(String S) {
       int ans=0;
       int bal=0;
       for(int i=0;i<S.length();i++){
           if(S.charAt(i)=='('){
               bal++;
           }else{
               bal--;
               if(S.charAt(i-1)=='('){
                   ans+=1<<bal;
               }
           }
       }
       return ans;
        
    }
}
```