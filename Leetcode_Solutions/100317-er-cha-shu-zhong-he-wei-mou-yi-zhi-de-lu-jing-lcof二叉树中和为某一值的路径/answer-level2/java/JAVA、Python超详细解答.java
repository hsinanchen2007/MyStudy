[楼主的个人博客，欢迎关注，有问必回哈](https://blog.csdn.net/qq_36929361)

## 解题分析
这道题，是要所有的结果的List集合，所以我们需要定义一个接受所有结果的全局变量res，如果有满足的结果，就把结果装到这个集合里面；

然后我们发现题目是要一条从根节点一直到叶子节点的路径，这条路径的和要是所给的值，我们的想法就是拿着根节点root，和所求的路径和sum往下递归，每递归到一层的节点，就用sum减去当前层节点的值，一直到sum==0并且是最后一层的节点，那么这条路径就是我们要找的结果路径之一；

那么，每次的路径节点我都用什么容器装载呢？不能到最后我们得出sum==0却发现之前递归的路径我们都不知道，那不是竹篮打水一场空么？所以我们可以定义一个List<Integer> temp来装载所有的路径，没错，我们就用一个List来记录所有的，但是有一个问题我们要清楚，List只在堆内存里面的，无论你怎么递归，List里面的值都是不会变的，也就是说，对于所有的递归方法来说，List始终都是那一个List，所以我们要注意两件事情：
1.找到结果之后不能直接把temp放到res里面，因为这样的结果放到了res里面，temp在之后递归的过程中值会变，这样res里面保存的讲不再是希望的记过，我们找到一个答案之后，需要把它再重生成一个List之后再放入结果集里面，这里可以借用集合的构造函数来重构，new ArrayList<>(temp)。
2.我们需要在每次向左向右递归之后删除上次递归的结果，也就是把temp里面最后的一条数据删掉，否则temp会带着递归回来的数据，你会发现最后temp已经超过了树的高度；

至于num，这个变量由于是存在在栈中的每次递归的方法中，每个方法的num都是独立的变量，所以我们不用考虑“悔棋”的操作；

这道题要求我们对对象和局部变量在内存中的位置有比较好的了解，如果这方面有欠缺的小伙伴哪块不会的话，可以来问我，或者查一下对应的资料；

## 代码
ps：这里笔者使用的jdk为1.8版本和Python3.7

- java实现
```java
 */
class Solution {
   List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (Objects.isNull(root)) {
            return res;
        }
        pathSum2(root, sum, new ArrayList<>());
        return res;
    }

    public void pathSum2(TreeNode root, int sum, List<Integer> temp) {
        sum -= root.val;
        temp.add(root.val);
        if (sum == 0 && Objects.isNull(root.left) && Objects.isNull(root.right)) {
            res.add(new ArrayList<>(temp));
        } else {
            if (Objects.nonNull(root.left)) {
                pathSum2(root.left, sum, temp);
                temp.remove(temp.size() - 1);
            } 
            if (Objects.nonNull(root.right)) {
                pathSum2(root.right, sum, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }
}
```
- python实现

```python
class Solution:

    def __init__(self):
        self.list_res = []

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root is None:
            return []
        self.pathSum2(root, sum, [])
        return self.list_res
    
    def pathSum2(self, root, sum_temp, list_temp):
        sum_temp -= root.val
        list_temp.append(root.val)

        if sum_temp == 0 and root.left is None and root.right is None:
            self.list_res.append(list_temp[:])
        else:
            if root.left is not None:
                self.pathSum2(root.left, sum_temp, list_temp)
                list_temp.pop()
            if root.right is not None:
                self.pathSum2(root.right, sum_temp, list_temp)
                list_temp.pop()
```
