这是我们一些人在大学期间可能面临的非常普遍的问题。我们可能想修一些感兴趣的课程。然而，如我们所知，大多数课程都有很多与之相关的先修要求。其中一些要求是硬性的，而另一些则仅仅是“建议的”要求，可以接受也可以不接受。然而，为了保证全面的学习，我们还是应该遵循建议的先修要求。如何决定选修的课程顺序，才能避免错过任何科目？

正如在问题陈述中提到的，本问题非常适合基于图的算法，可以很容易地将问题中的元素建模为一个图。在继续讨论解法前，我们先来看看问题和其中要素的图表示。

我们可以用图的形式将问题中的信息建模。

* 令$G(V, E)$为一个`有向`, `无权` 图。
* 每门课程为图中的一个结点。
* 根据课程之间的先修关系对边缘进行建模。问题中给出的刑如$[a, b]$的二元组代表课程 `b`是课程 `a`的先修课程。这可以用一条 `有向边 b ➔ a` 表示。
* 由于可能存在循环，图G是一个循环图。若图为非循环图，则题中要求的课程排序`总是`可能的。题中说明了这样的排序可能不存在，这说明图是循环图。

让我们看一个表示一组可能课程排序的示例图，以及一组不可能课程排序的示例图。这两张示例图能帮助解释我们的解法。

