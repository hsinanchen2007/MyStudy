### 解法一：递归

代码：
```java
class Solution {
    private List<Integer> res;
    public List<Integer> postorder(Node root) {
        res = new LinkedList<>();
        dfs(root);
        return res;
    }
    private void dfs(Node root) {
        if(root == null)    return;
        for(Node child : root.children)
            dfs(child);
        res.add(root.val);
    }
}
```

### 解法二：迭代
建议先完成题目589.N叉树的前序遍历，有助于本题的解决。
[N叉树的前序遍历题解](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/solution/marveljian-dan-de-xue-xi-bi-ji-589-by-tyanyonecanc/)

首先，我们需要的遍历顺序为：左->右->根。

其次，上面链接的题解提到了，如果对层序遍历进行改造，即结点每次都从队尾出列，然后再将子结点从左到右入列，很容易发现，这是一种根->右->左的前序遍历。
根->右->左，而我们需要的是左->右->根。
是否得到了什么启发？
显然，把根->右->左得到的顺序颠倒，就是答案左->右->根，即后序遍历。
由于还是从队尾出列，还是后进先出，故还是使用栈代替队列。
颠倒的方式很简单，就是每次都把值添加到结果List的开头即可。

代码：
```java
class Solution {
    public List<Integer> postorder(Node root) {
        LinkedList<Integer> res = new LinkedList<>();
        if(root == null)    return res;
        Stack<Node> sta = new Stack<>();
        sta.push(root);
        while(!sta.isEmpty())
        {
            Node cur = sta.pop();
            res.offerFirst(cur.val);
            for(Node child : cur.children)
                sta.push(child);
        }
        return res;
    }
}
```