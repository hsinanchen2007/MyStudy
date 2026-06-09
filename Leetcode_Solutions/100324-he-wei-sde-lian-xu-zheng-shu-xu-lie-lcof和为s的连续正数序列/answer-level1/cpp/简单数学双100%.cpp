设连续序列的起始元素是i, 总共有连续的n个整数，即$(i, i+1, ..., i+n-1)$。求和，有
$$S=\frac{n(2i+n-1)}{2}$$
稍作化简，有
$$2i=\frac{2s}{n}+1-n$$
这个式子就是关键了，它是个二元方程。如果固定$i$，那么这是关于$n$的二次方程，求解当然复杂一些；如果固定$n$，这就只是关于$i$的一次方程。因此我选择固定$n$。$n$从2开始递增遍历，显然在最终返回的列表里面，序列们是按照初始元素$i$从大到小排列的，所以最后还需要reverse一下，以满足题目“按首元素从小到大排列”的要求。

OK! $\because i\geq 1, \therefore 2i\geq 2$. 如果右边小于2，证明$n$就不能再大了，这时候就结束迭代。因为$2i$是偶数，所以要求$2s$能被$n$整除，并且右边表达式的值是偶数才行。

算法时间复杂度为$O(m)$（$m$即为target, 因为$n$可以达到$\sqrt{m}$，每一次$n$里面都可能有$n$次迭代以得到这一次的序列），空间复杂度为$O(1)$（不考虑要返回的结果变量所占用的内存）。

```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int a = 2 * target;
        for(int n = 2; ; ++n) {
            int remain = a % n, quotient = a / n + 1 - n;
            if(quotient < 2) break;
            if(remain != 0) continue;
            if(quotient % 2 == 0) {
                int start = quotient / 2;
                vector<int> tmp(n);
                for(int i = 0; i < n; ++i) tmp.at(i) = start + i;
                res.push_back(tmp);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
