通过分析，知道正确的二叉树是0结点没有被其它结点访问过，而且其他结点应该被访问一次。否则，就是不正确的二叉树。

```
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild, rightChild) -> bool:
        def isValid(arr):
            for i in range(n):
                if (i==0 and arr[i]!=0) or (i>0 and arr[i]!=1):
                    return False
            return True
        visit = [0]*n
        for i in range(n):
            if leftChild[i]>-1:
                visit[leftChild[i]] += 1
            if rightChild[i]>-1:
                visit[rightChild[i]] +=1
        return isValid(visit)
```

