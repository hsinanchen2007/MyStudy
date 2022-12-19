### 解题思路
层次遍历树

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
    public int maxLevelSum(TreeNode root) {
        // 存储当前层的节点
        LinkedList<TreeNode> currentLevel=new LinkedList<>();
        // 存储每层的数据
        Map<Integer,Integer> map=new LinkedHashMap<>();
        // 存储下一层的节点
        LinkedList<TreeNode> store=new LinkedList<>();
        currentLevel.add(root);
        int level=1;
        while(!currentLevel.isEmpty()){
            int currentCount=0;
            while(!currentLevel.isEmpty()){
                TreeNode removeNode=currentLevel.remove();
                currentCount+=removeNode.val;
                store.add(removeNode.left);
                store.add(removeNode.right);
            }
            map.put(level,currentCount);
            level++;
            while(!store.isEmpty()){
                TreeNode removeNode=store.remove();
                if(removeNode==null){
                    continue;
                }
                currentLevel.add(removeNode);
            }
        }
        Iterator<Map.Entry<Integer,Integer>> iterator=map.entrySet().iterator();
        int maxValue=Integer.MIN_VALUE;
        int maxIndex=0;
        while(iterator.hasNext()){
            Map.Entry<Integer,Integer> entry=iterator.next();
            if(maxValue<entry.getValue()){
                maxIndex=entry.getKey();
                maxValue=entry.getValue();
            }
        }
        return maxIndex;
        
    }
}
```