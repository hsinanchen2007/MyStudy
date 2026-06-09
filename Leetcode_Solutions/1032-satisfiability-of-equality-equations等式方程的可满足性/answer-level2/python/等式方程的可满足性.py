#### 方法：联通分量

**思路**

所有相互等于的变量能组成一个联通分量。举一个例子，如果 `a=b, b=c, c=d`，那么 `a, b, c, d` 就在同一个联通分量中，因为它们必须相等。

**算法**

第一步，我们基于给定的等式，用深度优先遍历将每一个变量按照联通分量染色。

将联通分量染色之后，我们分析形如 `a != b` 的不等式。如果两个分量有相同的颜色，那么它们一定相等，因此如果说它们不相等的话，就一定无法满足给定的方程组。

否则，我们的染色就可以看作是一组能满足方程组约束的方案，所以结果是 `true`。

```java [xvmEghMo-Java]
class Solution {
    public boolean equationsPossible(String[] equations) {
        ArrayList<Integer>[] graph = new ArrayList[26];
        for (int i = 0; i < 26; ++i)
            graph[i] = new ArrayList();

        for (String eqn: equations) {
            if (eqn.charAt(1) == '=') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                graph[x].add(y);
                graph[y].add(x);
            }
        }

        int[] color = new int[26];
        int t = 0;
        for (int start = 0; start < 26; ++start) {
            if (color[start] == 0) {
                t++;
                Stack<Integer> stack = new Stack();
                stack.push(start);
                while (!stack.isEmpty()) {
                    int node = stack.pop();
                    for (int nei: graph[node]) {
                        if (color[nei] == 0) {
                            color[nei] = t;
                            stack.push(nei);
                        }
                    }
                }
            }
        }

        for (String eqn: equations) {
            if (eqn.charAt(1) == '!') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                if (x == y || color[x] != 0 && color[x] == color[y])
                    return false;
            }
        }

        return true;
    }
}
```
```python [xvmEghMo-Python]
class Solution(object):
    def equationsPossible(self, equations):
        graph = [[] for _ in xrange(26)]

        for eqn in equations:
            if eqn[1] == '=':
                x = ord(eqn[0]) - ord('a')
                y = ord(eqn[3]) - ord('a')
                graph[x].append(y)
                graph[y].append(x)

        color = [None] * 26
        t = 0
        for start in xrange(26):
            if color[start] is None:
                t += 1
                stack = [start]
                while stack:
                    node = stack.pop()
                    for nei in graph[node]:
                        if color[nei] is None:
                            color[nei] = t
                            stack.append(nei)

        for eqn in equations:
            if eqn[1] == '!':
                x = ord(eqn[0]) - ord('a')
                y = ord(eqn[3]) - ord('a')
                if x == y: return False # lee
                if color[x] is not None and color[x] == color[y]:
                    return False
        return True
```


**复杂度分析**

* 时间复杂度：  $O(N)$，其中 $N$ 是方程组 `equations` 的数量。

* 空间复杂度：  $O(1)$，认为字母表的大小是 $O(1)$ 的。
  

  
