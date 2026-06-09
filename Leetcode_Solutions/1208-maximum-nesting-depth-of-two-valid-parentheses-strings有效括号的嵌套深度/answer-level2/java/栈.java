### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int len = seq.length();
        if(seq == null || len == 0){
            return new int[0];
        }
        Stack<Character> stack = new Stack<>();
        int res[] = new int[len];
        for(int i = 0; i < len; i++){
            char c = seq.charAt(i);
            if(c == '('){
                res[i] = stack.size() % 2;
                stack.push(c);
            }else{
                stack.pop();
                res[i] = stack.size() % 2;
            }
        }
        return res;
    }
}
```