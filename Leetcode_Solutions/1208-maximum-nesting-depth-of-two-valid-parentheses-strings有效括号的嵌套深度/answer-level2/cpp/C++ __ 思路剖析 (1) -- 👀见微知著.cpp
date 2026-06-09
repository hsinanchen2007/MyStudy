## 法一，简单思路
&emsp;看到这个题目，关于**括号**，我最开始想的是dfs+回溯或者啥,~~因为看起来一大堆~~
&emsp;但是联想到之前做过的一道题目[LC 856 括号的分数](https://leetcode-cn.com/problems/score-of-parentheses/)，我决定先用*栈的思想进行遍历处理*
&emsp;所以我现在遇到**括号的题目**一般会先进行以下两种思考:
- 利用**栈的思想进行遍历处理**+模拟进行题目要求的行为
- 碰到上述解决不了的或者涉及组合，种类的题目就考虑**dfs+回溯**
&emsp;那这题我选择的是用栈的思想进行遍历
&emsp;**具体思路：**
- $\mathcal{A}$: 这题要求的是让A,B两个子序列(不相交的意思就是A,B没有母串同一位置的字符)两者最大深度的最小值，显然是两者最相近时成立
- $\mathcal{B}$: 如何让两者最相近，这不就是**按照题目的要求进行模拟嘛**，简单对半分就好了。
- $\mathcal{C}$: 构建一个辅助数组，在上面记录该位置对应的嵌套深度，并且维护一个最大值（便于对半分）。
- $\mathcal{D}$: 然后设置一个$flag$，大于$flag$的为A部分，小于则为B部分就可以解决问题了。


```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int mx(0), cnt(0), len = seq.size(), flag(0); //最大值, 深度计数器,长度, 对半分标志🚩
        vector<int> dep(len, 0); // 模拟数组

        for (int i = 0; i < len; ++ i){
            if (seq[i] == '('){
                ++ cnt;
                dep[i] = cnt;
                mx = std::max(mx, cnt); // 维护最大值
            }else {
                dep[i] = cnt;
                -- cnt;
            }
        }
        flag = mx >> 1; // 对半分
        for (auto& e : dep) e = e > flag ? 1 : 0; // 完成模拟

        return dep;
    }
};
```
## 法二，如何优化？
&emsp; 我讲的啰里啰唆是为了和我一样的小白能做题目更快一点，如何抓住出题人的思路。因为面试可能要求的是快节奏下的思路，**所以把题目的类型归类，在看到关键词时进行定式思考足矣解决大部分问题.**
&emsp; 然后仔细一想，发现还可以优化。 为啥嘞，**因为关键词对半分。**
&emsp; 对半分实际上就是二进制串中的$\{0, 1, 0, 1 \cdots, 0, 1\}$这样的序列。
&emsp; 思考之后你就可以很简单的得出结论：
$$
\left\{\begin{aligned}
&\mathcal{A}: 与位运算挂钩 \\
&\mathcal{B}: 与奇偶性挂钩 \\
&\mathcal{C}: 假如你逻辑运算不错的话还能想到与异或挂钩 \\
\end{aligned}\right.
$$
&emsp; 那么你的思路是否一下开阔起来了呢！是不是感觉到再做这种类型的题目武器库都充实了一些！！
```cpp
#define SORT(A) std::sort(A.begin(), A.end())
#define RSORT(A) std::sort(A.begin(), A.end(), std::greater<>())
#define FR(A, e) for (auto& e : A)
#define SHOW(A) for (auto& e : A) {cout << e << " ";}; cout << endl;
#define ALL(A) A.begin(),A.end()
#define PB push_back
#define sz(x) ((int)x.size())
using LL = long long;
using db  = double;
const LL MOD = 1e9 + 7;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
using std::cin;
using std::vector;
using std::cout;
using std::endl;
template <typename T>
T gcd(T x, T y) {while(y^=x^=y^=x%=y); return x;}

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int idx(0);
        vector<int> dep(sz(seq), 0);

        FR(seq, e) dep[idx ++] = e == '(' ? idx&1 : (idx+1)&1;

        return dep;
    }
};
```
&emsp; 水平有限，仅仅是经验之谈， 若有不足或补充谢谢指出！！
&emsp; 回顾一下，我们能从这题学到什么？
&emsp;
$$
\left\{\begin{aligned}
&括号类题目=\left\{\begin{aligned}
&\mathcal{A}: 利用栈的思想进行遍历处理+模拟进行题目要求的行为 \\
&\mathcal{B}:碰到上述解决不了的或者涉及组合，种类的题目就考虑dfs+回溯 \\
\end{aligned}\right. \\
&对半分=\left\{\begin{aligned}
&\mathcal{A}: 与位运算挂钩 \\
&\mathcal{B}: 与奇偶性挂钩 \\
&\mathcal{C}: 假如你逻辑运算不错的话还能想到与异或挂钩 \\
\end{aligned}\right.
\end{aligned}\right. \\
$$
假如你没做过[LC 856 括号的分数](https://leetcode-cn.com/problems/score-of-parentheses/)可以试一试，用栈和dfs做做，这样再做这类题目必然会更有心得。