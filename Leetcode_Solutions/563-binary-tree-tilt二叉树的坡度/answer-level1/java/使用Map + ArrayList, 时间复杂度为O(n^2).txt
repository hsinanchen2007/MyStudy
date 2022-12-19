### 解题思路
如果我们可以从树叶开始计算子树的节点值的和，在计算上面一层的子树时就可以使用原来的值了。用ArrayList一层一层地存储子节点，每个节点对应一个index，于是可以使用map，将节点和节点子树的sum值建立映射了。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int findTilt(TreeNode root) {
        if( root == null)
            return 0;
        
        Map< Integer, Integer> map = new TreeMap();
        ArrayList< TreeNode> nodeArrayList = new ArrayList();
        nodeArrayList.add( root );
        int i = 0;
        int tilt = 0;
        // 存储子节点
        while( i < nodeArrayList.size() ){
            TreeNode p = nodeArrayList.get( i );
            if( p.left != null )
                nodeArrayList.add( p.left );
            if( p.right != null)
                nodeArrayList.add( p.right );
            i++;
        }
        for( i = i - 1; i >= 0; i--){
            TreeNode p = nodeArrayList.get( i );
            if( p.left == null && p.right == null ){
                map.put( i, p.val);
            }
            else if( p.left == null ){
                map.put( i, p.val + map.get( nodeArrayList.indexOf( p.right) ) );
                tilt += Math.abs( map.get( nodeArrayList.indexOf(p.right) ));
            }
            else if( p.right == null){
                map.put( i, p.val + map.get( nodeArrayList.indexOf(p. left) ) );
                tilt += Math.abs( map.get( nodeArrayList.indexOf(p.left) ));
            }
            else{
                map.put( i, p.val + map.get( nodeArrayList.indexOf(p. left) ) + map.get(nodeArrayList.indexOf( p.right)) );
                tilt += Math.abs( map.get( nodeArrayList.indexOf(p. left) ) - map.get(nodeArrayList.indexOf( p.right)) );
            }
        }
        return tilt;
    }
}
```