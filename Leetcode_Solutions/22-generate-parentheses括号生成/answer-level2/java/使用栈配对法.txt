[leetcode22](https://leetcode-cn.com/problems/generate-parentheses/)

* 使用栈表示当前没有配对的`（`,不用实际入栈，只要记录个数即可
  * 所以对于下一个位置
    * 如果还有剩余括号对数，添加`（`，同时`（`入栈
    * 如果`（`栈不为空，`（`出栈，同时添加`）`

```java
class Solution {
    List<String> list = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        if(n==0) return list;
        StringBuilder builder = new StringBuilder();
       helper(builder,0,n);
       return list;
    }
    public void helper(StringBuilder builder,int stack,int residual){
        if(stack == 0 && residual == 0){
            list.add(builder.toString());
            return;
        }
        if(stack > 0){
            builder.append(')');
            helper(builder,stack-1,residual);
            builder.deleteCharAt(builder.length()-1);
        }
        if(residual>0){
            builder.append('(');
            helper(builder,stack+1,residual-1);
            builder.deleteCharAt(builder.length()-1);
        }
        return ;
    }
}
```

