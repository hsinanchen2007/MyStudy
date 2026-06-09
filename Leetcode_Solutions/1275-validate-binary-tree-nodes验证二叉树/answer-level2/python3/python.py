### 解题思路
1.根据入度为0，找到根节点，若根节点不唯一或有多个，则判错。
2.根据根节点遍历树，当且仅当每个节点被遍历一次，则判对，需特别注意环的情况,即遍历过程中是否有节点重复出现，如有，则判错。
3.判断环可以用hash表，如下代码直接使用循环来判别环的存在，因此还可继续优化。

### 代码（faster than 6%）

```python3
class Solution:
    def bfs(self,root,nodes,leftChild, rightChild):
        import collections
        temp=collections.deque()
        temp.append(root)
        h=[]
        h.append(root)
        nodes[root]+=1
        while temp:
            i=temp.popleft()
            if leftChild[i]!=-1:
                if leftChild[i] in h:
                    nodes[leftChild[i]]+=1000
                    break
                else:
                    temp.append(leftChild[i])
                    h.append(leftChild[i])
                    nodes[leftChild[i]]+=1
            if rightChild[i]!=-1:
                if rightChild[i] in h:
                    nodes[rightChild[i]]+=1000
                    break
                else:
                    temp.append(rightChild[i])
                    h.append(rightChild[i])
                    nodes[rightChild[i]]+=1
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        a=[0]*n
        for node in leftChild:
            if node!=-1:
                a[node]+=1
        for node in rightChild:
            if node!=-1:
                a[node]+=1
        root=0
        num=0
        for i in range(n):
            if a[i]==0:
                root=i
                num+=1
        if num!=1:
            return False
        nodes=[0]*n
        self.bfs(root,nodes,leftChild, rightChild)
        for i in nodes:
            if i!=1:
                return False
        return True
        


```
### 优化后代码（faster than 44%）
```
class Solution:
    def bfs(self,root,nodes,leftChild, rightChild):
        import collections
        temp=collections.deque()
        temp.append(root)
        h=[0]*len(leftChild)
        h[root]=1
        nodes[root]+=1
        while temp:
            i=temp.popleft()
            if leftChild[i]!=-1:
                if h[leftChild[i]]>0:
                    nodes[leftChild[i]]+=1000
                    break
                else:
                    temp.append(leftChild[i])
                    h[leftChild[i]]+=1
                    nodes[leftChild[i]]+=1
            if rightChild[i]!=-1:
                if h[rightChild[i]]>0:
                    nodes[rightChild[i]]+=1000
                    break
                else:
                    temp.append(rightChild[i])
                    h[rightChild[i]]+=1
                    nodes[rightChild[i]]+=1
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        a=[0]*n
        for node in leftChild:
            if node!=-1:
                a[node]+=1
        for node in rightChild:
            if node!=-1:
                a[node]+=1
        root=0
        num=0
        for i in range(n):
            if a[i]==0:
                root=i
                num+=1
        if num!=1:
            return False
        nodes=[0]*n
        self.bfs(root,nodes,leftChild, rightChild)
        for i in nodes:
            if i!=1:
                return False
        return True
```