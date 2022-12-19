### 解题思路
一定要注意递归的终止条件啊！！！！！！
气死了，每次都注意不到！！！
还得多练习，才可以啊啊啊啊！！！！！！

### 代码

```java
class Solution {
    //二叉搜索树的特点是，根节点的值小于所有右子树的值
    //大于所有左子树的值；根节点是二叉后序遍历数组中的最后一个数
    public boolean verifyPostorder(int[] postorder) {
        int n = postorder.length;
        return isBack(postorder,0,n-1);
    }

    public boolean isBack(int[] postorder,int start,int end){
        //递归的终止条件啊！！！！！
        if(end-start<1){
            return true;
        }
        int root = postorder[end];
        int midIndex = start;
        for(;midIndex<end;midIndex++){
            if(postorder[midIndex]>root){
                break;
            }
        }
        for(int i=midIndex;i<end;i++){
            if(postorder[i]<root){
                return false;
            }
        }
        return isBack(postorder,start,midIndex-1)&&isBack(postorder,midIndex,end-1);
    }
}
```