### 解题思路
此处撰写解题思路
![QQ图片20200212204537.png](https://pic.leetcode-cn.com/0beacddd8285789975292d4632b9f9f7eb975ee937215cfef26c5c3d9cacdb64-QQ%E5%9B%BE%E7%89%8720200212204537.png)
没有使用官方的方法，用的是之前看左程云视频里提到的一种思路，但是耗时巨多

生成两个堆，一个堆存放所有数据中叫小的(N/2)个数据，做成大根堆Max_arr， 另一个存放较大的(N/2)个数据，做成小根堆，调取中位数时，只需要看两个堆的情况即可，两个堆的数据多一个就返回哪个堆的堆顶，若是一样多则返回两个堆顶的一半

本来想用python自带的优先级队列实现，但是想不到方法可以让数据在堆里交换，不知道哪位大神可以改进一下这种方法，我现在这个用时太多了
### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        num = nums1 + nums2
        self.Max_arr = []
        self.Min_arr = []
        for item in num:
            self.push(item)
        return self.Get_Median()

    def push(self, x):
        if not self.Min_arr or x < self.Min_arr[0]:
            self.Max_arr.append(x)
            self.Build_B_Heap()
        else:
            self.Min_arr.append(x)
            self.Build_S_Heap()

        if len(self.Max_arr) - len(self.Min_arr) > 1:
            self.Max_arr[0], self.Max_arr[-1] = self.Max_arr[-1], self.Max_arr[0]
            self.Min_arr.append(self.Max_arr.pop())
            self.Build_S_Heap()
            self.B_Heapify()
        if len(self.Min_arr) - len(self.Max_arr) > 1:
            self.Min_arr[0], self.Min_arr[-1] = self.Min_arr[-1], self.Min_arr[0]
            self.Max_arr.append(self.Min_arr.pop())
            self.Build_B_Heap()
            self.S_Heapify()

    def Build_B_Heap(self):
    #生成大根堆
        i = len(self.Max_arr) - 1
        while int((i - 1)/2) >= 0:
            if self.Max_arr[i] > self.Max_arr[int((i - 1)/2)]:
                self.Max_arr[i], self.Max_arr[int((i - 1)/2)] = self.Max_arr[int((i - 1)/2)], self.Max_arr[i]
                i = int((i - 1)/2)
            else:
                break

    def B_Heapify(self):
        i = 0
        while (2 * i + 2) < len(self.Max_arr):
            if self.Max_arr[2 * i + 1] >= self.Max_arr[2 * i + 2] and self.Max_arr[2 * i + 1] >= self.Max_arr[i]:
                self.Max_arr[i], self.Max_arr[2 * i + 1] = self.Max_arr[2 * i + 1], self.Max_arr[i]
                i = 2 * i + 1
            elif self.Max_arr[2 * i + 2] >= self.Max_arr[2 * i + 1] and self.Max_arr[2 * i + 2] >= self.Max_arr[i]:
                self.Max_arr[i], self.Max_arr[2 * i + 2] = self.Max_arr[2 * i + 2], self.Max_arr[i]
                i = 2 * i + 2
            else:
                break
        
        if len(self.Max_arr) == 2:
            (self.Max_arr[0], self.Max_arr[-1]) = (self.Max_arr[0], self.Max_arr[-1]) if self.Max_arr[0] > \
							  self.Max_arr[-1] else (self.Max_arr[-1], self.Max_arr[0])



    def Build_S_Heap(self):
        #生成小根堆
        i = len(self.Min_arr) - 1
        while int((i - 1)/2) >= 0:
            if self.Min_arr[i] < self.Min_arr[int((i - 1)/2)]:
                self.Min_arr[i], self.Min_arr[int((i - 1)/2)] = self.Min_arr[int((i - 1)/2)], self.Min_arr[i]
                i = int((i - 1)/2)
            else:
                break

    def S_Heapify(self):
        i = 0
        while (2 * i + 2) < len(self.Min_arr):
            if self.Min_arr[2 * i + 1] <= self.Min_arr[2 * i + 2] and self.Min_arr[2 * i + 1] <= self.Min_arr[i]:
                self.Min_arr[i], self.Min_arr[2 * i + 1] = self.Min_arr[2 * i + 1], self.Min_arr[i]
                i = 2 * i + 1
            elif self.Min_arr[2 * i + 2] <= self.Min_arr[2 * i + 1] and self.Min_arr[2 * i + 2] <= self.Min_arr[i]:
                self.Min_arr[i], self.Min_arr[2 * i + 2] = self.Min_arr[2 * i + 2], self.Min_arr[i]
                i = 2 * i + 2
            else:
                break
        if (2 * i + 1) < len(self.Min_arr):
            self.Min_arr[i], self.Min_arr[2 * i + 1] = (self.Min_arr[i], self.Min_arr[2 * i + 1]) if self.Min_arr[i] < \
							self.Min_arr[2 * i + 1] else (self.Min_arr[2 * i + 1], self.Min_arr[i])
        if len(self.Min_arr) == 2:
            (self.Min_arr[0], self.Min_arr[-1]) = (self.Min_arr[0], self.Min_arr[-1]) if self.Min_arr[0] < \
							  self.Min_arr[-1] else (self.Min_arr[-1], self.Min_arr[0])

    def Get_Median(self):
        if len(self.Min_arr) > len(self.Max_arr):
            return self.Min_arr[0]
        elif len(self.Min_arr) < len(self.Max_arr):
            return self.Max_arr[0]
        else:
            return (self.Min_arr[0] + self.Max_arr[0]) /2
```