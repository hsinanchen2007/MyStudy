### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if(seq == null || seq.equals(""))return new int[0];
        Stack<Character> si = new Stack<>();
        int[] res = new int[seq.length()];

        for(int i=0;i<seq.length();i++){
            char c = seq.charAt(i);
            if(c == '('){
                res[i] = si.size()%2;
                si.push(c);
            }else{
                si.pop();    
                res[i] = si.size()%2;
            }
        }
         /*if (seq == null || seq.equals("")) return new int[0];
        Stack<Character> stack = new Stack<>();
        int[] res = new int[seq.length()];
        //遍历
        for (int i = 0; i < seq.length(); i++) {
            char c = seq.charAt(i);
            if (c == '(') {//入栈,记录括号对所在深度,奇数用0标记，偶数用1标记。
                res[i] = stack.size() % 2;
                stack.push(c);
            } else {//出栈,记录括号对所在深度,奇数用0标记，偶数用1标记。
                stack.pop();
                res[i] = stack.size() % 2;
            }
        }
        
        int[] ans = new int [seq.length()];
        int idx = 0;
        for(char c: seq.toCharArray()) {
            ans[idx++] = c == '(' ? idx & 1 : ((idx + 1) & 1);
        }
        return ans;
        
        
        if (seq == null || seq.equals("")) return new int[0];
        int depth=0;
        int[] res = new int[seq.length()];
        //遍历
        for (int i = 0; i < seq.length(); i++) {
            char c = seq.charAt(i);
            if (c == '(') {//入栈,栈内深度增加
                res[i] = ++depth % 2;
            } else {//出栈，栈内深度减少
                res[i] = depth-- % 2;
            }
        }*/
        return res;
    }
}
```