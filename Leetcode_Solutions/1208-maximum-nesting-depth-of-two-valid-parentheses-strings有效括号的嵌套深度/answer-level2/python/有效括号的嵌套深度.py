![...号的嵌套深度 -Lizzi(1).mp4](7b0eee29-172e-4dbf-b30f-6ae008be489c)


#### 方法一：用栈进行括号匹配

**思路及算法**

要求划分出使得最大嵌套深度最小的分组，我们首先得知道如何计算嵌套深度。我们可以通过栈实现括号匹配来计算：

维护一个栈 `s`，从左至右遍历括号字符串中的每一个字符：

- 如果当前字符是 `(`，就把 `(` 压入栈中，此时这个 `(` 的嵌套深度为栈的高度；

- 如果当前字符是 `)`，此时这个 `)` 的嵌套深度为栈的高度，随后再从栈中弹出一个 `(`。

下面给出了括号序列 `(()(())())` 在每一个字符处的嵌套深度：

```
括号序列   ( ( ) ( ( ) ) ( ) )
下标编号   0 1 2 3 4 5 6 7 8 9
嵌套深度   1 2 2 2 3 3 2 2 2 1 
```

知道如何计算嵌套深度，问题就很简单了：只要在遍历过程中，我们保证栈内一半的括号属于序列 `A`，一半的括号属于序列 `B`，那么就能保证拆分后最大的嵌套深度最小，是当前最大嵌套深度的一半。要实现这样的对半分配，我们只需要把奇数层的 `(` 分配给 `A`，偶数层的 `(` 分配给 `B` 即可。对于上面的例子，我们将嵌套深度为 `1` 和 `3` 的所有括号 `(())` 分配给 `A`，嵌套深度为 `2` 的所有括号 `()()()` 分配给 `B`。

此外，由于在这个问题中，栈中只会存放 `(`，因此我们不需要维护一个真正的栈，只需要用一个变量模拟记录栈的大小。

```Python [sol1-Python3]
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = []
        d = 0
        for c in seq:
            if c == '(':
                d += 1
                ans.append(d % 2)
            if c == ')':
                ans.append(d % 2)
                d -= 1
        return ans
```
```C++ [sol1-C++]
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};
```
```Javascript [sol1-Javascript]
var maxDepthAfterSplit = function(seq) {
    let dep = 0;
    return seq.split("").map((value, index) => {
        if (value === '(') {
            ++dep;
            return dep % 2;
        } else {
            let ans = dep % 2;
            --dep;
            return ans;
        }
    });
};
```

**复杂度分析**

- 时间复杂度：$O(n)$，其中 $n$ 为字符串的长度。我们只需要遍历括号字符串一次。

- 空间复杂度：$O(1)$。除答案数组外，我们只需要常数个变量。

#### 方法二：找规律

**思路及算法**

我们还是使用上面的例子 `(()(())())`，但这里我们把 `(` 和 `)` 的嵌套深度分成两行：

```
括号序列   ( ( ) ( ( ) ) ( ) )
下标编号   0 1 2 3 4 5 6 7 8 9
嵌套深度   1 2 - 2 3 - - 2 - -
嵌套深度   - - 2 - - 3 2 - 2 1 
```

有没有发现什么规律？

- 左括号 `(` 的下标编号与嵌套深度的奇偶性相反，也就是说：

    - 下标编号为奇数的 `(`，其嵌套深度为偶数，分配给 `B`；

    - 下标编号为偶数的 `(`，其嵌套深度为奇数，分配给 `A`。

- 右括号 `)` 的下标编号与嵌套深度的奇偶性相同，也就是说：

    - 下标编号为奇数的 `)`，其嵌套深度为奇数，分配给 `A`；

    - 下标编号为偶数的 `)`，其嵌套深度为偶数，分配给 `B`。

这样以来，我们只需要根据每个位置是哪一种括号以及该位置的下标编号，就能确定将对应的对应的括号分到哪个组了。

对此规律感兴趣的同学的同学可以阅读下面的证明部分，若不感兴趣，可以直接跳到代码部分。

**证明**

- 对于字符串中的任意一个左括号 $($，它的下标编号为 $x$，嵌套深度为 $y$。如果它之有 $l$ 个左括号和 $r$ 个右括号，那么根据嵌套深度的定义，有：

    $$
    y = l - r + 1
    $$
    
  下标编号与 $l$ 和 $r$ 的关系也可以直接得到，注意下标编号从 $0$ 开始：

    $$
    x = l + r
    $$

  由于 $l - r$ 和 $l + r$ 同奇偶，因此 $l - r + 1$（即 $y$）和 $l + r$（即 $x$）的奇偶性相反。

- 对于字符串中的任意一个右括号 $)$，它的下标编号为 $x$，嵌套深度为 $y$。如果它之有 $l$ 个左括号和 $r$ 个右括号，那么根据嵌套深度的定义，有：

    $$
    y = l - r
    $$
    
  下标编号与 $l$ 和 $r$ 的关系也可以直接得到，注意下标编号从 $0$ 开始：

    $$
    x = l + r
    $$

  因此 $y$ 和 $x$ 的奇偶性相同。

```Python [sol2-Python3]
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = list()
        for i, ch in enumerate(seq):
            if ch == '(':
                ans.append(i % 2)
            else:
                ans.append(1 - i % 2)
            # 上面的代码也可以简写成
            # ans.append((i & 1) ^ (ch == '('))
            # C++ 和 Javascript 代码中直接给出了简写的方法
        return ans
```
```C++ [sol2-C++]
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        for (int i = 0; i < (int)seq.size(); ++i) {
            ans.push_back(i & 1 ^ (seq[i] == '('));
        }
        return ans;
    }
};
```
```Javascript [sol2-Javascript]
var maxDepthAfterSplit = function(seq) {
    return seq.split("").map((value, index) => index & 1 ^ (value === '('));
};
```

**复杂度分析**

- 时间复杂度：$O(n)$，其中 $n$ 为字符串的长度。我们只需要遍历括号字符串一次。

- 空间复杂度：$O(1)$。除答案数组外，我们只需要常数个变量。