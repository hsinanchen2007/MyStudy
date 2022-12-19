```
def floating(heap,index):
    parent = int((index-1)/2)
    
    while heap[index] < heap[parent] and index!=0:
        heap[index],heap[parent] = heap[parent],heap[index]
        index = parent
        parent = int((index-1)/2)

def sinking(heap,index):
    left = 2 * index + 1
    right = 2* index + 2
    while right < len(heap):
        # 当前节点存在左子节点 与 右子节点
        min_tmp_index = left if heap[left] <= heap[right] else right
        if heap[index] <= heap[min_tmp_index]:
            break
        heap[index],heap[min_tmp_index] = heap[min_tmp_index],heap[index]
        index = min_tmp_index
        left = 2 * index + 1
        right = 2* index + 2
    
    # 当前节点可能还存在 左子节点
    if left < len(heap) and heap[index] > heap[left]:
        heap[index],heap[left] = heap[left],heap[index]
        
def insert(heap, num):
    """ Min-heap的插入(数组尾部加元素+上浮)
    时间复杂度为树的深度：O(logn)
    空间复杂度：O(1)"""
    
    # 插入存储结构尾部
    heap.append(num)
    
    # 上浮
    floating(heap, len(heap)-1)

    
def delete(heap):
    """ Min-heap的删除（数组尾部移到头部+下沉）
    时间复杂度为树的深度：O(logn)
    空间复杂度：O(1)
    """
    if not heap:
        raise ValueError(" heap empty error ")
        
    min_val = heap[0]
    heap[0] = heap[-1]
    heap.pop(-1)
    
    sinking(heap,0)
    return min_val

def build(nums):
    """创建Min-heap
    从 int(length/2-1): 最后一个非叶节点 开始调整
    """
    for i in range(int(len(nums)/2-1),-1,-1):
        sinking(nums,i)
    return nums
```

在本题中可以这样使用
```
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        heap = build(arr)
        res = []
        for i in range(k):
            res.append(delete(heap))
            print(heap)
        return res
```
