### 解题思路

通过深度搜索遍历每层的节点数据，但需要知道节点所在的层 n,通过 n，可取出应存在的 list 并赋值。

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
    //递归从上到下遍历节点，并将对应层节点存储在一起
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
         if(root == null){
            return new ArrayList();
        }
        List<List<Integer>> nodeList = new ArrayList(10);

        levelOrderBottom2(root,0,nodeList);
    
        List<List<Integer>> result = new ArrayList(nodeList.size());
        for (int i = nodeList.size() - 1; i >= 0 ; i--) {
            List<Integer> list = nodeList.get(i);
            if (list == null || list.size() == 0 ) {
                continue;
            }
            result.add(list);
        }
        return result;
    }

    public void levelOrderBottom2(TreeNode node,int n,List<List<Integer>> nodeList){
        if(node == null){
            return;
        }

        nodeList.add(new ArrayList<>());
        List<Integer> rootLevel = getOrDefault(nodeList,n);
        rootLevel.add(node.val);

        levelOrderBottom2(node.left,n+1,nodeList);
        levelOrderBottom2(node.right,n+1,nodeList);
       
    }

    public List<Integer> getOrDefault(List<List<Integer>> nodeList,int i){
        List<Integer> levelList = nodeList.get(i);
        if(levelList == null){
            levelList = new ArrayList();
            nodeList.set(i,levelList);
        }
        return levelList;
    }
}
```