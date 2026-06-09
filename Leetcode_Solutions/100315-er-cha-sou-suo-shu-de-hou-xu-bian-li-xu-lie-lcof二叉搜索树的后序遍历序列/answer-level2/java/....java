### 解题思路
后序遍历，数组最后一个元素为根节点，根据二叉查找树，可以用一个指针将小于根节点的元素部分（左子树）和大于根节点的元素部分（右子树）分开，若每次向下递归分离左右子树时，右子树所有元素都大于根节点，则为后序遍历序列。

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if(postorder.length==0) return true;
        flag = true;
        int parent = postorder[postorder.length-1];
        int lastleft=0;
        for(lastleft=0;lastleft<postorder.length&&parent>postorder[lastleft];lastleft++);
        //left
        dfs(postorder,0,lastleft,true,parent);
        //right
        dfs(postorder,lastleft,postorder.length-1,false,parent);
        return flag;
    }

    private boolean flag = true;

    public void dfs(int[] a,int begin,int end,boolean left,int parent){
        if(begin>=end) return;
        if(!left){
            for(int i=begin;i<end;i++){
                if(a[i]<parent){
                    flag = false;
                }
            }
        }
        parent = a[end-1];
        int lastleft=begin;
        for(lastleft=begin;lastleft<a.length&&parent>a[lastleft];lastleft++);
        //left
        dfs(a,begin,lastleft,true,parent);
        //right
        dfs(a,lastleft,end-1,false,parent);

    }
}
```