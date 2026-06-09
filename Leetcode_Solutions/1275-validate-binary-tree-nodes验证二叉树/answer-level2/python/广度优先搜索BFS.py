### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """
        index=[0]*n 
        for element in leftChild:
            if element!=-1:
                index[element]+=1
        for element in rightChild:
            if element!=-1:
                index[element]+=1
        root = -1
        for i in range(n):
            if index[i]==0:
                root=i 
        if root==-1:
            return False
        seen = set()
        seen.add(root)
        q = [root]
        while(q):
            u=q.pop(0)
            if leftChild[u]!=-1:
                if leftChild[u] in seen:
                    return False
                seen.add(leftChild[u])
                q.append(leftChild[u])
            if rightChild[u]!=-1:
                if rightChild[u] in seen:
                    return False
                seen.add(rightChild[u])
                q.append(rightChild[u])
        return len(seen)==n

        
```