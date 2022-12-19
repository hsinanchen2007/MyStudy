![image.png](https://pic.leetcode-cn.com/c6eb745c731ca03edb6c051a55a340703fd97be1b57ce82728f97f8d316e068b-image.png)

```
    public int maxDepth(Node root) {
        if(root == null) {
            return 0;
        }
        int m = 0;
        for(Node i : root.children) {
            m = Math.max(maxDepth(i), m);
        }
        return m + 1;
    }
```
