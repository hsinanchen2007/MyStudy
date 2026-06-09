#### 方法一：拓扑排序

假设一个求和公式为 $C1 = C2 + C3$，如果我们更改了 $C2$ 或 $C3$ 的值，那么 $C1$ 的值也会被改变。进一步而言，如果有另一个求和公式 $D1 = C1 + D2$，那么更改 $C2$ 的值也会导致 $D1$ 的值被改变。

因此我们在更改了 $C2$ 的值后，应当找到所有相关的格子，对它们的值进行更改。在公式 $C1 = C2 + C3$ 中，我们称 $C1$ 依赖于 $C2$ 和 $C3$；在公式 $D1 = C1 + D2$ 中，我们称 $D1$ 依赖于 $C1$ 和 $D2$，也间接依赖于 $C2$ 和 $C3$。我们在更改了 $C2$ 后，需要找到所有直接或间接依赖于 $C2$ 的那些格子。

我们把每个格子看成有向图中的一个节点，如果 `x` 依赖于 `y`，那么我们从 `y` 到 `x` 连一条有向边。由于题目保证不会有循环求和，因此这个有向图是一个有向无环图。对于某个节点 `xc`，当它的值被更改后，所有它可以走到的节点 `xp[1..k]` 都需要被更改。同时，这 `k` 个可以走到的节点需要指定修改顺序，例如上面的例子 $C1 = C2 + C3$ 与 $D1 = C1 + D2$，我们应该先修改前者 $C1$ 的值，再修改后者 $D1$ 的值，因此我们可以使用拓扑排序来解决这个问题。例如下图的一种拓扑排序为 `5 4 2 3 1 0`，那么如果我们修改了节点 `5` 的值，按照 `5 4 2 3 1 0` 的顺序依次修改节点的值是合理的。

![Topological_Sort_Graph](https://pic.leetcode-cn.com/Figures/631/631_Design_Excel.PNG){:width=400}
{:align="center"}

在本题中，我们使用深度优先搜索的方法，借助一个栈得到拓扑排序，方法如下：

- 从被修改的节点开始进行深度优先搜索；

- 对当前节点所有未访问过的节点，递归地进行搜索；

- 将当前节点入栈；

- 在搜索结束后，从栈顶到栈底的序列就是一种可能的拓扑排序序列。

<![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/631/631_TopologicalSlide13.PNG)>

此外，我们还需要在图中额外记录每条边的权值，因为求和公式可能出现 $C1 = C2 + C3 + C2$ 的情况，此时 $C2$ 出现了两次，因此对于图中的每条边 `x -> y`，权值为 `z`，表示 `y` 的求和公式直接依赖于 `x`，并且依赖的次数为 `z`。我们可以用如下的方式实现题目中要求的所有操作：

* `Excel(int H, char W)`：建立一个 `H * W` 的表格；

* `set(int row, char column, int val)`：我们将 `(row, column)` 位置的数值改为 `val`，如果在此之前 `(row, column)` 的位置是一个求和公式，我们还需要覆盖这个求和公式，即从图中删除一系列表示依赖的有向边。随后我们从 `(row, column)` 开始，通过深度优先搜索得到拓扑排序，并依次重新计算这些格子的新值；

* `sum(int row, char column, List of Strings : numbers)`：该操作与 `set()` 类似，首先如果在此之前 `(row, column)` 的位置是一个求和公式，我们需要进行覆盖。随后我们在图中添加一系列表示这条求和公式中的依赖的有向边，再从 `(row, column)` 开始，得到拓扑排序并计算新值；

* `get(int row, char column)`：由于每次修改（无论是 `set()` 还是 `sum()`）操作后，我们都会将所有需要更新的值进行重新计算，因此 `get()` 操作只需要直接获取 `(row, column)` 位置的值即可。

```Java [sol1]
public class Excel {
    Formula[][] Formulas;
    class Formula {
        Formula(HashMap < String, Integer > c, int v) {
            val = v;
            cells = c;
        }
        HashMap < String, Integer > cells;
        int val;
    }
    Stack < int[] > stack = new Stack < > ();
    public Excel(int H, char W) {
        Formulas = new Formula[H][(W - 'A') + 1];
    }

    public int get(int r, char c) {
        if (Formulas[r - 1][c - 'A'] == null)
            return 0;
        return Formulas[r - 1][c - 'A'].val;
    }
    public void set(int r, char c, int v) {
        Formulas[r - 1][c - 'A'] = new Formula(new HashMap < String, Integer > (), v);
        topologicalSort(r - 1, c - 'A');
        execute_stack();
    }

    public int sum(int r, char c, String[] strs) {
        HashMap < String, Integer > cells = convert(strs);
        int summ = calculate_sum(r - 1, c - 'A', cells);
        set(r, c, summ);
        Formulas[r - 1][c - 'A'] = new Formula(cells, summ);
        return summ;
    }

    public void topologicalSort(int r, int c) {
        for (int i = 0; i < Formulas.length; i++)
            for (int j = 0; j < Formulas[0].length; j++)
                if (Formulas[i][j] != null && Formulas[i][j].cells.containsKey("" + (char)('A' + c) + (r + 1))) {
                    topologicalSort(i, j);
                }
        stack.push(new int[] {r,c});
    }

    public void execute_stack() {
        while (!stack.isEmpty()) {
            int[] top = stack.pop();
            if (Formulas[top[0]][top[1]].cells.size() > 0)
                calculate_sum(top[0], top[1], Formulas[top[0]][top[1]].cells);
        }
    }

    public HashMap < String, Integer > convert(String[] strs) {
        HashMap < String, Integer > res = new HashMap < > ();
        for (String st: strs) {
            if (st.indexOf(":") < 0)
                res.put(st, res.getOrDefault(st, 0) + 1);
            else {
                String[] cells = st.split(":");
                int si = Integer.parseInt(cells[0].substring(1)), ei = Integer.parseInt(cells[1].substring(1));
                char sj = cells[0].charAt(0), ej = cells[1].charAt(0);
                for (int i = si; i <= ei; i++) {
                    for (char j = sj; j <= ej; j++) {
                        res.put("" + j + i, res.getOrDefault("" + j + i, 0) + 1);
                    }
                }
            }
        }
        return res;
    }

    public int calculate_sum(int r, int c, HashMap < String, Integer > cells) {
        int sum = 0;
        for (String s: cells.keySet()) {
            int x = Integer.parseInt(s.substring(1)) - 1, y = s.charAt(0) - 'A';
            sum += (Formulas[x][y] != null ? Formulas[x][y].val : 0) * cells.get(s);
        }
        Formulas[r][c] = new Formula(cells, sum);
        return sum;
    }
}
```

**复杂度分析**

* 时间复杂度：

    - `set`：$O\big((r* c)^2\big)$，其中 $r$ 和 $c$ 是表格的高和宽。在修改某一个格子后，我们在最坏情况下需要重新计算所有格子的值，时间复杂度为 $O(r* c)$，并且对于每一个格子，它最多可能依赖于 $O(r* c)$ 个格子。

    - `sum` $O\big((r*c)^2\big)$，和 `set` 的时间复杂度相同；

    - `get`：$O(1)$，我们可以直接得到值；

* 空间复杂度：$O\big((r*c)^2\big)$，用来对于每一个格子存储依赖关系对应的有向边。