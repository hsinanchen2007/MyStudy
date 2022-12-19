### 解题思路
思路前期准备：[不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)

#### 大体的思路是：
分别以1,2,3,...n作为根节点，若以j作为根节点，则1，2，3..j-1 构成左子树，相对的j+1,j+2,j+3...n构成右子树.

#### 方法：
动态规划
dp二维数组，dp[i] 表示整数i能够生成的所有二叉搜索树，dp[i][j]则表示，以j为根节点的二叉搜索树。

根据[不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)的思路，
延续其思路，将二叉搜索树按照其根节点分为两个部分，
对于左子树，则只需要根节点左边指向dp[i-1][j-1]即可，
对于右子树，则不能直接进行简单的右边指向dp[i-1][j+1]，因为此前的dp[i]中并未存放有相应的搜索二叉树；此时就需要自己动手构造。
根据题意以及实例总结可得，对于一个长度i，能够生成不同的搜索二叉树的形式是固定的，即1，2 和 3，4,长度都为2，它们生成不同的搜索二叉树的形式是固定的，只是存放的val有所不同。
那么可以按照此为依据，对右子树进行构造，右边的长度是i-j，于是只需要找到dp[i-j]即可获得全部的二叉搜索树构造形式，而对于其中的val，
我们需要进行更新。更新的依据是j，在原val的基础上进行val+j即可。

#### 代码实现:
##### 问题:
1.涉及到树和指针操作，所以不能直接修改或是复制，特别是在对右子树进行构造的过程中，需要自己动手复制构造一棵新的树，防止原数据被修改；
2.初始化的选择;
3.左右子树的拼接;
##### 解决方法:
1.定义一个函数，进行额外的二叉树构造
```go
func Update(t *TreeNode,offset int) *TreeNode {
    res := new(TreeNode)
    if t == nil {
        return nil
    }
    res.Val = t.Val + offset
    res.Left = Update(t.Left,offset)
    res.Right = Update(t.Right,offset)
    return res
}
```
2.初始化的条件:
```go
 p := new(TreeNode)
    p.Val = 1
    p.Left = nil
    p.Right = nil
    dp[1] = append(dp[1],p)
    p = nil
    dp[0] = append(dp[0],p)
```
3.左右子树的拼接;
```go
for i:=2;i<=n;i++ { //长度
        for j:=1;j<=i;j++ { //根节点的选择
            for _,v1 := range dp[j-1] { //遍历左边
                for _,v2 := range dp[i-j] { //遍历右边
                    //偏移量
                    offset := j
                    //根节点构造
                    root := new(TreeNode)
                    root.Val = j
                    //左子树直接拼接
                    root.Left = v1
                    //右子树更新后进行拼接
                    root.Right = Update(v2,offset)
                    //存储结果
                    dp[i] = append(dp[i],root)
                }
            }
        }
    }
```



### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func generateTrees(n int) []*TreeNode {
    if n == 0 {
        return nil
    }

    dp := make([][]*TreeNode,n+1)

    p := new(TreeNode)
    p.Val = 1
    p.Left = nil
    p.Right = nil
    dp[1] = append(dp[1],p)
    p = nil
    dp[0] = append(dp[0],p)

    for i:=2;i<=n;i++ {
        for j:=1;j<=i;j++ {
            for _,v1 := range dp[j-1] {
                for _,v2 := range dp[i-j] {
                    offset := j
                    root := new(TreeNode)
                    root.Val = j
                    root.Left = v1
                    root.Right = Update(v2,offset)
                    dp[i] = append(dp[i],root)
                }
            }
        }
    }
    return dp[n]
}
func Max(a,b int) int {
    if a<b {
        return b
    }
    return a
}
func Update(t *TreeNode,offset int) *TreeNode {
    res := new(TreeNode)
    if t == nil {
        return nil
    }
    res.Val = t.Val + offset
    res.Left = Update(t.Left,offset)
    res.Right = Update(t.Right,offset)
    return res
}


```