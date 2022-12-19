一开始用StringBuilder来append，debug发现new出来的StringBuilder的hashCode不一样，所以map使用get方法无法判断是否重复（即使stringbuilder里的值一样），故使用String
```
    List<TreeNode> rsList = new ArrayList();
    Map<String, Integer> map = new HashMap();
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        dfsPreOrder(root);
        return rsList;
    }

    public String dfsPreOrder(TreeNode node){
        if(node == null){
            return "#";
        }
        String sb = node.val + "";
        sb += dfsPreOrder(node.left);
        sb += dfsPreOrder(node.right);
        Integer val = map.get(sb);
        if(val == null){
            map.put(sb, 1);
        }else if(val == 1){
            rsList.add(node);
            map.put(sb,++val);
        }
        return sb;
    }
```
