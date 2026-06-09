```
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        #此题方法和23. 合并K个排序链表 相似
        #采用堆排序
        def adjustHeap(heap,start,end):
            dad=start
            son=dad*2+1
            while son<end:
                x=matrix[heap[dad][0]][heap[dad][1]]
                y1=matrix[heap[son][0]][heap[son][1]]
                if son+1<end:
                    y2=matrix[heap[son+1][0]][heap[son+1][1]]
                    if y2<y1:
                        son=son+1
                        y1=matrix[heap[son][0]][heap[son][1]]
                if x>y1:
                    tmp=heap[dad]
                    heap[dad]=heap[son]
                    heap[son]=tmp
                    dad=son
                    son=dad*2+1
                else:
                    return
        
        n=len(matrix)
        
        heap=[]
        for i in range(0,n):
            heap.append([i,0])
            
        #初始化堆
        t=n//2-1
        while True:
            if t<0:
                break
            adjustHeap(heap,t,n)
            t=t-1
        
        for i in range(0,k-1):
            tmp=heap.pop(0)
            if tmp[1]+1<n:
                heap.insert(0,[tmp[0],tmp[1]+1])
                adjustHeap(heap,0,len(heap))
            else:
                a=heap.pop()
                heap.insert(0,a)
                adjustHeap(heap,0,len(heap))
                
        return matrix[heap[0][0]][heap[0][1]]
```
