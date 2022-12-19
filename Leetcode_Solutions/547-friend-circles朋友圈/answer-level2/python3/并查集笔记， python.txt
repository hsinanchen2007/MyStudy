### 解题思路
初次学习并查集

### 代码

```python3
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        #定义一个集合，保证每个元素的父节点是自己，各自都是独立集合
        father = [i for i in range(len(M))]

        #定义查找方法，顺着一个节点一直查找，直到找到父节点，父节点自己指向自己
        def find(x):
            a = x
            while father[x] != x:
                x = father[x]       #找到这个节点的根节点
            while a != father[a]:
                father[a] = x       #指向根节点
                a = father[a]               
            return x                #返回根节点

        #定义合并方法，就是通过上面查找方法，把a元素的父节点指向b元素的父节点,
        #返回a的父节点
        def unit(a, b):
            father[find(a)] = find(b)
            return find(a)

        for i in range(len(M)):
            for j in range(len(M[0])-1):
                if M[i][j] == 1:
                    unit(i, j)    #合并到集合中
        for i in range(len(M)):   #每次这个操作，都是把所有节点指向同一个根节点
            find(i)               #从头遍历，找出每个元素的父节点，因为合并时候只返回了a父节点
        return len(set(father))
```