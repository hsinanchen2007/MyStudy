### $\mathcal{A \quad Solution\;one}$ 
&emsp; **有关匹配问题 与 括号问题 可以用回溯+dfs解决**(栈和dfs同源~~在我看来差不多~~)
&emsp; 在我看到这种括号问题的时候，我就觉得是$dfs$，用dfs解决这种问题的核心就是，**怎么通过搜索一步步把问题给分解化**，显然这个题目是对于不同的情况进行讨论，在这种讨论过程中来思考如何将问题给降级！
**解题思路**
- ①: 思考如何构建$dfs$函数,`XX dfs(xxxxx)`,我觉得这一步是很多题解忽略的方面，直接给出了$dfs$函数。在这里我们需要的是一个值,而且**这个值是可以由多个值组合**而成的,因此我首先认为应该是`int dfs(xxxxx)`,其次在我们在这个函数中我们需要知道的信息为:①现在处理的字符位置，②在第几个括号下， ③目前的值是多少。 最后推得$dfs$函数为$\rightarrow$`int dfs(int cur, int l, int now)`。
- ②:思考在不同情况下如何进一步搜索：(设字符串为$S$)
 $$ \left\{\small
\begin{aligned}
S[cur] = '(' &\qquad 我们进往更深层次进行搜索\\
S[cur] = ')' &\qquad\left\{
\begin{aligned}
&{\mathcal{A}\quad\small 假如到了末端,直接返回值val }\\
&{\mathcal{B}\quad\small 假如S[cur + 1]==')',我们把责任丢给下一个')',让他去处理其他情况} \\
&{\mathcal{C}\quad\small 假如S[cur + 1]=='(',我们计算已经闭合的括号，并继续处理下一个阶段}
\end{aligned}
\right.\\
\end{aligned}
\right.

$$
&emsp;最终代码如下:
```
class Solution {
    string ss;
public:
    int dfs(int cur, int l, int now){
        if (ss[cur] == '(') return dfs(cur + 1, l + 1, now);
        else {
            int val = now == 0 ? 1 : 2 * now;
            if (cur == ss.size() - 1) return val; // 结束啦！
            if (ss[cur + 1] == '(') return pow(2, l - 1) * val + dfs(cur + 1, l - 1, 0); // 分解问题
            if (ss[cur + 1] == ')') return dfs(cur + 1, l - 1, val);// 把责任丢给下一个)
        }
        return 0;
    }
    
    int scoreOfParentheses(string S) {
        ss.swap(S);
        return dfs(0, 0, 0);
    }
};
```
### $\mathcal{B \quad Solution\;two}$ 
&emsp;思考下之后发现核心计算点就在于**封闭的括号**，每当一个括号封闭时，我们都可以**通过他所在的层次直接计算出来**！
&emsp;衍生一下得到了顺序遍历直接搞定的方法其:计算核心为计算`()`：
```
class Solution {
public:
    int scoreOfParentheses(string S) {
        int deep(0), ans(0);
        for (int i = 0; i < S.size(); ++ i){
            deep = S[i] == '(' ? deep + 1 : deep - 1;
            if (S[i] == ')' && S[i - 1] == '(') ans += 1 << deep;
        }

        return ans;
    }
};
```