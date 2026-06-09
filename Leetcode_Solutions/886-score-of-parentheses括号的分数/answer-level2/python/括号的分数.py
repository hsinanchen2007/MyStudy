#### 方法一：分治

对于一个字符串 `S`，我们将左括号 `(` 记为 `1`，右括号记为 `-1`，如果 `S` 的某一个非空前缀对应的和为 `0`，那么这个前缀就是一个平衡括号字符串。我们遍历字符串 `S`，得到若干个前缀和为 `0` 的位置，就可以将字符串拆分为 `S = P_1 + P_2 + ... + P_n`，其中每一个 `P_i` 都是一个平衡括号字符串。这样我们就可以分别计算每一个 `P_i` 的分数再相加，即 `score(S) = score(P_1) + score(P_2) + ... + score(P_n)`。

对于一个不可拆分的平衡括号字符串，如果它为 `()`，那么就得 `1` 分，否则它的最外层一定有一对左右括号，可以将这对括号去除后继续进行拆分，再将得到的分数乘 `2`。

```Java [sol1]
class Solution {

    public int scoreOfParentheses(String S) {
        return F(S, 0, S.length());
    }

    public int F(String S, int i, int j) {
        //Score of balanced string S[i:j]
        int ans = 0, bal = 0;

        // Split string into primitives
        for (int k = i; k < j; ++k) {
            bal += S.charAt(k) == '(' ? 1 : -1;
            if (bal == 0) {
                if (k - i == 1) ans++;
                else ans += 2 * F(S, i+1, k);
                i = k+1;
            }
        }

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def scoreOfParentheses(self, S):
        def F(i, j):
            #Score of balanced string S[i:j]
            ans = bal = 0

            #Split string into primitives
            for k in xrange(i, j):
                bal += 1 if S[k] == '(' else -1
                if bal == 0:
                    if k - i == 1:
                        ans += 1
                    else:
                        ans += 2 * F(i+1, k)
                    i = k+1

            return ans

        return F(0, len(S))
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是字符串 `S` 的长度，在最坏的情况下，字符串 `S` 为 `(((((((....)))))))`，它需要拆分 $O(N)$ 次，每次遍历字符串的时间复杂度也为 $O(N)$。

* 空间复杂度：$O(N)$。

#### 方法二：栈

字符串 `S` 中的每一个位置都有一个“深度”，即该位置外侧嵌套的括号数目。例如，字符串 `(()(.()))` 中的 `.` 的深度为 `2`，因为它外侧嵌套了 `2` 层括号：`(__(.__))`。

我们用一个栈来维护当前所在的深度，以及每一层深度的得分。当我们遇到一个左括号 `(` 时，我们将深度加一，并且新的深度的得分置为 `0`。当我们遇到一个右括号 `)` 时，我们将当前深度的得分乘二并加到上一层的深度。这里有一种例外情况，如果遇到的是 `()`，那么只将得分加一。

下面给出了字符串 `(()(()))` 每次对应的栈的情况：

* `[0, 0]` `(`
* `[0, 0, 0]` `((`
* `[0, 1]` `(()`
* `[0, 1, 0]` `(()(`
* `[0, 1, 0, 0]` `(()((`
* `[0, 1, 1]` `(()(()`
* `[0, 3]` `(()(())`
* `[6]` `(()(()))`


```Java [sol2]
public int scoreOfParentheses(String S) {
    Stack<Integer> stack = new Stack();
    stack.push(0); // The score of the current frame

    for (char c: S.toCharArray()) {
        if (c == '(')
            stack.push(0);
        else {
            int v = stack.pop();
            int w = stack.pop();
            stack.push(w + Math.max(2 * v, 1));
        }
    }

    return stack.pop();
}
```

```Python [sol2]
class Solution(object):
    def scoreOfParentheses(self, S):
        stack = [0] #The score of the current frame

        for x in S:
            if x == '(':
                stack.append(0)
            else:
                v = stack.pop()
                stack[-1] += max(2 * v, 1)

        return stack.pop()
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(N)$，为栈的大小。

#### 方法三：统计核心的数目

事实上，我们可以发现，只有 `()` 会对字符串 `S` 贡献实质的分数，其它的括号只会将分数乘二或者将分数累加。因此，我们可以找到每一个 `()` 对应的深度 `x`，那么答案就是 `2^x` 的累加和。

```Java [sol3]
class Solution {

    public int scoreOfParentheses(String S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) == '(') {
                bal++;
            } else {
                bal--;
                if (S.charAt(i-1) == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
}
```

```Python [sol3]
class Solution(object):
    def scoreOfParentheses(self, S):
        ans = bal = 0
        for i, x in enumerate(S):
            if x == '(':
                bal += 1
            else:
                bal -= 1
                if S[i-1] == '(':
                    ans += 1 << bal
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(1)$。