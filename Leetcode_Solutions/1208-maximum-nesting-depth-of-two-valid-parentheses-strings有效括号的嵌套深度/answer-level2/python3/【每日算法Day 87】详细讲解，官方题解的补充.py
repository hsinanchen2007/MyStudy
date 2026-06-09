

## 题目描述
一句话概括就是，给你一个合法的括号序列，你需要将其拆分成两个合法的子序列（不连续），使得两个子序列的括号嵌套深度较大者尽量的小。

## 题解
既然想要两个子序列的嵌套深度中较大者尽量小，那么我们最好能够让两个子序列的嵌套深度相同。

再考虑任意一个原序列中嵌套深度为 $d$ 的合法子序列，我们要想办法把它拆成两半。那么最优的方法肯定是一半嵌套深度为 $\lfloor d/2 \rfloor$ ，一半是 $d - \lfloor d/2 \rfloor$ 。这样两个子序列中嵌套深度较大值就是 $\lceil d/2 \rceil$，而其它任何分法都会导致较大值大于它。

那么怎么样才能对半分呢？这个其实随意了，但是最为方便的方法就是，嵌套深度为奇数的作为一个子序列，偶数的作为另一个子序列，这样就对半分了，代码还好写。

具体实现上，我们用一个变量 $cnt$ 来表示当前括号的嵌套深度，那么遇到左括号就深度加一，遇到右括号嵌套深度就是当前的 $cnt$ ，但是遍历完这个括号之后，深度要减一，然后嵌套深度为奇数的括号位置处标记为 1 就行了。

伪代码也就是：
```text
if c = '('
    cnt := cnt + 1
    mask := cnt&1
else
    mask := cnt&1
    cnt := cnt - 1
```

### 简化
其实我们可以注意到，不管是加一还是减一，奇偶性的变化都是一致的，也就是减一之后的奇偶性和加一之后是相同的。

所以我们把减一也变成加一，那么不管遇到什么括号，都是 $cnt$ 加一了，那不就变成了下标 $i$ 了吗？

我们把上面的伪代码按照这种思路改变一下：
```text
if c = '('
    cnt := cnt + 1
    mask := cnt&1
else
    mask := cnt&1
    cnt := cnt + 1
```

然后用下标 $i$ 替换掉 $cnt$ :
```text
if c = '('
    mask := (i+1)&1
else
    mask := i&1
```

继续改写一下，让形式统一一点：
```text
if c = '('
    mask := ~(i&1)
else
    mask := i&1
```

那么最后就可以把这两种情况合并了，也就是标记值直接就等于 `(i&1)^(c='(')` 。

当然我是从代码的角度，从奇偶性推过来的，官方题解是直接严格证明了正确性：

[官方题解：LeetCode 1111. 有效括号的嵌套深度](https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/you-xiao-gua-hao-de-qian-tao-shen-du-by-leetcode-s/ "官方题解：LeetCode 1111. 有效括号的嵌套深度")

![1.jpg](https://pic.leetcode-cn.com/07cfe9b8d64e1376501467025d95eea2422f9ae5244c2fa27d7b3c164a3cf5ae-1.jpg)


## 代码
### c++
```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt = 0;
        vector<int> res;
        for (auto c : seq) {
            if (c == '(') {
                res.push_back((++cnt)&1);
            } else {
                res.push_back((cnt--)&1);
            }
        }
        return res;
    }
};
```

### python
```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        cnt = 0
        res = []
        for c in seq:
            if c == '(':
                cnt += 1
                res.append(cnt&1)
            else:
                res.append(cnt&1)
                cnt -= 1
        return res
```

### 简化（c++）
```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        for (int i = 0, sz = seq.size(); i < sz; ++i) {
            res.push_back((i&1)^(seq[i]=='('));
        }
        return res;
    }
};
```

### 简化（python）
```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res = []
        for i, c in enumerate(seq):
            res.append((i&1)^(c=='('))
        return res
```