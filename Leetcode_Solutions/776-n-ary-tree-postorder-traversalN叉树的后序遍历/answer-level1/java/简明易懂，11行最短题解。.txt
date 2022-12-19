```java []
class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> res  =  new ArrayList<Integer>();
        if(root == null) return res;
        for(Node cur:root.children){
            res.addAll(postorder(cur));
        }
        res.add(root.val);
        return res;
    }
}
```

