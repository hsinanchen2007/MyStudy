### 解题思路
有一种数列叫卡特兰数，卡塔兰数有一个应用是：
n个0和n个1，组成一个串，在任何时候，1的个数都要大于等于0的个数，问有多少个这样的串？
想详细了解卡特兰数的可以参考[我的博客](https://blog.csdn.net/cz9797/article/details/105366774)，或者自己去搜相关的资料，**超有意思的一个数列！！**

**咦？把1看成左括号，0看成右括号，不就是括号匹配问题吗？**

所以我的思路是简单的暴力递归，回溯减枝，**而减枝的条件就是左括号的个数在任何时候都要大于等于右括号的个数**

### 代码

```cpp
class Solution {
public:
    vector<string> rel;
    vector<string> generateParenthesis(int n) {
        //把左括号看成1，右括号看成0，则在任何时候1的个数都大于等于0的个数
        string s = "";
        backtrack(0, 0, n, s);
        return rel;
    }
    void backtrack(int l, int r, int n, string s){
        //若左括号的个数小于右括号的个数，或者左括号的个数大于n，或者右括号的个数大于n,不合法，减枝
        if(l < r || l > n || r > n)    return ;
        //合理结果,push
        if(l == r && l == n) {
            rel.push_back(s);
            return ;
        }
        //递归回溯
        s += '(';
        backtrack(l+1, r, n, s);
        s.pop_back();

        s += ')';
        backtrack(l, r+1, n, s);
        s.pop_back();
    }
};
```