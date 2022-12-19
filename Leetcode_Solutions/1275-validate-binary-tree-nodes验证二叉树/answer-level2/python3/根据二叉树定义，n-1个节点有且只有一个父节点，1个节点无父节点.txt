
统计每个节点的根结点个数，如果出现跟节点大于1的为非法，注意单独处理n大于2时的孤儿节点，
`python
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        
        memo = n*[0]
        for i in range(n):
            if leftChild[i]!=-1:memo[leftChild[i]]+=1
            if rightChild[i]!=-1:memo[rightChild[i]]+=1
        if len(list(filter(lambda x:x==1,memo)))==n-1 and len(list(filter(lambda x:x==0,memo)))==1 :
            if n>1:
                for i in range(len(memo)):
                    if memo[i]==0 and (leftChild[i]!=-1 or rightChild[i]!=-1):
                        return True
            else:
                return True
        return False
`
