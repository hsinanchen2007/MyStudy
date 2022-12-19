### 解题思路
子节点不为空，那么收集深度到一个list，获取list中最大值，返回给上层调用

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
import java.util.Optional;

class Solution {
    public int maxDepth(Node root) {
		if (root == null) return 0;
		List<Integer> list = new ArrayList<>();
		if (root.children != null) 
			for (Node cur : root.children)
				list.add(maxDepth(cur));
		// return list.isEmpty() ? 1 : list.stream().max(Integer::compare).get();
        return list.isEmpty() ? 1 : Collections.max(list) + 1;
	}
}
```