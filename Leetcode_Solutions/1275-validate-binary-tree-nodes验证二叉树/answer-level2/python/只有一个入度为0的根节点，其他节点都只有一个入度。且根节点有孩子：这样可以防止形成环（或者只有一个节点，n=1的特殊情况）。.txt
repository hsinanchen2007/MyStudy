```python3
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        count = [0 for _ in range(n)]
        for i in range(len(leftChild)):
            if leftChild[i] != -1:
                count[leftChild[i]] += 1
            if rightChild[i] != -1:
                count[rightChild[i]] += 1
        flag = 0
        # print(count)
        for i in range(n):
            if count[i] > 1:
                return False
            if count[i] == 0:
                root = i
                flag += 1
        # 只有一个入度为0的根节点，其他节点都只有一个入度。且根节点有孩子：这样可以防止形成环（或者只有一个节点，n=1的特殊情况）。
        return flag == 1 and (n==1 or (leftChild[root]!=-1 or rightChild[root]!=-1))