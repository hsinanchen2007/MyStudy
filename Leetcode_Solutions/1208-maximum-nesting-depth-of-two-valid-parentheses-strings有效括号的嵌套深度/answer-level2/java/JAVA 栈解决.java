### 解题思路
这道题用栈来解决问题，我运用的方法有，seq.isEmpty(),stack.push(),seq.charAt(),stack.size(),size.pop()
一.判断seq字符串是否为空或者是否是空字符串
二.创建栈stack，如果seq是'('时候入栈，否则得出现在的深度depth=stack.size(),得出左边的下标left=stack.pop(),如果深度是偶数时候，它的左边和他自己就是1.

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if(seq==null||seq.isEmpty())
            return new int[0];
        int[] ans = new int[seq.length()];
        Stack<Integer> stack = new Stack<Integer>();
        for(int i=0;i<seq.length();i++){
            if(seq.charAt(i)=='('){
                stack.push(i);
            }else{
                int depth = stack.size();
                int left = stack.pop();
                if(depth%2==0){
                    ans[left] = 1;
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
}
```