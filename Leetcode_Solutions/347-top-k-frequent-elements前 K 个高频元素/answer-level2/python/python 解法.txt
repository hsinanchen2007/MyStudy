from collections import defaultdict

def swap(tree,i,j):
    temp = tree[i]
    tree[i] = tree[j]
    tree[j] = temp


def heapify(tree, n, i):
    if i < n:
        child1 = 2*i+1
        child2 = 2*i+2
        min = i
        if child1 <n and tree[child1][1]<tree[min][1]:
            min = child1
        if child2 <n and tree[child2][1]<tree[min][1]:
            min = child2
        if min != i:
            swap(tree,i,min)
            heapify(tree,n,min)


def build(tree,n):
    last = n-1
    last_parent = int((last-1)/2)
    for i in range(last_parent, -1, -1):
        heapify(tree, n, i)



def build_dict(arr):
    str2count = defaultdict(int)
    for str in arr:
        str2count[str] +=1
    return str2count
def main():
    arr = [1,1,1,2,3,4,3]
    str2count = build_dict(arr)

    k = 2
    str_list = [i for i in str2count.items()]
    min_heap = str_list[:k]
    build(min_heap, k)  # 取前k个元素构建最小堆
    for i in str_list[k:]:  # 遍历剩余元素
        if i[1] > min_heap[0][1]:  # 如果新元素> 堆顶元素，则将堆顶元素替换，然后向下筛选更新最小堆
            min_heap[0] = i
            heapify(min_heap, k, 0)

    print([i[0] for i in min_heap])