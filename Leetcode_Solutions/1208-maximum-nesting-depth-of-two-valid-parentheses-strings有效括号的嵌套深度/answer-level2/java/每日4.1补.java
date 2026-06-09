### 解题思路
去除栈减小时间空间复杂度

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
         int[] res = new int[seq.length()];
         Stack<Character> stack = new Stack<>();
         for(int i=0;i<seq.length();i++){
             char c=seq.charAt(i);
             if(c=='('){
                 res[i]=stack.size()%2;
                 stack.push(c);
             }else{
                 stack.pop();
                 res[i]=stack.size()%2;
             }
         }
         return res;
    }
}
```