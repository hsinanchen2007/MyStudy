#### 方法一：递归

我们可以使用递归的方法得到二叉树的前序遍历。在递归时，根据题目描述，我们需要加上额外的括号，会有以下 `4` 种情况：

- 如果当前节点有两个孩子，那我们在递归时，需要在两个孩子的结果外都加上一层括号；

- 如果当前节点没有孩子，那我们不需要在节点后面加上任何括号；

![No_child](https://pic.leetcode-cn.com/Figures/606/606_Case2.PNG)
{:align="center"}

- 如果当前节点只有左孩子，那我们在递归时，只需要在左孩子的结果外加上一层括号，而不需要给右孩子加上任何括号；

![Left_child](https://pic.leetcode-cn.com/Figures/606/606_Case3.PNG)
{:align="center"}

- 如果当前节点只有右孩子，那我们在递归时，需要先加上一层空的括号 `()` 表示左孩子为空，再对右孩子进行递归，并在结果外加上一层括号。

![Right_child](https://pic.leetcode-cn.com/Figures/606/606_Case4.PNG)
{:align="center"}

考虑完上面的 `4` 种情况，我们就可以得到最终的字符串。

```Java [sol1]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public String tree2str(TreeNode t) {
        if(t==null)
            return "";
        if(t.left==null && t.right==null)
            return t.val+"";
        if(t.right==null)
            return t.val+"("+tree2str(t.left)+")";
        return t.val+"("+tree2str(t.left)+")("+tree2str(t.right)+")";   
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是二叉树中的节点数目。

* 空间复杂度：$O(N)$，在最坏情况下，会递归 $N$ 层，需要 $O(N)$ 的栈空间。

#### 方法二：迭代

我们也可以用迭代的方法解决这个问题。

我们用一个栈来存储树中的一些节点，其中栈顶的元素为当前遍历到的节点，从栈底到栈顶的元素在树上即为从根到当前节点的唯一路径。和迭代得到前序遍历的方法略有不同，由于这里需要输出额外的括号，因此我们还需要用一个集合存储所有遍历过的节点，具体的原因在接下来会说明。

首先我们把根节点入栈。对于当前栈顶的元素，如果它没有遍历过，那么就把它加入到集合中，并开始对以它为根的子树进行前序遍历。我们先在答案末尾添加一个 `(`，表示一个节点的开始，然后判断该节点的子节点个数。和方法一相同，这里会出现四种情况：如果它没有子节点，我们什么都不做；如果它有两个子节点，那么我们先将右孩子入栈，再将左孩子入栈，这样就保证了前序遍历的顺序；如果它只有左孩子，那么我们将左孩子入栈；如果它只有右孩子，那么我们在答案末尾添加一个 `()` 表示空的左孩子，再将右孩子入栈。注意这四种情况中，我们都不会将当前节点出栈，原因是我们一开始添加了 `(` 表示节点的开始，在以当前节点为根的子树中所有节点遍历完成之后，我们才会在答案末尾添加 `)` 表示节点的结束。因此我们需要用上面提到的集合来存储遍历过的节点，如果当前栈顶的元素遍历过，那么我们就知道需要在答案末尾添加 `)`，并将这个节点出栈。

在迭代完成之后，我们得到的答案字符串的前后会有一对括号，我们把它去除后就可以得到最终的答案。

<![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/606/Construct_Binary_Tree_stackSlide13.PNG)>

```Java [sol2]
public class Solution {
    public String tree2str(TreeNode t) {
        if (t == null)
            return "";
        Stack < TreeNode > stack = new Stack < > ();
        stack.push(t);
        Set < TreeNode > visited = new HashSet < > ();
        StringBuilder s = new StringBuilder();
        while (!stack.isEmpty()) {
            t = stack.peek();
            if (visited.contains(t)) {
                stack.pop();
                s.append(")");
            } else {
                visited.add(t);
                s.append("(" + t.val);
                if (t.left == null && t.right != null)
                    s.append("()");
                if (t.right != null)
                    stack.push(t.right);
                if (t.left != null)
                    stack.push(t.left);
            }
        }
        return s.substring(1, s.length() - 1);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是二叉树中的节点数目。

* 空间复杂度：$O(N)$，在最坏情况下，栈中会存放 $N$ 个节点。