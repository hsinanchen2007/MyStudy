比较典型的DFS回溯问题。

dfs的基本框架：
```
int search(int t)
{
    if(满足输出条件)
    {
        输出解;
    }
    else
    {
        for(int i=1;i<=尝试方法数;i++)
            if(满足进一步搜索条件)
            {
                为进一步搜索所需要的状态打上标记;
                search(t+1);
                恢复到打标记前的状态;//也就是说的{回溯一步}
            }
    }
}
```


这里的答案输出是String类型，所以对于->的插入、删除、StringBuffer的使用是一个小注意点。

```
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result=new ArrayList<>();
        if(root==null){return result;}
        //传入的每一次helper，这里的StringBuffer存的是一个根节点到叶子节点的序列
        binaryTreePathsHelper(root,result,new StringBuffer());
        return result;
    }

 public static void binaryTreePathsHelper(TreeNode root,List<String> result,StringBuffer tmp){
        if(root==null) return;
        //先加入
        tmp.append(root.val);

        //终止条件是左右子节点都空
        if(root.left==null&&root.right==null){
           result.add(new String(tmp));

        }
        else {
            //左边节点不空，遍历左边
            if(root.left!=null){
                tmp.append("->");
                binaryTreePathsHelper(root.left,result,tmp);
                //回溯
                tmp.delete(tmp.lastIndexOf("->"),tmp.length());
            }
            //右边节点不空，遍历右边
            if(root.right!=null){
                tmp.append("->");
                binaryTreePathsHelper(root.right,result,tmp);
                //回溯
                tmp.delete(tmp.lastIndexOf("->"),tmp.length());
            }

        }
    }
}
```


   