### 层次遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

因为堂兄弟节点必须要在同一深度，因此可以用层次遍历。但是还要保证是不是同一父节点，因此还要判断一下。代码如下：
```
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        ans = [root]
        while ans:
            tmp,n=[],len(ans)
            for i in range(n):
                r=ans.pop(0)
                if r:
                    tmp.append(r.val)
                    ans.append(r.left)
                    ans.append(r.right)
                else:
                    tmp.append(None)        #加一个None,是为了方便判断是否为同一父节点
            if x in tmp and y in tmp:
                l = tmp.index(x)            #获取x的索引位置
                r = tmp.index(y)            #获取y的索引位置
                if l>r:                     #如果l大于r,调换位置，方便判断            
                    l,r = r,l               
                if r-l==1 and r%2 != 0:     #只有l,r相邻并且r为奇数时（l为偶数），才是同一父节点
                    return False
                return True
            if x in tmp or y in tmp:
                return False
        return False
```
