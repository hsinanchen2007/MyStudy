详解：https://zhuanlan.zhihu.com/p/85844233
这个题有两种解法，第一种仍是归并，但是要添加索引数组，通过移动索引去归并结果。时间复杂度 nlogn

这里我要说的是通过构建二叉搜索树解决：

首先说一下什么是二叉搜索树：
一个树，他的右节点都大于根节点，左节点都小于等于根节点
对于这道题目，我是通过逐渐构建二叉搜索树来解决问题的。

思想：计算已经形成的二叉搜索树中，找到数值可插入的位置和有多少个节点比当前数值小。

举例子：

[5,2,6,1]
![image.png](https://pic.leetcode-cn.com/83b877635e955498a92ab659e9b855f6d9ca3ee4b835c25ac899fbf819b823a6-image.png)



这里面每个node 都会有一个leftnum去记录它左节点个数。
我们进行插入的时候如果发现当前value> 目前在遍历的root
我们让count+=1+root.leftnum 实际就是这个点代表的节点数量

看一下面的13是如何插入的：
![image.png](https://pic.leetcode-cn.com/e59a9c8f06e0d77be19e453629e575267012a93b6cc56a955bd2f9cc801b2362-image.png)


先找到5 13比5 大 count +=（3+1）
再找到 11 13比11大 count += (1+1)
插入 并返回 count =6

```
public class TreeNode{
        int leftnum;
    
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val=val;
            this.leftnum=0;
            this.left=null;
            this.right=null;
        } 
    }
class Solution {
    public int inseart(TreeNode root,int val){
        int count=0;
        while(true){
            // now value < root inseart left
            if(root.val>=val){
                
                if(root.left==null){
                    root.left=new TreeNode(val);
                    root.left.leftnum=0;
                    root.leftnum+=1;
                    return count;
                }
                root.leftnum+=1;
                root=root.left;
            }else if(root.val<val){
                
                //count += root leftnum+root(1)
                count+=(1+root.leftnum);
                if(root.right==null){
                    root.right=new TreeNode(val);
                    root.right.leftnum=0;
                    return count;
                }
                root=root.right;    
            }     
        }  
    }
    
    
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> fans=new ArrayList<>();
        if(nums.length==0){
            return fans;
        }
        TreeNode root=new TreeNode(nums[nums.length-1]);
        int[] ans=new int[nums.length];
        //inseart node
        for(int i=nums.length-2;i>=0;i--){
            int subans=inseart(root,nums[i]);
            ans[i]=subans;
        }
        for(int i=0;i<ans.length;i++){
            fans.add(ans[i]);
        }
        return fans;
        
    }
}
```
![image.png](https://pic.leetcode-cn.com/9b4aca5b94a6ac0a467fb6006f9ddba8e9b6da37a9a6296fd215b60629ce247d-image.png)