![image.png](https://pic.leetcode-cn.com/f2e99f870046c980322914283b457ca14634c2ef1c7ec949f02f6851c8dee9a4-image.png){:width=450}
{:align=center}

对于上述图，一个可能的排序是: `C6 ➔ C4 ➔ C1 ➔ C5 ➔ C2 ➔ C3` ，另一个可能的排序是 `C6 ➔ C4 ➔ C5 ➔ C1 ➔ C2 ➔ C3`。下面我们来看一个不可能完成课程排序的图。

![image.png](https://pic.leetcode-cn.com/7f3cd8b54e4f28be65176542da0c8cecbfe9ce3776c23c4be805a3393956234c-image.png){:width=450}
{:align=center}

前一张图中改变的边用红色高亮显示。

> 显然，图中的循环说明不可能存在一个合适的课程排序。直观而言，不可能有两个课程互相为先修课程。对更大的循环也是同样的道理。

这样的课程排序可以称为一个`拓扑排序` ，这是图领域中的一个常见算法问题。本文将介绍解决问题的两种方法。
<br>
<br>

---

#### 方法一: 深度优先搜索

**直觉**

假设我们正处在深度优先遍历过程中的一个结点。称此结点为`A`。

> 深度优先搜索的流程是，在完成A的递归并移动到其他节点之前，我们将考虑源自A的所有可能路径。路径中源自节点A的所有节点都将A作为祖先。这正好符合我们的问题，因为从课程A开始的路径中的所有课程都以A为先修。

现在我们知道了如何获得所有以特定课程为先修的课程。如果课程的有效排序存在，那么“A”课程将优先于所有其他以它为先修的课程。这个思路可以通过深度优先搜索来实现。我们先看一下伪代码，然后再看正式算法。

```
➔ let S be a stack of courses
➔ function dfs(node)
➔     for each nei***or in adjacency list of node
➔          dfs(nei***or)
➔     add node to S  
```
下面来看根据这一思路的算法。

**算法**

1. 初始化栈 `S`，它将存储图中课程的拓扑排序。
2. 使用输入中提供的边构建邻接表。注意输入中如 `[a, b]` 的边代表课程 `b`是课程 `a`的先修课程。这代表边 `b ➔ a`。在实现算法时，请记住这一点。
3. 对于图中的每个结点，都运行一次深度优先搜索，以防该结点没有在其他结点的深度优先搜索中被访问到过。
4. 假设我们正在执行结点 `N`的深度优先搜索。我们将递归地遍历结点 `N` 所有未被处理过的邻接结点。
5. 处理完了所有邻接结点后，将结点`N`入栈。我们利用栈来模拟所需要的顺序。当结点 `N`入栈时，所有以`N` 为先修的课程结点均已经入栈。
6. 在所有的结点被处理过后，从栈顶到栈底顺序依次返回结点元素。

在进入正式实现之前，先让我们通过示例图查看算法的运行过程。

<![image.png](https://pic.leetcode-cn.com/48fd0e7eb044b2a20d480ceea21aeeb2bfd5010256c58f01aae82832f283b464-image.png),![image.png](https://pic.leetcode-cn.com/43a50179b137d3f4aa6593b57ac7b7a3883af80314827023e32a87acf4c2eed6-image.png),![image.png](https://pic.leetcode-cn.com/6d3c1126d636f52c38f59b7df8994a7e1c10fa8b7ed68791246308a7b5b4e561-image.png),![image.png](https://pic.leetcode-cn.com/8b3c7b56e874b0fd8bff60b32e3b7d33e1a356acb401d7865e92e7ccf1daa616-image.png),![image.png](https://pic.leetcode-cn.com/52224c6f93e2be3c8cc72b02643f8a50f0d6f02d7992ae9a0380722e4207844c-image.png),![image.png](https://pic.leetcode-cn.com/50e9579b027cf34ec44809c24406ba9f610fab7a437384a631b16ed759b0adef-image.png),![image.png](https://pic.leetcode-cn.com/b466ed7416009b35066d64c1ff7f61d3dba8bdbc55e6ae44c4434344d8856a02-image.png),![image.png](https://pic.leetcode-cn.com/0dd922cc410e36954d721f073feb40e8765224c952ca7ab5b81eb66bf906e41d-image.png),![image.png](https://pic.leetcode-cn.com/b3e9187230bd3689c41ed0516271ac70ca04dbf6c3bba999e7155a4d1b5dd5cd-image.png),![image.png](https://pic.leetcode-cn.com/f8812d314842e721b972aa91b5ce58cf1fe541024fcf9ab52a266be2223147a2-image.png),![image.png](https://pic.leetcode-cn.com/1b12d83de8f270a1b82c00031751bf86e68cc213175bfa2bac0b6ee4aa2946e5-image.png),![image.png](https://pic.leetcode-cn.com/d08f06f61ebab3b1e983384afe234720425581302f95f5cb3b7ed2daff6f5693-image.png),![image.png](https://pic.leetcode-cn.com/825f857c7658d1fb5ee4d5aef9e148202ea85aedfc54c6952ba74688c1a8b377-image.png),![image.png](https://pic.leetcode-cn.com/954318b08e0650132f0a0b64c89f3f0e131b5ead681095a7fe32f0d9702a4da1-image.png),![image.png](https://pic.leetcode-cn.com/bcb1e023987f7283876c39b9c211d383262478c72ea40ea79edf4d25f63c8d3e-image.png),![image.png](https://pic.leetcode-cn.com/63a3ecafb8df1e8cc69a3b70d529f5b38577e123b85091a4dd143f665d767176-image.png),![image.png](https://pic.leetcode-cn.com/ef22bc8e7768879b98e87cbed21bb869a5c18ee9187e7110dc6f504cb4822390-image.png),![image.png](https://pic.leetcode-cn.com/1756642f0222339bd34cbabed087409a37efd27a0b9235cdae0f2b43ec64aa6b-image.png),![image.png](https://pic.leetcode-cn.com/c704176f2ef22a6a88212f6804f5402507311a822c78b65a63efc2de3458e87f-image.png),![image.png](https://pic.leetcode-cn.com/db06f24e0f1da9c29a7c379816b3ff9d2c4de853c16160b9427394afbb379d9d-image.png)>





> 关于拓扑排序顺序需要注意的一点是，节点（课程）不一定只有一种排序，而可能有多中。例如，在上面的图中，我们可以在执行“b”之前处理节点“d”，这样就有了另一种排序。

```Java [solution 1]
class Solution {
  static int WHITE = 1;
  static int GRAY = 2;
  static int BLACK = 3;

  boolean isPossible;
  Map<Integer, Integer> color;
  Map<Integer, List<Integer>> adjList;
  List<Integer> topologicalOrder;

  private void init(int numCourses) {
    this.isPossible = true;
    this.color = new HashMap<Integer, Integer>();
    this.adjList = new HashMap<Integer, List<Integer>>();
    this.topologicalOrder = new ArrayList<Integer>();

    // By default all vertces are WHITE
    for (int i = 0; i < numCourses; i++) {
      this.color.put(i, WHITE);
    }
  }

  private void dfs(int node) {

    // Don't recurse further if we found a cycle already
    if (!this.isPossible) {
      return;
    }

    // Start the recursion
    this.color.put(node, GRAY);

    // Traverse on nei***oring vertices
    for (Integer nei***or : this.adjList.getOrDefault(node, new ArrayList<Integer>())) {
      if (this.color.get(nei***or) == WHITE) {
        this.dfs(nei***or);
      } else if (this.color.get(nei***or) == GRAY) {
        // An edge to a GRAY vertex represents a cycle
        this.isPossible = false;
      }
    }

    // Recursion ends. We mark it as black
    this.color.put(node, BLACK);
    this.topologicalOrder.add(node);
  }

  public int[] findOrder(int numCourses, int[][] prerequisites) {

    this.init(numCourses);

    // Create the adjacency list representation of the graph
    for (int i = 0; i < prerequisites.length; i++) {
      int dest = prerequisites[i][0];
      int src = prerequisites[i][1];
      List<Integer> lst = adjList.getOrDefault(src, new ArrayList<Integer>());
      lst.add(dest);
      adjList.put(src, lst);
    }

    // If the node is unprocessed, then call dfs on it.
    for (int i = 0; i < numCourses; i++) {
      if (this.color.get(i) == WHITE) {
        this.dfs(i);
      }
    }

    int[] order;
    if (this.isPossible) {
      order = new int[numCourses];
      for (int i = 0; i < numCourses; i++) {
        order[i] = this.topologicalOrder.get(numCourses - i - 1);
      }
    } else {
      order = new int[0];
    }

    return order;
  }
}
```

```Python [solution 1]
from collections import defaultdict
class Solution:

    WHITE = 1
    GRAY = 2
    BLACK = 3

    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """

        # Create the adjacency list representation of the graph
        adj_list = defaultdict(list)

        # A pair [a, b] in the input represents edge from b --> a
        for dest, src in prerequisites:
            adj_list[src].append(dest)

        topological_sorted_order = []
        is_possible = True

        # By default all vertces are WHITE
        color = {k: Solution.WHITE for k in range(numCourses)}
        def dfs(node):
            nonlocal is_possible

            # Don't recurse further if we found a cycle already
            if not is_possible:
                return

            # Start the recursion
            color[node] = Solution.GRAY

            # Traverse on nei***oring vertices
            if node in adj_list:
                for nei***or in adj_list[node]:
                    if color[nei***or] == Solution.WHITE:
                        dfs(nei***or)
                    elif color[nei***or] == Solution.GRAY:
                         # An edge to a GRAY vertex represents a cycle
                        is_possible = False

            # Recursion ends. We mark it as black
            color[node] = Solution.BLACK
            topological_sorted_order.append(node)

        for vertex in range(numCourses):
            # If the node is unprocessed, then call dfs on it.
            if color[vertex] == Solution.WHITE:
                dfs(vertex)

        return topological_sorted_order[::-1] if is_possible else []
```

**复杂度分析**

* 时间复杂度: $O(N)$，其中$N$为课程数。我们需要要对森林中的所有结点执行完全的深度优先搜索。之所以是森林而不是图，是因为并非所有结点都连接在一起。也可能存在不连通的部分。
* 空间复杂度: $O(N)$, 递归栈占用的空间(不是用于存储拓扑排序的栈)。
<br>
<br>

---

#### 方法二: 利用结点的入度

**直觉**

这种方法更容易直观地思考，这从下面关于拓扑排序的观点/事实可以清楚地看到。

>拓扑排序中的第一个节点将是没有任何入边的节点。事实上，任何具有0入度的节点都可以开始拓扑排序。如果有多个这样的节点，它们的相对顺序并不重要，可以以任何顺序出现。

我们的算法就基于这个思路。首先处理入度为0的所有节点/课程（没有先修课程）。如果从图中删除所有这些课程，以及它们的出边，就可以找到下一步应该处理的课程/节点。这些节点也是入度为0的节点。重复这样做，直到所有的课程都被考虑在内。

**算法**

1. 初始化一个队列 `Q`来记录图中0入度的所有结点。
2. 遍历输入中的所有边，创建邻接表并存储每个结点的入度。
3. 将所有入度为0的边加入 `Q`.
4. 执行以下操作直到 `Q`为空。
    1. 从 `Q`中弹出一个元素。不妨称为 `N`。
    2. 对 `N`的所有邻接节点, 将其入度减去1。若任意结点的入度变为0，将其加入`Q`。
    3. 将节点`N`加入到存储拓扑排序的列表中。
    4. 回到4.1。图中的每个结点都处理了一次。

在进入正式实现之前，先让我们通过示例图查看算法的运行过程。

<![image.png](https://pic.leetcode-cn.com/58f61a0191133da762913c2805c47df44e51f5f960a5034a83ac18703da28da2-image.png),![image.png](https://pic.leetcode-cn.com/7e3651cc1466c1742c95aa2b8e96bcb98608430b93c3e3148187f8bc60598c9b-image.png),![image.png](https://pic.leetcode-cn.com/48020b1ad252572469efd8749cf9959b2aad49dacc8d0eed4b95703af378139b-image.png),![image.png](https://pic.leetcode-cn.com/23d59d03758bba8810ed872cd7a6ced5675341818f4f8c6654ffdc54bbcf5a18-image.png),![image.png](https://pic.leetcode-cn.com/d2388e777f63a2d06ebdd9761268d4b69cf0debfb8e30a13ca2427c473b4dc37-image.png),![image.png](https://pic.leetcode-cn.com/0423f6737b3a96a450794416346e75ba8e45a66b78482046014eadcd5c360fb4-image.png),![image.png](https://pic.leetcode-cn.com/21915095540a56cd7a0ce65f2e1e47a8c063f6acfc5edf46b7322c8151741cd7-image.png),![image.png](https://pic.leetcode-cn.com/0ab2447b53af886d76896ab73578701b86c192ebdee4df403b44667f2277272e-image.png),![image.png](https://pic.leetcode-cn.com/94ad480af7f0e1b49e67522fab311c8a54396fdd1a4f10d31eafd0830bdcf515-image.png),![image.png](https://pic.leetcode-cn.com/672618dc5bea527a545ef467157b08044268c397b2e3085ab79c7966299d7114-image.png),![image.png](https://pic.leetcode-cn.com/2d289a9d5d12804630acf7c58971e88e54380555ef1c3798b9aac27ee444076c-image.png),![image.png](https://pic.leetcode-cn.com/9c6dae050a78be2cdb5c890526621c03fba7cb5caa75e15a9636507ef60f7c42-image.png),![image.png](https://pic.leetcode-cn.com/2dee343bd67c57fe320f2698d5ff6449f798dd3bde9289911bcdb0cdd2637f4b-image.png),![image.png](https://pic.leetcode-cn.com/c19c0fbde3768e638a0a0dd9dcbe8f1a9756e52ffa5dfcc5c95e195ebd3f1068-image.png)>



这里需要注意的是，本算法不一定要使用队列，也可以用栈。但是，由于两个数据结构的访问模式不同，获得的顺序也不同。

```Java [solution 2]
class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {

    boolean isPossible = true;
    Map<Integer, List<Integer>> adjList = new HashMap<Integer, List<Integer>>();
    int[] indegree = new int[numCourses];
    int[] topologicalOrder = new int[numCourses];

    // Create the adjacency list representation of the graph
    for (int i = 0; i < prerequisites.length; i++) {
      int dest = prerequisites[i][0];
      int src = prerequisites[i][1];
      List<Integer> lst = adjList.getOrDefault(src, new ArrayList<Integer>());
      lst.add(dest);
      adjList.put(src, lst);

      // Record in-degree of each vertex
      indegree[dest] += 1;
    }

    // Add all vertices with 0 in-degree to the queue
    Queue<Integer> q = new LinkedList<Integer>();
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.add(i);
      }
    }

    int i = 0;
    // Process until the Q becomes empty
    while (!q.isEmpty()) {
      int node = q.remove();
      topologicalOrder[i++] = node;

      // Reduce the in-degree of each nei***or by 1
      if (adjList.containsKey(node)) {
        for (Integer nei***or : adjList.get(node)) {
          indegree[nei***or]--;

          // If in-degree of a nei***or becomes 0, add it to the Q
          if (indegree[nei***or] == 0) {
            q.add(nei***or);
          }
        }
      }
    }

    // Check to see if topological sort is possible or not.
    if (i == numCourses) {
      return topologicalOrder;
    }

    return new int[0];
  }
}
```
```Python [solution 2]
from collections import defaultdict
class Solution:

    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """

        # Prepare the graph
        adj_list = defaultdict(list)
        indegree = {}
        for dest, src in prerequisites:
            adj_list[src].append(dest)

            # Record each node's in-degree
            indegree[dest] = indegree.get(dest, 0) + 1

        # Queue for maintainig list of nodes that have 0 in-degree
        zero_indegree_queue = [k for k in range(numCourses) if k not in indegree]

        topological_sorted_order = []

        # Until there are nodes in the Q
        while zero_indegree_queue:

            # Pop one node with 0 in-degree
            vertex = zero_indegree_queue.pop(0)
            topological_sorted_order.append(vertex)

            # Reduce in-degree for all the nei***ors
            if vertex in adj_list:
                for nei***or in adj_list[vertex]:
                    indegree[nei***or] -= 1

                    # Add nei***or to Q if in-degree becomes 0
                    if indegree[nei***or] == 0:
                        zero_indegree_queue.append(nei***or)

        return topological_sorted_order if len(topological_sorted_order) == numCourses else []
```

**复杂度分析**

* 时间复杂度: $O(N)$。图中的每个结点都处理了一次。 
* 空间复杂度: $O(N)$。我们使用了一个中间的队列数据结构来存储所有具有0入度的结点。在最坏的情况下，没有任何先修关系，队列会包括所有的结点。
<br/>
