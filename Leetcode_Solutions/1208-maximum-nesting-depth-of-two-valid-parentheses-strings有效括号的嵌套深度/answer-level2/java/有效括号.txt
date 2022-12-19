### 解题思路
有效括号的嵌套深度，用栈存放'('，栈的深度即时，'('的嵌套深度；
遇到一个')'，从栈中弹出一个'('后，栈的深度即为')'的嵌套深度

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] answer = new int[seq.length()];
        int depth = 0;
        for(int i = 0; i < seq.length(); i++){
            if(seq.charAt(i) == '('){
                depth++;
                answer[i] = depth % 2;
            }else{
                answer[i] = depth % 2;
                depth--;
            }
        }
        return answer;
    }
}
```