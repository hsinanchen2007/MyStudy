### 代码

```java
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        //末尾加空格,减少下面的判断逻辑
        s = s + " ";
        char[] charArr = s.toCharArray();
        Stack<String> stack = new Stack<>();
        int startIndex = 0;
        for(int i = 1, j = 0; i < charArr.length; i++,j++){
            if(charArr[i] == ' ' && charArr[j] != ' '){
                stack.push(new String(charArr, startIndex, i-startIndex));
            }else if(charArr[i] == ' ' && charArr[j] == ' '){
                continue;
            }else if(charArr[i] != ' ' && charArr[j] == ' '){
                startIndex = i;
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.empty()){
            sb.append(stack.pop());
            sb.append(" ");
        }
        return sb.toString().trim();
    }
}
```