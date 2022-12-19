### 解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
40.9 MB
, 在所有 Java 提交中击败了
100.00%
的用户

我也不知道为啥结果这么好。
就是遍历root的子节点集合。并且给每一层都创建一个int集合，用一个int标号来表示，第一层就是root本身，为0
然后再添加元素的时候，根据result集合长度跟标号比较来得知此层是否有对应的集合了。
有对应的集合了就直接取出来，没有就新建然后 放进去

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
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root==null){
            return result;
        }
        List<Integer> first = new ArrayList<>();
        first.add(root.val);
        
        result.add(first);
        findOrder(root.children,result,1);


        return result;
    }

    public void findOrder(List<Node> root,List<List<Integer>> result,int n){
        if (root==null || root.size()==0){
            return;
        }


        List<Integer> integers = null;
        if (result.size()>=n+1){
            integers=result.get(n);
        }else {
            integers=new ArrayList<>();
            result.add(integers);
        }

        for (Node node:root){
            integers.add(node.val);
            findOrder(node.children,result,n+1);
        }


    }
}
```