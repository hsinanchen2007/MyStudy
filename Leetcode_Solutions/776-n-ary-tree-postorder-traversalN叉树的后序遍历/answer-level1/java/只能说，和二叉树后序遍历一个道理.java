![image.png](https://pic.leetcode-cn.com/0e315b503426706402f49cf003996c06cf2b5268a90300f307119f6dfd1089d5-image.png)

```
    List<Integer> res = new ArrayList<Integer>();
    public List<Integer> postorder(Node root) {
        helper(root);
        return res;
    }
    public void helper(Node root) {
        if(root == null) {
            return;
        }
        int s = root.children.size();
        for(int i = 0; i < s; i++) {
            helper(root.children.get(i));
        }
        res.add(root.val);
    }
```
