![422A2B151D338A622C8FCCA478F43160.png](https://pic.leetcode-cn.com/11a2e46c1e8df80eea391c729be8b03a3feed2a2150611b8d6b4f8672fd6fc48-422A2B151D338A622C8FCCA478F43160.png)```


```
class Solution {
    static List<Integer> list = new ArrayList<>();
    //因为 list 是静态的，所以在下一次使用前要把 list 清空。
    {
        list.clear();
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        //当 root 为空时，直接返回。
        if (root == null) {
            return new ArrayList<>();
        }
        int ret = root.val;
        list.add(ret);
        preorderTraversal(root.left);
        preorderTraversal(root.right);
        return list;
    }
}
```

