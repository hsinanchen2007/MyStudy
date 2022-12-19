### 解题思路
简单递归一下子
![图片.png](https://pic.leetcode-cn.com/2b24da54fc4a39a096ddb14b949cb12c8afe18715d0e78c07b5de8ec04bd7bee-%E5%9B%BE%E7%89%87.png)


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
    public int maxDepth(Node root) {
       if(root == null) return 0;
       int temp = 0;
      for(Node t : root.children){//应该算是广度优先搜索了
          temp = Math.max(temp , maxDepth(t));
      }
        return temp + 1;
    }
}
```