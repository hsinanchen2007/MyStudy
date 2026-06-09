其实就是二叉树先序遍历，把先左后右改成 foreach，只使用一个list来保存结果集

```java
class Solution {
    
    List<Integer> result = new ArrayList<Integer>();
    
    public List<Integer> preorder(Node root) {
        if (root != null) {
            result.add(root.val);
            for (Node node : root.children) {
                preorder(node);
            }
        }
        return result;
    }
    
```

> 执行用时 : 1 ms, 在所有 Java 提交中击败了100.00%的用户
    内存消耗 :46.5 MB, 在所有 Java 提交中击败了97.02% 的用户
