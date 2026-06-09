### 解题思路
就不递归，😒

### 代码

```swift
class Solution {
    func sumRootToLeaf(_ root: TreeNode?) -> Int {

        //如果输入为空🌲，直接返回
        guard let root = root else { return 0 }

        //初始化一个元素为元组的stack，用来记录当前访问的节点 和 从根到该节点为止的值的和
        var stack:[(TreeNode,Int)] = [(root, root.val)]
        
        //定义返回值
        var ans = 0

        //迭代遍历🌲，其实本质上也是在求🌲的所有路径。这个循环做了下面三件事：
        //循环每次开始获取stack栈头的信息,并先将栈头踢出stack
        //1,如果当前访问到的节点没有左子和右子，说明已经到叶了，把探索完成的当前路径上的所有节点的和传入ans
        //2,如果当前访问到的节点有左子，则将左子 和 根到左子 的所有值的和插入stack
        //3,如果当前访问到的节点有右子,则将右子 和 根到右子 的所有值得和插入stack
        while let node = stack.last?.0, let value = stack.last?.1{
            
            stack.removeLast()
            
            if node.left == nil && node.right == nil {
                ans += value
            }
            
            if node.left != nil {
                stack.append((node.left!, value << 1 + node.left!.val ))
            }
            
            if node.right != nil {
                stack.append((node.right!, value << 1 + node.right!.val ))
            }
            
        }
        
        return ans
    }

}
```