感觉自己好强，怎么办？

```java
// n个数，则根节点可能是1->n
// DP求长度是1，一直到长度是n-1的子树的所有可能结构=>作为我们的工具库
    // DP阶段：长度每+1就是一个新阶段
    // DP状态：每阶段下的所有状态，就是该长度所有可能的BST的根节点
    // 最优子结构：想要推出第n个阶段的所有状态，就需要用到前n-1个阶段的所有状态
    // 无后效性？：用到了前N-1个阶段里所有的根节点，但不用去管这些根节点是怎么得到的

    // 根据根节点的位置，根节点左侧右侧会被划分为两个不同长度的连续数组
    // 左右数组分别是根节点的左右子树，按照DP的结果连接对应长度的子树根节点（左子直连，右子new出新节点后加offset）
    // 将根节点的位置从1一直Loop到n，将所有根节点都放入答案库中，解决问题 

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
    
    HashMap <Integer, ArrayList<TreeNode>> map = new HashMap(); //存1->n-1长度的所有根节点;key是长度，动态数组存长度对应的根节点们
    

    
    public List<TreeNode> generateTrees(int n) {
        
        ArrayList <TreeNode> zeroList = new ArrayList();
        
        if(n==0) return zeroList;
        
        zeroList.add(null);
        map.put(0, zeroList);
        
        for(int i=1;i<=n;i++){
            ArrayList <TreeNode> curList = new ArrayList();//这个动态数组是用来存长度为i的数列的所有可能BST的根节点的
            for(int j=1;j<=i;j++){
                //首先我们要知道一共要new多少次根节点（左子根节点数*右子根节点数）
                ArrayList <TreeNode> leftList = map.get(j-1);
                ArrayList <TreeNode> rightList = map.get(i-j);
                int leftNum = leftList.size();
                int rightNum = rightList.size();
                for(int leftRootIndex = 0;leftRootIndex<=leftNum-1;leftRootIndex++){
                    for(int rightRootIndex = 0;rightRootIndex<=rightNum-1;rightRootIndex++){
                        //先new出一个总根节点
                        TreeNode root = new TreeNode(j);
                        //对于根节点位于j，总长度为i的数组，从哈希表中按长度取出根节点，作为左右子接在根节点上
                        //左子可以直接接，因为各节点的值完全相同   
                        root.left = leftList.get(leftRootIndex);
                        //右子要new完了加offset才能接，因为节点值不同
                        root.right = niu(rightList.get(rightRootIndex),j);
                        //最后把这个宝贝根节点塞进动态数组中
                        curList.add(root);
                    }
                }  
            }
            
            //最后把这个宝贝动态数组put进哈希表中，并配一个值为目前队列长度的key
            map.put(i,curList); 
        }
        return map.get(n);
    }
    
    //niu是个递归（回溯）遍历二叉树的小方法
    private TreeNode niu(TreeNode root,int offset){
        if(root==null) return null;
        
        //把本节点new了,并且给节点值加上offset
        TreeNode thisNode = new TreeNode(root.val+offset);
        
        for(int i=0;i<=1;i++){
            //i=0 遍历左子
            if(i==0){
                thisNode.left = niu(root.left,offset);
            }
            //i=1 遍历右子
            else{
                thisNode.right = niu(root.right,offset);
            }
        }
        
        return thisNode;
    }
}
```