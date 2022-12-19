### 解题思路
执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 36.8 MB , 在所有 Java 提交中击败了 100.00% 的用户

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return verifyPostorder(postorder,0,postorder.length-1);
    }

    public boolean verifyPostorder(int[] postorder,int start, int end) {
        if(start>=end){
            return true;
        }
        int partIndex = start;
        for(int i=start;i<end;i++){
            if(postorder[i]<postorder[end]){
                //如果不相等，说明小于尾部数子的序列不是连续的，也就是说明 在根节点的右子树存在小于根节点的值，所以不满足条件 false。
                if(i!=partIndex){
                    return false;
                }
                partIndex++;
            }
        }
        return verifyPostorder(postorder,start,partIndex-1) && verifyPostorder(postorder,partIndex,end-1);
    }
}
```