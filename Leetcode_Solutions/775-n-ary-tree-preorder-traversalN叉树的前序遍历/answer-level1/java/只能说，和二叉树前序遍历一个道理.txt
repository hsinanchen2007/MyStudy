![image.png](https://pic.leetcode-cn.com/373d17090d10f4480b5d0f88b13004c0638f5f434b3d2c595bc85a96d4cd4912-image.png)

```
    List<Integer> res = new ArrayList<Integer>();
    public List<Integer> preorder(Node root) {
        inOrder(root);
        return res;
    }
    public void inOrder(Node root) {
        if(root == null) {
            return;
        }
        res.add(root.val);
        int s = root.children.size();
        for(int i = 0; i < s; i++) {
            inOrder(root.children.get(i));
        }
    }
```
