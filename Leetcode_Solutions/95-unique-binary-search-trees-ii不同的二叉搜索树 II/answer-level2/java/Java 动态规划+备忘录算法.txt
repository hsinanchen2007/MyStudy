### 解题思路
//先判断边界条件  n=0的情况,这时候返回空列表
首先建立一个帮助函数和空节点
TreeNode emptyNode = new TreeNode(-1);
//定义from到end所能组成的二叉树列表
//定义一个map，用于存放从from-end的结果,避免重复计算
List<TreeNode> generateHelp(int from,int end){
        if(from == end){
                return Arrays.asList(new TreeNode(from));
                //放入到map中
        }else if(from>end){
             //返回null
            //注意 由于java中List不允许放入null,所以我们利用一个空节点来代替null
         }else if(end-from ==1){
                 //如果end只比from大
                  //那么返回两个树
                 //第一个树  根节点是end,左节点是from
                //第二个树   根节点是from,右节点是end
             
          }else{
                     for(int i=from;i<=end;i++){
                                //以i为根节点,左边组成一个子树,右边组成一个子树
                               List<TreeNode> leftNodeList = generateHelp(1,i-1);
                               List<TreeNode> leftNodeList = generateHelp(i+1,end);
                                for(TreeNode treeNode:leftNodeList){
                                        for(TreeNode rightNode:rightNodeList){
                                                    TreeNode root = new TreeNode(i);
                                                    //注意这里需要判空 当leftNode或者rightNode为emptyNode的时候,就设置为null
                                                    root.left = leftNode;  
                                                    root.right = rightNode; 
                                                   //把result添加到结果列表  
                                        }
                               }
                     }
         } 
}

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

    Map<String,List<TreeNode>> map = new HashMap<>();
    TreeNode emptyNode = new TreeNode(-1);

    private List<TreeNode> generateTreesHelp(int from,int end){
        if(map.get(from+"-"+end)!=null){
            return map.get(from+"-"+end);
        }
        if(from > end){
            List<TreeNode> treeNodeList = Arrays.asList(emptyNode);
            map.put((from+"-"+end),treeNodeList);
            return treeNodeList;
        }else if(from==end){
            List<TreeNode> treeNodeList = Arrays.asList(new TreeNode(from));
            map.put((from+"-"+end),treeNodeList);
            return treeNodeList;
        }else if(end-from ==1 ){
            TreeNode node1 = new TreeNode(end);
            node1.left = new TreeNode(from);
            TreeNode node2 = new TreeNode(from);
            node2.right = new TreeNode(end);
            List<TreeNode> treeNodeList = Arrays.asList(node1, node2);
            map.put((from+"-"+end),treeNodeList);
            return treeNodeList;
        }else{
            List<TreeNode> result = new ArrayList<>();
            for(int i = from;i<=end;i++){
                List<TreeNode> leftList = generateTreesHelp(from,i-1);
                List<TreeNode> rightList = generateTreesHelp(i+1,end);
                for(TreeNode leftNode:leftList){
                    for(TreeNode rightNode:rightList){
                        //以i为根节点
                        TreeNode root = new TreeNode(i);
                        root.left = leftNode==emptyNode?null:leftNode;
                        root.right = rightNode==emptyNode?null:rightNode;
                        result.add(root);
                    }
                }
            }
            map.put(from+"-"+end,result);
            return result;
        }
    }

    public List<TreeNode> generateTrees(int n) {
        if(n==0){
            return new ArrayList<>();
        }

       List<TreeNode> list = generateTreesHelp(1,n);
       return list;
    }
}
```