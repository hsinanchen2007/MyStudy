![image.png](https://pic.leetcode-cn.com/25d35bbd6d52534e32397df96695ab2414495b559e4d141af314a6daed9ce0ac-image.png)


遍历字符串，遍历过程中可以通过对数字字符的累加以及'-'的计数来获得数值val及对应深度dep，即得即用无需长期存储。

然后直接加入或覆盖键key为深度dep的树字典，字典的值value就是以val为值的树指针。

且由先序遍历的特性可以知道，上一个遍历到的比自己深度浅1的节点必为自己的父节点，所以直接把当前节点加到这父节点下便可以把树连接起来了。

最后返回字典里面深度为0的那值便是所求的树指针。

```python []
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        ans = {-1: TreeNode(0)}     #字典初始化
        def addTree(v, p):          #添加树函数
            ans[p] = TreeNode(int(v))
            if not ans[p - 1].left: #左子树不存在就加在左边
                ans[p - 1].left = ans[p]
            else:                   #反之加在右边
                ans[p - 1].right = ans[p]
        val, dep = '', 0            #值和对应深度初始化
        for c in S:
            if c != '-':
                val += c            #累加字符来获得数字
            elif val:               #如果是‘-’且存在val
                addTree(val, dep)   #就把累加好的数字和对应深度添加进树
                val, dep = '', 1    #值和对应深度重新初始化
            else:
                dep += 1            #连续的‘-’只加深度不加值
        addTree(val, dep)           #末尾剩余的数字也要加进树
        return ans[0]
```

样例的字典变化如下：

```py
"1-2--3--4-5--6--7"
【插入值/深度/树字典】
1 0 {-1: 0, 0: 1}
2 1 {-1: 0, 0: 1, 1: 2}
3 2 {-1: 0, 0: 1, 1: 2, 2: 3}
4 2 {-1: 0, 0: 1, 1: 2, 2: 4}
5 1 {-1: 0, 0: 1, 1: 5, 2: 4}
6 2 {-1: 0, 0: 1, 1: 5, 2: 6}
7 2 {-1: 0, 0: 1, 1: 5, 2: 7}
```
