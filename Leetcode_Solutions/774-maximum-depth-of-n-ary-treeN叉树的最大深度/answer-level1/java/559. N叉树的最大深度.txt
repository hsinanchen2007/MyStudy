
/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/24
 *
 * 多叉树的深度遍历
 *
 */

```
 public int maxDepth(Node root) {
    if(root == null) return 0;
    int max = 0;
    for(int i =0;i< root.children.size();i++){
        max = Math.max(maxDepth(root.children.get(i)),max);
    }
    return max + 1;
}
```