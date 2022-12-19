### 解题思路
还是要深入理解回朔的解法，首先回朔的的递归可能是没有统一的return出口的，因为如果成功，执行到底即可。
然后只要将进入回朔步骤的路径进行撤销，就可以继续进行操作。

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
    List<List<Integer>> result = new ArrayList(); 
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root==null){
            return result;
        }
        backTrack(root,0,new ArrayList(),sum);
        return result;
    }

    public void backTrack(TreeNode root,int count,List<Integer> temp,int sum){
        count = count+root.val;
        temp.add(root.val);
        if(count==sum && root.left==null && root.right==null) {
            //这里必须是要new一个新的list，是因为temp对象是一个引用，所有操作增加和删除只针对这个temp对象，
            //如果不用一个新的list来保存结果，那最后temp里存的只是经过增加和删除操作后的东西，最终每个数组
            //里只有根节点5.
            result.add(new ArrayList(temp));
        }
        if(root.left!=null){
            backTrack(root.left,count,temp,sum);
            temp.remove(temp.size()-1);
        }
        if(root.right!=null){
            backTrack(root.right,count,temp,sum);
            temp.remove(temp.size()-1);
        }
    } 
}
```