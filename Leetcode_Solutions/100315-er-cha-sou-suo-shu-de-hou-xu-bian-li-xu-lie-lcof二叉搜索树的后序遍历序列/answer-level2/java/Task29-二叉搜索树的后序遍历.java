### 解题思路
题目是二叉搜索树，二叉搜索树指的是树的左节点>右节点。

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return helper(postorder, 0, postorder.length - 1);
        
    }

    public boolean helper(int[] postorder, int start , int end) {
        // 需要是>= 且返回的True，因为start == end， 说明只有一个子节点，一定符合。如果小于，说明没有子节点，也符合，所以要返回true。
        if (start >= end) {
            return true;
        }
        int temp = start;
        while (postorder[temp] < postorder[end]) {
            temp++;
        }
        int middle = temp;

        while (postorder[temp] > postorder[end]) {
            temp++;
        }
        
        return temp == end && helper(postorder, start, middle -1) && helper(postorder, middle, end -1);
        

    }
}
```