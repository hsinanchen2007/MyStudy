### 解题思路
此处撰写解题思路
当根==null时，**此时应该产生一个空的List<>，而不是NULL**，否则将root的值添加到成变量中。
然后遍历孩子节点。
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    private List<Integer> res=new ArrayList<>();
    public List<Integer> preorder(Node root) { 
        if( root ==null) return new ArrayList<Integer>();
        res.add(root.val);
        for(Node child:root.children){
            if(child!=null) preorder(child);//为了剪枝。
        }
        return res;
        
    }
}
```
**`不`加`if(child!=null)`**
![Snipaste_2020-03-18_23-34-13.jpg](https://pic.leetcode-cn.com/6948cd69f6e871d39204d9dca6708eb57a8f171dfdc1146c26396a6b7cf426dc-Snipaste_2020-03-18_23-34-13.jpg)
**添加`if(child!=null)`**
![Snipaste_2020-03-18_23-34-38.jpg](https://pic.leetcode-cn.com/55d60ea8565eabd5260f88bafb98cd79275566cbe0b1ea8d7f11d45595106a3d-Snipaste_2020-03-18_23-34-38.jpg)
