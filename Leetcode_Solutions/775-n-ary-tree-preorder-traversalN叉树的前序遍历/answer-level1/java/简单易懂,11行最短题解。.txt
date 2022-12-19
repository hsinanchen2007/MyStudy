```java []
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> res  =  new ArrayList<Integer>();
        if(root == null) return res;
        res.add(root.val);
        for(Node cur:root.children){
            res.addAll(preorder(cur));
        }
        return res;
    }
}