### 解题思路
解题思路：
     *  便利字符串，遇到左括号'('入栈，遇到右括号')'出栈，当栈为空，说明一个原语结束
     *  使用两个int变量，分别记录原语开始位置和结束位置，当一个原语结束后，通过记录的开始位置和结束位置进行字符串截取
     *  将全部截取的字符串拼接即可得到最终结果

### 代码

```java
class Solution {
    public String removeOuterParentheses(String S) {
        Stack<Character> stack = new Stack<>();
        String result = "";
        int start = 0;
        int end = 0;
        for(char c : S.toCharArray()){
            if(c == '('){
                stack.push(c);
            }else{
                stack.pop();
                if(stack.empty()){
                    //说明原语化end
                    //截取字符串
                    result += subStr(S,start,end);
                    start = end + 1;
                }
            }
            end++;
        }
        
        return result;
    }

    private String subStr(String str,int start,int end){
        return str.substring(start + 1,end);
    }
}
```