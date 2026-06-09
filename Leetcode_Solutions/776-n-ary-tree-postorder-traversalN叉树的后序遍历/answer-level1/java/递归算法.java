### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
99.69%
的用户
内存消耗 :
39.9 MB
, 在所有 java 提交中击败了
100.00%
的用户

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
class Solution {
    private ArrayList<Integer> list = new ArrayList<Integer>();
    public List<Integer> postorder(Node root) {
        f(root);
        return list;
    }
    private void f(Node root) {
        if (root == null) {
            return;
        }
        // 从去最左端的结点
        if (root.children.size() != 0 ) {
            f(root.children.get(0));
        }
        // 访问索引为i的孩子
        for (int i = 1; i < root.children.size(); i++) {
            f(root.children.get(i));
        }
        // 添加到list中
        list.add(root.val);
    }
}
```