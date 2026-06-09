### 解题思路
找寻右子树

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if(postorder == null || postorder.length == 0) return true;
        //右子树开始的位置
        int start = 0;
        int length = postorder.length;
        for(int i = 0;i < length - 1;i++){
            //跟根节点进行比较
            if(postorder[i] < postorder[length - 1])
                start++;
        }
        for(int i = start;i < length - 1;i++){
            if(postorder[i] <= postorder[length - 1]){
                return false;
            } 
        }
        return verifyPostorder(Arrays.copyOfRange(postorder,0,start)) &&
        verifyPostorder(Arrays.copyOfRange(postorder,start,length - 1));
        
    }

}
```