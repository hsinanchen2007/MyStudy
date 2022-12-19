主要思路：以树上的每一个节点作为根节点，然后向每一条路径下累加，若等于目标数值，计数加一。

创建两个函数，helper1用来遍历树上的每一个节点，每一个节点都调用一次helper2，helper2则进行对以当前节点作为根节点的树的所有路径进行累加。
![image.png](https://pic.leetcode-cn.com/93efbed9f8093371f0aef029dd8d29758c23dc6e9d938a2ffbeb8aaf66faab48-image.png)

首先以10为根节点，向下遍历所有路径，在对应的路径累加

![image.png](https://pic.leetcode-cn.com/86e0e7b598a318bc0f6a7e34f5e9edd0680f2e8c01cddb87007cbe456e2b8bbd-image.png)
第一条路径累加完，发现没有目标值，此时需要返回上一节点，所以需要舍弃当前节点的值，所以会有temp-=root.val,然后遍历右节点
![image.png](https://pic.leetcode-cn.com/8b892825cd5fab1318b15c787992c0b425a34d7d87108b7c01f5ce88b6fdeec0-image.png)
没有，节点接着上移，遍历右节点
![image.png](https://pic.leetcode-cn.com/48932935b31b319d0fe9797eebe0a2126c97fbbf4eb52a244c097195084fc2c2-image.png)
发现最后两个节点能和根节点组成10->-3->1，计数器累加，这样一个节点作为根节点的遍历完成，之后再以每一个节点作为根节点，遍历这颗以此节点作为根节点的树，重复上面的操作，即可找到所有满足要求的路径总和。

再以下一个节点为根节点演示一下：
![image.png](https://pic.leetcode-cn.com/bbb598b1f796b9c37aef14e681e46ac6c6a9da06a5afb9fa51b5bf4997d5d76b-image.png)
只管以5作为根节点的树，其他不管
![image.png](https://pic.leetcode-cn.com/3b9e11834793f3bf7512489bbdae0ac72ca53aaa5650c14f1cb9ffd6501205cd-image.png)
5->3,满足条件，res++
![image.png](https://pic.leetcode-cn.com/9f1ba76ce87329eb7568900cf092db9426971a5528e946522d584a40073bba5a-image.png)
5->2->1，满足条件，res++。
至此，以第二个节点为根节点的子树遍历也完成了





```
class Solution {
    int res=0,temp=0;
    public void helper1(TreeNode root,int sum){
        if(root==null)return;
        helper2(root,sum);//每个节点都作为根节点调用helper2
        helper1(root.left,sum);
        helper1(root.right,sum);
    }
    public void helper2(TreeNode root,int sum){
        if(root==null)return;
        temp+=root.val;//对当前路径上的树累加
        if(temp==sum)//遇到目标值，计数器累加
            res++;
        helper2(root.left,sum);//遍历左子树
        helper2(root.right,sum);//遍历右子树
        temp-=root.val;//当前节点的左右子树遍历完，需要减去当前节点值，计算其他路径

    }
    public int pathSum(TreeNode root, int sum) {
        helper1(root,sum);
        return res;
    }
}
```
