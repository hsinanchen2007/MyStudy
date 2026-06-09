# 1.优化的冒泡(超出)
```
class Solution:
    def bubble_sort(nums):
        for i in range(len(nums) - 1):  
            flag = False  # 改进后的冒泡，设置一个交换标志位
            for j in range(len(nums) - i - 1):  
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    flag = True
            if not flag:
                return nums  # 这里代表计算机偷懒成功。
```
# 2.选择排序(超出)
```
class Solution:
    def selection_sort(nums): 
        for i in range(len(nums)): 
            min_idx = i 
            for j in range(i+1, len(nums)): 
                if nums[min_idx] > nums[j]: 
                    min_idx = j 
                        
            nums[i], nums[min_idx] = nums[min_idx], nums[i] 
        return nums
```
# 3.插入排序
 **从第二个元素开始和前面的元素进行比较，如果前面的元素比当前元素大，则将前面元素 后移，当前元素依次往前，直到找到比它小或等于它的元素插入在其后面。**
```
class Solution:
    def insertion_sort(nums):
        # 第一层for表示循环插入的遍数
        for i in range(1, len(nums)):
            for j in range(i, 0,  -1):
                if nums[j] < nums[j-1]:
                    nums[j], nums[j-1] = nums[j-1], nums[j]
                else:
                    break
        return nums
        
```
# 4.快速排序
**任意选取一个数据（通常选用数组的第一个数或最后一个数）作为关键数据，然后将所有比它小的数都放到它前面，所有比它大的数都放到它后面，这个过程称为一趟快速排序。 **
```
class Solution:
    def partition(arr,low,high): 
        i = (low-1)         # 最小元素索引
        pivot = arr[high]     
        for j in range(low,high): 
        # 当前元素小于或等于 pivot 
            if   arr[j] <= pivot: 
                i = i+1 
                arr[i], arr[j] = arr[j], arr[i] 
        arr[i+1], arr[high] = arr[high], arr[i+1] 
        return i+1  
    def quickSort(arr,low,high): 
        if low < high:
            pi = partition(arr, low, high) 
            quickSort(arr, low, pi-1) 
            quickSort(arr, pi+1, high) 
        n = len(arr) 
        quickSort(arr, 0, n-1) 

```
# 5.归并排序
```
class Solution:
    def merge_sort(arr):
        if len(arr) == 1: return arr
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        return marge(merge_sort(left), merge_sort(right))
    def marge(left, right):
        res = []
        while len(left) > 0 and len(right) > 0:
        # 左右两个数列第一个最小放前面
            if left[0] <= right[0]:
                res.append(left.pop(0))
            else:
                res.append(right.pop(0))
        # 只有一个数列中还有值，直接添加
        res += left
        res += right
        return res
   
```
# 6.桶排序（牺牲空间）
```
class Solution:
    def bucket_sort(s):
        min_num = min(s)
        max_num = max(s)
        # 桶的大小
        bucket_range = (max_num-min_num) / len(s)
        # 桶数组
        count_list = [ [] for i in range(len(s) + 1)]
        # 向桶数组填数
        for i in s:
            count_list[int((i-min_num)//bucket_range)].append(i)
        s.clear()
        # 回填，这里桶内部排序直接调用了sorted
        for i in count_list:
            for j in sorted(i):
            s.append(j)
       
```
# 7.计数排序 --当数值中有非整数时，计数数组的索引无法分配
```
class Solution:
    def count_sort(s):
        # 找到最大最小值
        min_num = min(s)
        max_num = max(s)
        # 计数列表
        count_list = [0]*(max_num-min_num+1)
        # 计数
        for i in s:
            count_list[i-min_num] += 1
        s.clear()
        # 填回
        for ind,i in enumerate(count_list):
            while i != 0:
            s.append(ind+min_num)
            i -= 1

```
# 8.希尔排序（减小增量排序）
** 希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本。但希尔排序是非稳定排序算法。
希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。**
```
class solution:
    def shell_sort(s):
        b = len(s)                         #列表长度
        gap = b // 2                       #初始步长设置为总长度的一半
        while gap >= 1:
            for i in range (b):
                j = i
                while j >= gap and s[j-gap] > s[j]:   #在每一组里面进行直接插入排序
                    s[j], s[j-gap] = s[j-gap], s[j]
                    j-= gap
            gap = gap//2                              #更新步长

```
# 9.堆排序
```
class Solution:
    def heapify(arr, n, i): 
        largest = i  
        l = 2 * i + 1     # left = 2*i + 1 
        r = 2 * i + 2     # right = 2*i + 2 
    
        if l < n and arr[i] < arr[l]: 
            largest = l 
    
        if r < n and arr[largest] < arr[r]: 
            largest = r 
    
        if largest != i: 
            arr[i],arr[largest] = arr[largest],arr[i]  # 交换
    
            heapify(arr, n, largest) 
    
    def heapSort(arr): 
        n = len(arr) 
    
        # Build a maxheap. 
        for i in range(n, -1, -1): 
            heapify(arr, n, i) 
    
        # 一个个交换元素
        for i in range(n-1, 0, -1): 
            arr[i], arr[0] = arr[0], arr[i]   # 交换
            heapify(arr, i, 0) 
```
# 10.基数排序
```
class Solution:
    def radix_sort(s):
        """基数排序"""
        i = 0 # 记录当前正在排拿一位，最低位为1
        max_num = max(s)  # 最大值
        j = len(str(max_num))  # 记录最大值的位数
        while i < j:
            bucket_list =[[] for _ in range(10)] #初始化桶数组
            for x in s:
                bucket_list[int(x / (10**i)) % 10].append(x) # 找到位置放入桶数组
            s.clear()
            for x in bucket_list:   # 放回原序列
                for y in x:
                    s.append(y)
            i += 1
```










