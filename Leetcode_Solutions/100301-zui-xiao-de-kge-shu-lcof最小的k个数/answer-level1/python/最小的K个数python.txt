```
class Solution(object):
    def sift(self, li, low, high):
        """
        li: 列表
        low：堆的根节点位置
        high：堆的最后一个元素的位置
        """
        # 调整变换成一个堆
        i = low  # i最开始指向根节点
        j = 2*i + 1 # j是左孩子
        tmp = li[low]  #把堆顶保存下来
        while j<=high:  #只要j位置有数
            if j + 1 <= high and li[j+1] >li[j]: #如果有右孩子并且比左孩子大
                j = j+1 #j指向右孩子
            if li[j] > tmp:
                li[i] = li[j] #把原孩子节点写到父节点位置
                i = j  #向下走一层
                j = 2*i + 1
            else:   #tmp更大，把tmp放到i的位置
                li[i] = tmp
                break
        else:
            li[i] = tmp #把 tmp放到叶子节点

    def heap_sort(self, li):
        n = len(li)
        for i in range((n-2)//2,-1,-1):  #分块（两层二叉树）调整
            # i表示建堆的时候 调整部分（二层）的跟的下标
            self.sift(li, i, n-1)
            #所有块调整完，建堆完成
        for i in range(n-1, -1, -1):
            #i 指向当前堆的最后一个元素
            # array.append(li[0]) #也可以写到新的列表中，缺点是占用新的内存
            li[0], li[i] = li[i], li[0] #交换位置，不用新建列表，节省空间
            self.sift(li, 0, i-1) #i-1是新的high

    # 快速排序算法
    def quick_sort(self, arr):
        if len(arr) < 2: # 基线条件 未排序区只含有1个元素
            return arr
        else:
            tmp = arr[0] # 列表第一个元素为选择的基准值
            less = [ i for i in arr[1:] if i<=tmp] #小于基准值的元素，写入less列表中
            larger = [i for i in arr[1:] if i>tmp] # 大于基准值的元素，写入larger列表中
            re = self.quick_sort(less) + [tmp] + self.quick_sort(larger)
        return re

    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        #快速排序法
        r = self.quick_sort(arr)
        return r[:k]
        #堆排序法
        # self.heap_sort(arr)
        # return arr[:k]
```
