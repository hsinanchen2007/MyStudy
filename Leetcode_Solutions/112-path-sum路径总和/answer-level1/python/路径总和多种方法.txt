*方法一：*
前序遍历，找出根节点到叶子节点的所有路径，再进行每条路径求和判断，该方法直观，空间复杂度高，O(n),n为叶子节点的个数
```
def hasPathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        def search(node,route):
            if not node:
                return
            else:
                route = route + str(node.val)
                if (node.left==None) and (node.right==None):
                    paths.append(sum([int(r) for r in route.split('->')]))
                    routes.append(route)
                else:
                    route = route + '->'
                    search(node.left,route)
                    search(node.right,route)
            
        paths = []
        routes = []
        search(root,'')
        if sum_ in paths:
            return True
        else:
            return False
```
```
 class Solution {
        List<List<Integer>> list = new ArrayList<>();
        ArrayList<Integer> inner = new ArrayList<>();
        public List<List<Integer>> pathSum(TreeNode root, int sum) {
            if (root == null) return list;
            sum -= root.val;
            inner.add(root.val);  // 入列表
            if (root.left == null && root.right == null){
                if (sum == 0){
                    list.add(new ArrayList<>(inner));  // 记得拷贝一份
                }

            }
            if (root.left != null)  pathSum(root.left, sum);
            if (root.right != null)  pathSum(root.right, sum);
            inner.remove(inner.size()-1);  //从列表中删除
            return list;
        }
    }
```


*方法二：*
优化空间复杂度,直接每次缓存求和每一条路径，若存在该和的路径，则返回True

```
def hasPathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        def search(node,route_sum):
            if not node:
                return
            else:
                route_sum = route_sum + node.val
                if (node.left==None) and (node.right==None):
                    if route_sum == sum_:
                        self.flag = True
                        return 
                else:
                    search(node.left,route_sum)
                    search(node.right,route_sum)
        
        self.flag = False
        search(root,0)
        return self.flag
```


*方法三：*
将上述递归方法，用栈迭代实现，每个节点存储从根节点到该节点的和
```
def hasPathSum(self, root, sum_):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return 
        
        route_sum = 0
        stacks = [(root,route_sum)]
        while len(stacks)>0:
            node,route_sum = stacks.pop()
            route_sum = route_sum + node.val
            if not node.left and not node.right:
                print(node.val,route_sum)
                if route_sum == sum_:
                    return True
            else:
                if node.left:
                    stacks.append((node.left,route_sum))
                if node.right:
                    stacks.append((node.right,route_sum))

        return False
```
扩展：
从上至下的路径，任意节点开始，至任意节点结束，找到路径和与指定值相等的所有路径

```
def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        # 找出所有路径
        # def search(node,route,r_sum):
        #     if node == None:
        #         return 
        #     route = route + str(node.val)
        #     r_sum = r_sum + node.val
        #     if r_sum < sum:
        #         route = route+'->'
        #     elif r_sum== sum:
        #         self.paths.append(route)
        #         route = ''
        #         r_sum = 0
        #     else:
        #         route = ''
        #         r_sum = 0

        #     print(self.paths,route,r_sum)
        #     search(node.left,route,r_sum)
        #     search(node.right,route,r_sum)

        # self.paths = []
        # search(root,'',0)
        # print(self.paths)
        # return len(self.paths)

        #找出有几条路径
        if not root:
            return 0
        
        stack = [(root,[root.val])]
        res = 0

        while stack:
            node,temp = stack.pop()
            res += temp.count(sum)
            temp += [0]
            if node.left:
                arr = [i+node.left.val for i in temp]
                stack.append((node.left,arr))
            
            if node.right:
                arr = [i+node.right.val for i in temp]
                stack.append((node.right,arr))
        
        return res
```

