简单的迭代
1.如果当前结点为null，直接返回list
2.如果当前结点的children为null，list.add(root.val),返回list
3.遍历当前结点的children中的每个结点，进行迭代操作，然后list.add(root.val)


class Solution {
    List<Integer> list2 = new ArrayList<>();

    public List<Integer> postorder(Node root) {
        if (root == null) {
            return list2;
        }
        if (root.children == null) {
            list2.add(root.val);
            return list2;
        }
        for (Node node:root.children){
            postorder(node);
        }
        list2.add(root.val);
        return list2;
    }
}