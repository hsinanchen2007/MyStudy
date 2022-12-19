二叉树的前序遍历：
```
if(root == null){
    return list;
}
list.add(root.val);
preorder(root.left);
preorder(root.right);
return list;
```
这里既然是N叉树，那就是把递归改成遍历递归就行了，一样的道理

```
class Solution {
    List<Integer> list = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if(root == null){
            return list;
        }
        list.add(root.val);
        for(Node n : root.children){
            preorder(n);
        }
        return list;
    }
}
```
