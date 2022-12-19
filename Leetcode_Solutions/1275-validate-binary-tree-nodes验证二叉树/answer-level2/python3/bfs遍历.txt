先找root节点，然后bfs遍历。思路简单

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        root = -1
        for i in range(n):
            if i not in leftChild and i not in rightChild:
                if root != -1:
                    return False
                root = i
        test_list = [False]*(n+1)
        test_list[root] = True
        # print(root)
        import queue
        q_store = queue.Queue()
        q_store.put(root)
        while not q_store.empty():
            tmp_q = q_store.get()
            if test_list[leftChild[tmp_q]] or test_list[rightChild[tmp_q]]:
                print(tmp_q)
                return False
            if leftChild[tmp_q] != -1:
                q_store.put(leftChild[tmp_q])
                test_list[leftChild[tmp_q]] = True
            if rightChild[tmp_q] != -1:
                q_store.put(rightChild[tmp_q])
                test_list[rightChild[tmp_q]] = True
        
        # print(test_list)
        if False in test_list[:-1]:
            return False
        return True