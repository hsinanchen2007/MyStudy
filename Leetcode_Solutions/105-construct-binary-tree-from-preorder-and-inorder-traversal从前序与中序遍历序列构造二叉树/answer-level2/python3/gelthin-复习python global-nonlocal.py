### 解题思路
本题的思路参见官方题解，然后我这里大的改进是参照官方题解评论区的解答，全部用闭区间 [a,b] 更加清晰。

就是需要定义一个变量 pre_idx 来记录每一次 root 节点在 preorder 中的位置。然后这个变量需要在递归调用的函数中同步变大，因为发生了变化所以需要用 nonlocal 标明。如果只是利用值，而不重赋值或者改变值的话，可以直接用，就像官网题解中的         
```python3
idx_map = {val:idx for idx, val in enumerate(inorder)} 
```
idx_map 变量，直接用，不需要申明 global, nonlocal, 也不需要当做形参，可以内部函数直接利用上一层的值，并且递归也可以用。

这里如果不用 nonlocal, 而改用 global 会报错，因为 global 会找真正最外层的全局变量，但是这里是 def buildTree()内部定义的变量不算全局变量。


这里需要再去看一下书籍 《python 语言及其应用》 和 《流畅的 python》
### 这里想探讨一下 python3 语言 global, nonlocal 关键字的用法， 以及内部函数如何自动使用上一级变量

类似，之前在 mixmatch 的 pytorch 实现中碰到的问题：
``` python3
def test(): ## 报错
    print(A) # UnboundLocalError: local variable 'A' referenced before assignment
    A = 1 # 有此语句，则函数会默认 A 为函数内部局部变量，导致错误
A = 2
test()
```

``` python3
def test(): ## 正确
    global A # 加上 global 声明则正确，但下面的语句会直接更改了外部的A。 MixMatch 的写法就是这样
    print(A)
    A = 1
A = 2
test()
```

``` python3
def test():  ## 报错
    A = 1     ## global 关键字声明必须放在对变元的赋值操作之前，否则有了此语句，就认为此变元是局部变元
    global A  #SyntaxError: name 'A' is assigned to before global declaration
A = 2
test()
```

``` python3
def test():  # 函数内部可以使用上一层的变量A，无需形参列表 def test(A) 来传参数
    print(A) # 或者直接注释掉 A 变元的赋值, 然后函数内部 A 就会默认使用外部的 A，
    # A = 1 
A = 2
test()
```

###### global 和 nonlocal 语义是不一样的 [部分更细致的解析参见](https://blog.csdn.net/xcyansun/article/details/79672634)
+ global 声明继承的是全局变量，可以放在任何一个函数的最初的位置，放在最外层也对 
+ nonlocal 只能用在嵌套函数中，是继承上一层函数的局部变量, 上一层必须有局部（非全局）变量，否则会报错。
+ global,nonlocal 在函数递归调用中也能奏效, 能够持续地修改某一个变元
+ global 和 nonlocal 都得放在句首
+ global 和 nonlocal 有时候会冲突，例如 global 在 nonlocal 的上一层
+ 当 global 和 nonlocal 不冲突的时候，例如，nonlocal 在 global 上一层，可以在不同函数的层次同时共存，并起到合适的作用

```python3
def test():
    nonlocal A # SyntaxError: no binding for nonlocal 'A' found
    print(A) # 找不到这个变元 A 应该绑定啥，最外层是全局变量，不可绑定
A = 2
test()
```

```python3
def test():
    global A  # 直接绑定最外层的全局变量
    def inter_test():
        nonlocal A  # SyntaxError: no binding for nonlocal 'A' found
        print(A)    # 必须要绑定上一层的局部变量，但上一层只有一个全局变量
    inter_test()
A = 4
test()
```
```python3
def test():
    A = 5 # 局部变量
    def inter_test():
        nonlocal A  # SyntaxError: no binding for nonlocal 'A' found
        print(A)    # 必须要绑定上一层的局部变量，但上一层只有一个全局变量
        def inter_inter_test():
            global A
            print(A)
        inter_inter_test()
    inter_test()
A = 4
test()


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        ## 这里似乎要求树中没有重复元素，如果有重复元素，会变得很复杂？
        def helper(preorder, inorder, left, right):
            nonlocal pre_idx  ## 应该使用 nonlocal, 如果使用 global 则需要全局 main 函数定义 pre_idx
            if left > right:  ## 使用 闭区间 [left, right] 更清晰
                return None
            # root = TreeNode(preorder[pre_ind]) 错误
            root = TreeNode(preorder[pre_idx])
            index = inorder.index(root.val)  ## 查找第一个出现的位置，这里可以使用一个 set 来加速
            pre_idx += 1
            root.left = helper(preorder, inorder, left, index-1) ## 这里会递归更新 pre_idx
            root.right = helper(preorder, inorder, index+1, right)## 这里会使用求 root.left 中更新过的 pre_idx
            return root
        
        pre_idx = 0
        return helper(preorder, inorder, 0, len(preorder)-1)
```