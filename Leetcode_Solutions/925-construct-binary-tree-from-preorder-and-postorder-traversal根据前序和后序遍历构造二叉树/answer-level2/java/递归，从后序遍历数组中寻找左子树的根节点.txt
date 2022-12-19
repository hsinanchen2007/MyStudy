### 解题思路
前序遍历是root->left->right，后序遍历的**逆向**是root->right->left。

前序遍历的第一个元素和后序遍历的最后一个元素总是相同，这个就是树的root节点。

我们可以默认**前序遍历下标为1**的节点，是**左子树的root**(下标为0的是整个树的root节点)。

那么只要逆向遍历后序数组，找到与pre[1]值相同的元素，就是在后序遍历中，找到了左子树的root节点(题目条件，数组没有重复元素），记为leftRootIndex。

那么**后序遍历的[0,leftRootIndex]**的全部元素，就都是**左子树**的节点。**前序遍历从[1,leftRootIndex+1]**的全部元素，也都是**左子树**的节点。

同理，pre和post中剩下的，就都是右子树的节点(除去确定的根节点)。

### 核心代码
```
int postLeft = 1;
for (int i = length - 1 ; i >= 0;i--){
    // 寻找后序遍历的左子树节点，前序的index为1的节点就是左子树的root，只要在后序遍历中找到相同的，从0->i就都是左子树
    if (pre[1] == post[i]){
            postLeft = i + 1;// 这个节点往前的（不包括postLeft，i才是真正的leftRootIndex），都是后序遍历的左子树
            break;
        }
    }
}
```


### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        // pre和post的长度总是相等的，
        if (pre.length == 0){
            return null;
        }
        if (pre.length == 1){
            return new TreeNode(pre[0]);
        }
        // 正向先序root->left->right，逆向后序root->right->left
        // pre的第一个，总是和post的最后一个相等
        int length = pre.length;
        TreeNode root = new TreeNode(pre[0]);
        // left的分隔点
        int postLeft = 1;
        for (int i = length - 1 ; i >= 0;i--){
            // 寻找后序遍历的左子树节点，前序的index为1的节点就是左子树的root，只要在后序遍历中找到相同的，从0->i就都是左子树
            if (pre[1] == post[i]){
                postLeft = i + 1;// 这个节点往前的（不包括postLeft，i才是真正的leftRootIndex），都是后序遍历的左子树
                break;
            }
        }
        // 左子树的前序遍历数组，前闭后开区间
        int[] leftPre = Arrays.copyOfRange(pre,1,1 + postLeft);
        // 左子树的后序遍历数组，前闭后开区间
        int[] leftPost = Arrays.copyOfRange(post,0,postLeft);
        // 递归构造左子树
        root.left = constructFromPrePost(leftPre,leftPost);

        // 右子树的前序遍历数组，前闭后开区间
        int[] rightPre = Arrays.copyOfRange(pre,1 + postLeft,length);
        // 右子树的后序遍历数组，前闭后开区间
        int[] rightPost = Arrays.copyOfRange(post,postLeft,length - 1);
        // 递归构造右子树
        root.right = constructFromPrePost(rightPre,rightPost);
        return root;
    }
}
```