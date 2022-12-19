### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.ArrayList;
import java.util.List;

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
class Solution {

	List<List<Integer>> list = new ArrayList<>();
	static int height = 0;

	public List<List<Integer>> levelOrder(Node root) {
		return levelOrder(root, 0);
	}

	private List<List<Integer>> levelOrder(Node root, int i) {
		if (root == null) {
			return list;
		}
		if (list.size() == i) {
			List<Integer> levelList = new ArrayList<>();
			levelList.add(root.val);
			list.add(levelList);
		} else {
			list.get(i).add(root.val);
		}
		i++;
		if (root.children != null) {
			for (int k = 0; k < root.children.size(); k++) {
				levelOrder(root.children.get(k), i);
			}
		}
		return list;

	}
}

```