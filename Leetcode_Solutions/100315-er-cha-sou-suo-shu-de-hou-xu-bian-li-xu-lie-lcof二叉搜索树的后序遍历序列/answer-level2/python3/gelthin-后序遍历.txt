### 解题思路
连错两回后，终于自己写出来了。
+ 如果是一个后续遍历，那么必然存在 ind 使得， postorder[1...ind]< postorder[-1] < postorder[ind+1,...,-2] 
+ 当从左往右遍历找第一个大于 postorder[-1] 的元素记录下标 i,令 ind=i-1, 还需要 check 剩下的元素都满足不小于 postorder[-1]
+ 然后递归地对左子树、右子树进行操作确定。
+ 注意递归返回条件，left == right 或者 left > right 都要返回

这个题解比我的好很多。[面试题33. 二叉搜索树的后序遍历序列（递归分治 / 单调栈，清晰图解）](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/)
+ 同时从左到右，搜第一个 > pivot 的值的下标，从右到左搜第一个小于 pivot 值的下标
+ 如果不是相隔一个，则直接返回 False
+ 如果是， 再接着递归，左子树，右子树。

#### 单调栈的思路非常强


### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        def helper(posterorder, left, right): # 考虑闭区间 [left, right]
            if left>=right:  # 无节点或者仅仅一个节点
                return True
            pivot = posterorder[right]
            ind = right-1  ## 如果没有找到，说明没有右子树 # 若没有左子树， 则 ind = left-1, 也对
            for i in range(left, right):  # range 函数不包括 right
                if posterorder[i]>pivot:
                    ind = i-1
                    break
            # ind = i-1 这里不可调用 i 变量
            ## 但还要判读一下，是否 ind+1 后面的元素也都大于 pivot。 例如，特例 [7,4,6,5] 出错
            for i in range(ind+2, right):
                if posterorder[i]<pivot:
                    return False
            return helper(posterorder,left,ind) and helper(posterorder,ind+1,right-1)
        return helper(postorder, 0, len(postorder)-1)
            
```