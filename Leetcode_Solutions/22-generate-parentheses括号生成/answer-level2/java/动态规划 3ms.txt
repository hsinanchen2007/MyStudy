
每当输出一个左括号，首先将其右括号入栈。然后可以输出1、2、3……stk（栈中元素个数）个右括号。

然后处理下一个左括号。

> 特殊情况，若只剩一个左括号，则它输出完要输出栈中剩余所有的右括号。
>> 由于括号长得一样，我并没有真的建这么多个栈，只是用int变量记录了栈中有多少个括号。

```java
import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */
class Solution {
    /**
     * 生成括号
     * @param stk 栈中括号数量
     * @param n 当前剩余(
     * @return
     */
    private void createKH(StringBuilder sb,List<String> res,int stk,int n){
        if(n==1){
            sb.append('(');
            stk++;
            for(int i=0;i<stk;i++){
                sb.append(')');
            }
            res.add(sb.toString());
            return;
        }
        sb.append('(');
        stk++;
        for(int i=0;i<=stk;i++){
            createKH(new StringBuilder(sb), res, stk-i, n-1);
            sb.append(')');
        }
    }

    public List<String> generateParenthesis(int n) {
        StringBuilder sb=new StringBuilder();
        List<String> res=new ArrayList<>();
        createKH(sb, res, 0, n);
        return res;
    }
}

```
```angelscript
√ Accepted
  √ 8/8 cases passed (3 ms)
  √ Your runtime beats 85.14 % of java submissions
  √ Your memory usage beats 96.94 % of java submissions (36.6 MB)
```

[我的博客：ntutn.top](https://www.ntutn.top/show/81)