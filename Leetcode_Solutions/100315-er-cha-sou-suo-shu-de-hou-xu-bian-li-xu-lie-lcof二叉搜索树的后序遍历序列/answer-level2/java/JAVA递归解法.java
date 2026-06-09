### 解题思路
后序遍历最后一个一定是root结点，根据root结点找到左子树和右子树，递归遍历左子树和右子树，注意边界条件即可。

### 代码

```java
class Solution {
    public static boolean verifyPostorder(int[] postorder) {
        if(postorder == null)
            return false;
        int len = postorder.length;
        if(len <= 1)
            return true;
        return dfs(postorder, 0, len-1);
    }

    static boolean dfs(int[] postorder, int start, int end){
        if(start>end)
            return false;

        int root = postorder[end];

        int i=start;
        for(;i<end;i++){
            if(postorder[i]>root)
                break;
        }

        int j=i;
        for(;j<end;j++){
            if(postorder[j]<root)
                return false;
        }

        boolean left = true;
        if(i>start)
            left = dfs(postorder,start,i-1);
        boolean right = true;
        if(i<end)
            right = dfs(postorder,i,end-1);

        return (left&&right);
    }
}
```