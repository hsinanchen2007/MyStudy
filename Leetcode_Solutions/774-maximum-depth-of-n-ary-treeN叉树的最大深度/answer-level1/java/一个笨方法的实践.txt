### 解题思路
以前面试遇到过类似的，当时紧张就说了个一层层遍历的笨方法，现在实践一下。。。

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
class Solution {
    public int maxDepth(Node root) {
        if (null == root) {
			return 0;
		}

		// 层数 将root节点已经算进去
		int level = 1;

		// 上层数目
		int fcount = 1;

		// 下层数目
		int ccount = 0;

		Queue<Node> queue = new LinkedList<Node>();
		queue.add(root);
		while (!queue.isEmpty()) {
			Node node = queue.poll();
			fcount--;

			List<Node> children = node.children;
			
			if(null != children) {
				for (Node node2 : children) {
					ccount++;
					queue.add(node2);
				}
			}

			if (fcount == 0 && ccount != 0) {
				level++;
				// 当上一层节点遍历完成后，遍历下一层节点
				fcount = ccount;
                ccount = 0;
			}

		}
		return level;

    }
}
```