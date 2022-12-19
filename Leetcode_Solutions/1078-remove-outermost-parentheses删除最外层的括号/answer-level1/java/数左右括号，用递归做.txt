### 解题思路
S里面只有左右括号，而且是有效的，第一个肯定是"(",然后开始遍历字符串，数出左右括号的数量，当左=右的时候，取出中间的子字符串，然后将后面剩下的字符串进行递归

比较蠢，效果好像也不是很好，但是解决问题。学习一下其他dalao的方法...

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        //思路是数左右括号,记录左右括号的数量，对应上记录下角标，取出角标之间的东西
        int right_n = 1;
        int left_n = 0;

        for(int i=1; i<S.length(); i++){
            if(S.charAt(i) == '('){
                right_n = right_n + 1;
            }else{
                left_n = left_n + 1;
            }
            //两边相等了，取出中间的东西
            if(right_n == left_n){
                return S.substring(1,left_n+right_n-1) + removeOuterParentheses(S.substring(left_n+right_n, S.length()));
            }
        }
        return "";
    }
}
```