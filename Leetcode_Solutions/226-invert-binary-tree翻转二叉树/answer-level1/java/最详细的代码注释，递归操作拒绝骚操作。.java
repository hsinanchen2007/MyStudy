### 要点
比对一下题目这两个代码图片。如果按每一层来看的话，就是把结点的左右两侧子树进行交换
第二层交换
```
     4
   /   \
  7     2
 / \   / \
6   9 1   3
```
第三层交换
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```
### 递归
翻转的流程由上到下,而你要做的就是告诉计算机交换哪些节点
对于 **4** 而言，需要交换 **7，2**，

这么理解
 **4** 告诉 **7，2** 你们需要交换自己的位置。
 **7** 告诉 **9，6** 你们需要交换自己的位置。
 
 那么就是每到达一个根结点，你都应该通知它的左右两边进行交换。
 **如：**
 ```root:  root.left <> root.right```
 ```root.left:  root.left.left <> root.left.right```
#### 代码片段
```java
public TreeNode invertTree(TreeNode root) {
      if(root==null){//0.终止条件直接返回
          return null;
      }
      TreeNode tmp = root.left;//1.交换节点
      root.left = root.right;
      root.right = tmp;
      
      invertTree(root.left);//2.让左子树内部交换节点
      invertTree(root.right);//3.让左子树内部交换节点
      return root;//4.返回修改之后的节点
  }
```
---
## 结尾 
##### <u>[1.博客地址](https://blog.csdn.net/weixin_42322309)</u>
##### <u>[2.源代码仓库](https://gitee.com/Gre-Z/Algorithm")</u>
> 如果你在代码里看到了用 数字标记的注释 如 //1.xxx 这是我写代码的顺序，希望能给你一点启发。