**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 * 
 * 解题思路: 把节点全部存到 hashset 中 然后进行遍历判断
 * 
 */
```
class Solution {
    HashSet<Integer> hashSet = new HashSet<>();
    public boolean findTarget(TreeNode root, int k) {
        PrePost(root);

        for(int key:hashSet){
            if(hashSet.contains(k - key) && k - key != key){
                return true;
            }
        }
        return false;

    }

    public void PrePost(TreeNode root){
        if(root == null) return;
        hashSet.add(root.val);
        PrePost(root.left);
        PrePost(root.right);
    }
}
```