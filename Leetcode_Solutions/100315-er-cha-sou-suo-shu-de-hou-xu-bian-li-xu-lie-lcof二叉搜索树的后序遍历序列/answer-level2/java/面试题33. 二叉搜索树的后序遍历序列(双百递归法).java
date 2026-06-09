### 解题思路
主要使用了分左右子树递归的思想。先找到规律，每个数组最后一个元素是根节点，左子树都小于根节点，右子树都大于根节点，于是两个子树分成两个数组，将两个数组继续递归求是否是BST，最后返回boolean，详细看注释

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        int l=postorder.length;
        return isBST(postorder,l);
    }
    boolean isBST(int[] p,int l){//l是长度
        if(p==null||l<=0)return true;//空返回true，用例子跑出来的，本来按理解是false，不知道为啥要求true
        int root=p[l-1];//最后一个节点是根节点
        int i=0;
        for(;i<l-1;i++){
            if(p[i]>root)break;//只要发现右子树出现就跳出循环，此时i指的是右子树
        }
        int j=i;
        for(;j<l-1;j++){//只要发现右子树中有小于根节点的就返回false
            if(p[j]<root)return false;
        }
        boolean left=true;//为空也返回true
        if(i>0)left=isBST(p,i);//对左子树递归求是否二叉搜索树，此时根据长度取数组就是到p[i-1]为止
        boolean right=true;
        if(i<l-1){//右子树麻烦是因为要求右子树的数组
            int k=i;
            int index=0;
            int[] right1=new int[l-1-i];
            for(;k<l-1;k++){//求右子树数组
                right1[index]=p[k];
                index++;
            }
            right=isBST(right1,l-1-i);
        }
        return right&&left;
    }
}
```