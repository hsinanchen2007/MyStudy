![image.png](https://pic.leetcode-cn.com/c682b38c9e7bed221b6dc6d010e826f3caccbc065027b62b55f0e4fad758eab9-image.png)

推荐不适用额外的空间，我没做到，觉得会浪费很多时间

```
    int maxTimes = 0;
    int thisTimes = 0;
    List<Integer> res = new LinkedList<Integer>();
    TreeNode pre = null;
    public int[] findMode(TreeNode root) {
        inOrder(root);
        int length = res.size();
        int[] rr = new int[length];
        for(int i = 0; i < length; i++) {
            rr[i] = res.get(i);
        } 
        return rr;
    }
    public void inOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        inOrder(root.left);
        if(pre != null && pre.val == root.val) {
            thisTimes++;
        } else {
            thisTimes = 1;
        }
        if(thisTimes == maxTimes) {
            res.add(root.val);
        } else if(thisTimes > maxTimes) {
            maxTimes = thisTimes;
            res.clear();
            res.add(root.val);
        }
        pre = root;
        inOrder(root.right);
    }
```
