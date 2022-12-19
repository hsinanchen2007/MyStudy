```
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if(root == null)
            return list;
        list.add(root.val);
        for(int i = 0; i < root.children.size(); i++) {
            list.addAll(preorder(root.children.get(i))); //添加list对象
        }
        return list;
        
    }
}
```
