### 解题思路
核心： left < root < right

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        int size = postorder.length;
        if(size == 0 || size == 1 || size == 2)
            return true;
        return check(0, size - 1, postorder);
    }
    public boolean check(int start, int end, int[] postorder){
        if(start >= end)
            return true;
        int i;
        for(i = start; i < end; i++){
            if(postorder[i] > postorder[end])
                break;
        }
        for(int j = i; j < end; j++)
            if(postorder[j] < postorder[end])
                return false;
        return check(start, i - 1, postorder) && check(i, end - 1, postorder);
    }
}
```