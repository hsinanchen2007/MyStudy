### 解题思路
执行用时 :
213 ms
, 在所有 java 提交中击败了
16.73%
的用户
内存消耗 :
239.7 MB
, 在所有 java 提交中击败了
5.10%
的用户

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
    public boolean isSymmetric(TreeNode root) {
          if(root==null){
            return true;
        }
        boolean res=true;
        Queue<TreeNode> node_queue=new LinkedList<TreeNode>();//使用队列
        node_queue.offer(root.left);//队列插入
        node_queue.offer(root.right);
        boolean all_null=true;
        while(true){
            all_null=true;
            ArrayList<TreeNode> node_arr=new ArrayList<>();
            int queue_size=node_queue.size();
            for(int i=0;i<queue_size;i++){
                TreeNode temp=node_queue.poll();
                node_arr.add(temp);
                node_queue.offer(temp==null?null:temp.left);
                node_queue.offer(temp==null?null:temp.right);
            }
            for(int i=0;i<node_arr.size();i++){//判断该层节点是否构成回文
                if(node_arr.get(i)==null&&node_arr.get(node_arr.size()-1-i)==null){

                }else if(node_arr.get(i)==null&&node_arr.get(node_arr.size()-1-i)!=null){
                    return false;
                }else if(node_arr.get(i)!=null&&node_arr.get(node_arr.size()-1-i)==null){
                    return false;
                }else{
                    if(node_arr.get(i).val!=node_arr.get(node_arr.size()-1-i).val){
                        return false;
                    }else{

                    }
                }

            }
            Object [] arry_node=node_queue.toArray();

            for(int i=0;i<node_queue.size();i++){
                if(arry_node[i]!=null){
                    all_null=false;
                    break;
                }
            }
            if(all_null==true){
                break;
            }



        }


        return true;
        
    }
}
```