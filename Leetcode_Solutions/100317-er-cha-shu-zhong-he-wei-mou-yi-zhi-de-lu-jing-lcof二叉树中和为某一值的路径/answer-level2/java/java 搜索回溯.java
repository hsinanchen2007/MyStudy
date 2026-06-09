![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/642b46e4fe7fda6d1f0a1ec1a443d0d7c5a1aae5324ab31a6ad74d7e012699fc-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
//搜索回溯方法
class Solution {
    List<List<Integer>> res;

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        res = new LinkedList<>();
        List<Integer> trace = new LinkedList();
        if(root == null) return res;
        search(root, sum, trace);
        return res;
    }

    public void search(TreeNode node, int target, List<Integer> trace) {
        trace.add(node.val);
        //根节点
        if (node.left == null && node.right == null && target == node.val) 
            res.add(new LinkedList<Integer>(trace));
        //不是根节点
        if (node.left != null) search(node.left, target - node.val, trace);
        if (node.right != null) search(node.right, target - node.val, trace);
        trace.remove(trace.size() - 1);
    }
}
```