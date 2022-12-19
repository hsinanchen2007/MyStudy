### 解题思路
![WechatIMG4.jpeg](https://pic.leetcode-cn.com/5f0d02d057955f681bca8c589478e2787178c7039d69601ef5c89fecfef283a5-WechatIMG4.jpeg)


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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList();
        dfs(root,new LinkedList(),0,result,sum);
        return result;
    }

    public void dfs(TreeNode root,LinkedList<TreeNode> stack,int stackSum,List<List<Integer>> result,int sum){
        if(root == null){
            return;
        }
        if(root.left == null && root.right==null){
            if((stackSum+root.val)==sum){
                //将stack与root变为list加入到list结果中
                List<Integer> tmpList = new ArrayList();
                Iterator<TreeNode> iterator = stack.descendingIterator();
                while(iterator.hasNext()){
                    tmpList.add(iterator.next().val);
                }
                tmpList.add(root.val);
                result.add(tmpList);
            }
        }else{
            stack.push(root);
            if(root.left!=null){
                dfs(root.left,stack,stackSum+root.val,result,sum);
            }
            if(root.right!=null){
                dfs(root.right,stack,stackSum+root.val,result,sum);
            }
            stack.pop();
            
        }
    }
}
```