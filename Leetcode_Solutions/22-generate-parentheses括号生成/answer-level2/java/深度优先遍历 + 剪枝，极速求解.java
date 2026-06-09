### 有效括号

题目描述：给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

对于本题而言有效括号是什么，有效括号相信我们在前面的题目里面都尝试过用 stack 来检验过。

那个题目中最终通过 stack 匹配 括号 最终清空栈来判断输入的括号合法性。

在本题中 我们也可以定义 左括号 "(" 为 -1，右括号 ")" 为1，正常的括号排序在每一步进行添加的时候当前总和 sum 总是会<=0, 当 sum >0 那么此时的括号必定不合法。我们直接进行剪枝 return 即可。

我们定义 left = 0; right = 0; 那么

```java
 sum = -1*left + right<=0
```

推导出 right <= left 为合法的分枝，然后我们进行 dfs 遍历，过滤掉非法的分枝即可。

下面贡献一下代码

```java
class Solution {
  int pair = 0;
    public List<String> generateParenthesis(int n) {
        ArrayList<String> list = new ArrayList<>();
        pair = n;
      	// 默认肯定从左括号开始
        dfsGenerateParenthesis("(",1,0,list);
        return list;
    }

    public void dfsGenerateParenthesis(String res,int left,int right,ArrayList list) {
        if(left==pair&&right==pair) {
            list.add(res);
            return;
        }

        if (right>left) {
            // 剪枝
            return;
        }

        if(left<pair) {
            dfsGenerateParenthesis(res+"(",left+1,right,list);
        }
        if(right<pair) {
            dfsGenerateParenthesis(res+")",left,right+1,list);
        }
    }
}
```

