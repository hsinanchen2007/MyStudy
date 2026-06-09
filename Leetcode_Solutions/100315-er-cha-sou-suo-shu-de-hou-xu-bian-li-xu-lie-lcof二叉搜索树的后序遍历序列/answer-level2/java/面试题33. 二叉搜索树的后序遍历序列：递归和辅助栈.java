### 解题思路
二查搜索树性质：左子树节点的值都小于根节点的值，右子树的值都大于根节点的值;
后序遍历：左子树|右子树|根节点
并且与根节点相邻的节点，一定是与根节点直接相连的右节点

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        //利用栈空间，二叉搜索树后序遍历的倒序：根节点|右子树|左子树
        //先找到根节点，然后判断postorder数组中根节点左边（左子树）的值是否有大于根节点的，如果有直接返回false;
        //栈是为了保存二叉搜索树以及其子树的根节点
        Stack<Integer> stack = new Stack<>();
        int root = Integer.MAX_VALUE;
        for(int i = postorder.length - 1; i >= 0; i--) {
            if(postorder[i] > root) return false;
            while(!stack.isEmpty() && stack.peek() > postorder[i]){
                root = stack.pop();
            }
            stack.add(postorder[i]);
        }
        return true;
        //return judge(postorder,0,postorder.length-1);
    }

    //递归，利用二查搜索树的性质：左子树|右子树|根节点
    public boolean judge(int[] postorder,int i,int j){
        if(i>=j){
            return true;
        }
        int left=i;
        while(postorder[left]<postorder[j]){
            left++;
        }
        int right=left;
        while(postorder[left]>postorder[j]){
            left++;
        }
        return left==j&&judge(postorder,i,right-1)&&judge(postorder,right,j-1);
    }
}
```