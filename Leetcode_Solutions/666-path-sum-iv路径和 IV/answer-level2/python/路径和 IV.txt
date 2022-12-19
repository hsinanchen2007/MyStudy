####  方法一：转换成树 [Accepted]
将数组给定的数据构造一颗树。然后计算从根节点到每个叶子结点的路径之和，就得到答案。

**算法：**
- 分为两个步骤，构造树和遍历树。
- 在树的构造过程中，我们有深度、位置和权值这些信息，我们可以根据条件 `pos - 1 < 2*(depth - 2)` 来判断结点在右边还是左边。例如，当 `depth = 4` 时，`pos` 可取 `1, 2, 3, 4, 5, 6, 7, 8`，当 `pos<=4` 时，结点的位置在左边。
- 在遍历过程中，我们执行深度优先搜索的策略遍历树，并沿着我们所走过的路径记录当前和。每当我们到达一个叶结点 `(node.left == null && node.right == null)` 时，将该路径的和添加到答案中。

```Python [ ]
class Node(object):
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution(object):
    def pathSum(self, nums):
        self.ans = 0
        root = Node(nums[0] % 10)

        for x in nums[1:]:
            depth, pos, val = x/100, x/10 % 10, x % 10
            pos -= 1
            cur = root
            for d in xrange(depth - 2, -1, -1):
                if pos < 2**d:
                    cur.left = cur = cur.left or Node(val)
                else:
                    cur.right = cur = cur.right or Node(val)

                pos %= 2**d

        def dfs(node, running_sum = 0):
            if not node: return
            running_sum += node.val
            if not node.left and not node.right:
                self.ans += running_sum
            else:
                dfs(node.left, running_sum)
                dfs(node.right, running_sum)

        dfs(root)
        return self.ans
```

```Java [ ]
class Solution {
    int ans = 0;
    public int pathSum(int[] nums) {
        Node root = new Node(nums[0] % 10);
        for (int num: nums) {
            if (num == nums[0]) continue;
            int depth = num / 100, pos = num / 10 % 10, val = num % 10;
            pos--;
            Node cur = root;
            for (int d = depth - 2; d >= 0; --d) {
                if (pos < 1<<d) {
                    if (cur.left == null) cur.left = new Node(val);
                    cur = cur.left;
                } else {
                    if (cur.right == null) cur.right = new Node(val);
                    cur = cur.right;
                }
                pos %= 1<<d;
            }
        }

        dfs(root, 0);
        return ans;
    }

    public void dfs(Node node, int sum) {
        if (node == null) return;
        sum += node.val;
        if (node.left == null && node.right == null) {
            ans += sum;
        } else {
            dfs(node.left, sum);
            dfs(node.right, sum);
        }
    }
}

class Node {
    Node left, right;
    int val;
    Node(int v) {val = v;}
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 是 `nums` 的长度。
* 空间复杂度：$O(N)$，深度优先搜索中隐式调用堆栈的大小。


####  方法二：直接遍历 [Accepted]
**算法：**
在方法 1 中，我们将在树上进行深度优先搜索。一个省时的想法是，我们根据等式 `root = num / 10 = 10 * depth + pos` 作为根节点的唯一标识符。则左子结点的标识符是 `left = 10 * (depth + 1) + 2 * pos - 1`，而右子节点则是 `right = left + 1`。

```Python [ ]
class Solution(object):
    def pathSum(self, nums):
        self.ans = 0
        values = {x / 10: x % 10 for x in nums}
        def dfs(node, running_sum = 0):
            if node not in values: return
            running_sum += values[node]
            depth, pos = divmod(node, 10)
            left = (depth + 1) * 10 + 2 * pos - 1
            right = left + 1

            if left not in values and right not in values:
                self.ans += running_sum
            else:
                dfs(left, running_sum)
                dfs(right, running_sum)

        dfs(nums[0] / 10)
        return self.ans
```

```Java [ ]
class Solution {
    int ans = 0;
    Map<Integer, Integer> values;
    public int pathSum(int[] nums) {
        values = new HashMap();
        for (int num: nums)
            values.put(num / 10, num % 10);

        dfs(nums[0] / 10, 0);
        return ans;
    }

    public void dfs(int node, int sum) {
        if (!values.containsKey(node)) return;
        sum += values.get(node);

        int depth = node / 10, pos = node % 10;
        int left = (depth + 1) * 10 + 2 * pos - 1;
        int right = left + 1;

        if (!values.containsKey(left) && !values.containsKey(right)) {
            ans += sum;
        } else {
            dfs(left, sum);
            dfs(right, sum);
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。
* 空间复杂度：$O(N)$，分析与方法 1 相同。