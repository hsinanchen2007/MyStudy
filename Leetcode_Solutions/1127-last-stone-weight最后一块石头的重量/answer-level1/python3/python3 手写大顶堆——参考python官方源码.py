### 解题思路
1、官方默认实现小顶堆，我就在官方源码的基础上略加修改（其实就是改了个大于小于号），实现了大顶堆。
2、在最后加了个自定义的heapsort()方法，实现了原地堆排序（升序）。
3、解决本题的话实际上用不到这么多方法，主要使用heappush(heap,item)和heappop(heap)这两个方法就可以了，这个具体实现题解中已有很多代码参考，就不再赘述。

### 代码

```python3
#从pos位置向startpos位置（一般为根节点）渗透，即自底向上。时间复杂度O(logn)
def _siftdown(heap, startpos, pos):
    newitem=heap[pos]
    while pos>startpos:
        parentpos=(pos-1)>>1
        if heap[parentpos]<newitem:
            heap[pos]=heap[parentpos]
            pos=parentpos
            continue
        break
    heap[pos]=newitem
```
```python3
#利用_siftdown()方法实现入堆操作。时间复杂度O(logn)   
def heappush(heap,item):
    heap.append(item)
    _siftdown(heap,0,len(heap)-1)
```
```python3 
#从pos位置向endpos位置（一般为叶子节点）渗透，即自顶向下。时间复杂度O(logn)
def _siftup(heap,pos,endpos):
    startpos=pos
    item=heap[pos]
    childpos=pos*2+1
    while childpos<endpos:
        rightpos=childpos+1
        if rightpos<endpos and heap[rightpos]>heap[childpos]:
            childpos=rightpos
        heap[pos]=heap[childpos]
        pos=childpos
        childpos=pos*2+1
    heap[pos]=item
    _siftdown(heap,startpos,pos)
```
```python3
#利用_siftup()方法实现出堆操作。时间复杂度O(logn)    
def heappop(heap):
    lastelt=heap.pop()
    if heap:
        returnitem=heap[0]
        heap[0]=lastelt
        _siftup(heap,0,len(heap))
        return returnitem
    return lastelt
```
```python3
#利用_siftup()方法实现对x的原地大顶堆化，此处x为list类型。时间复杂度O(nlogn)
def heapify(x):
    n=len(x)
    for i in reversed(range(n//2)):
        _siftup(x,i,n)
```
```python3     
#首先利用heapify()方法将列表x变为大顶堆，然后利用_siftup()方法实现堆排序。时间复杂度O(nlogn)
def heapsort(x):
    heapify(x)
    n=len(x)
    for i in range(n-1,0,-1):
        x[0],x[i]=x[i],x[0]
        _siftup(x,0,i)
```