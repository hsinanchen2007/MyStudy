### 解题思路
这道题核心是排序，所以可以借着这道题实现一下所有的基础排序


### 冒泡排序
冒泡排序
冒泡排序就是从头开始比较，相邻数据两两比较，如果前一个更大，则交换。不断重复这个交换过程，直到排序完成。
一句话解释就是：通过交换元素逐步消除逆序
时间复杂度O(n^2),空间复杂度O(1)，稳定排序（相同元素不改变相对位置）
```python3
#冒泡排序
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        flag = True #提前设定一个指示，如果已经排好序就可以提前结束排序
        i = 1
        while i < len(nums) and flag:
            flag = False
            for j in range(len(nums)-1):
                if nums[j+1]< nums[j]:
                    p = nums[j]         #核心就是交换，如果比它小，则交换，一直循环直到全部排好序
                    nums[j] = nums[j+1]
                    nums[j+1] = p
                    flag = True
            i += 1
        return nums
```



### 快速排序
2.快速排序，快速排序分为三步：
    1.选择一个标准，根据这个标准，这组数据被划分为2份，小的那份在前
    2.递归实现继续划分，在已经划分好的两份里面继续执行（1）
    3.每个数据成为一组时，划分完毕
时间复杂度O(nlogn)，空间复杂度O(logn)，不稳定
```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        def qsort(lst,lft,rght):
            if lft>rght: return
            i = lft #小的那份
            j = rght #大的那份
            p = lst[i] #标准
            while i < j:
                while i<j and lst[j] > p: #如果尚未完成排序，且大的那份比设定的标准大，则继续向前查找
                    j -= 1
                if i < j:                 #如果在查找完大的这份数组之前，找到小于设定标准的，则放入小的那份
                    lst[i] = lst[j]
                    i += 1
                while i < j and lst[i] <= p: #同理，如果小的那份比设定标准小，则继续查找
                                             #如果小的那份找找到比设定标准大的，则放入大的那份
                    i+=1
                if i < j:
                    lst[j] = lst[i]
                    j-=1
            lst[i] = p
            qsort(lst,lft,i-1)               #递归，不断缩小待排序数组长度，直到每个数据成一组，排序完毕
            qsort(lst,i+1,rght)
        qsort(nums,0,len(nums)-1)
        return nums 
```


   

###选择排序
3.选择排序
这种方法和我们正常的思维很像，依次找到最小的，次小的... 然后放在第一位，第二位...
即：1.找到数据中最小的放在首位；2.在剩余数据中找到最小的放在第二位；3.直到全部放置完毕
时间复杂度O(n^2),空间复杂度O(1)，不稳定
```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1):
            k = i
            for j in range(i,len(nums)):
                if nums[k] > nums[j]:
                    k = j
            if i != k:
                nums[i],nums[k] = nums[k],nums[i]
        return nums
```



###插入排序
4.插入排序
是一种稳定排序，每次抽出一个未排序的数字和前面已排序的数组中数据进行比较，如果比每个都大，则放在已排序的数组后面，否则比该未排序的数字大的已排序的数组中数据后移一位。
    1.插入前和已排好序的数值比较
    2.若大于该数值，则继续往后遍历，直到遍历全部已排序数组
    3，若小于该数值，则插入到该数值前面一位，该数及后续数后移一位
时间复杂度O(n^2),空间复杂度O(1)，不稳定
```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(1,len(nums)):
            p = nums[i]
            j = i
            while j > 0 and nums[j-1] > p:
                nums[j] = nums[j-1]
                j -= 1
            nums[j] = p
        return nums

```
###归并排序
归并排序就是分治思想的强力体现了。
思路是：（感觉和快排有点相反的味道）
首先将原始数组中看做n个有序的子数组，然后两两合并，合并完成后保持合并后的子数组仍有序，再不断两两合并，直到得到长度为n的有序数组
时间复杂度O(nlogn)，空间复杂度O(n)，稳定
```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2:
            return nums
        mid = len(nums)//2
        lft = nums[:mid]
        rght = nums[mid:]
        self.sortColors(lft)
        self.sortColors(rght)
        i = j = k = 0
        #这一块是归并排序中进行排序的作用
        while i < len(lft) and j <len(rght): #因为分为左右两组分开排序，所以停止标志是至少一边停止排序
            if lft[i] < rght[j]:            #如果待排序的两个数组中，左边的小于右边的，则将左边的放在首位
                nums[k] = lft[i]
                i += 1
            else:                           #反之右边的放在首位
                nums[k] = rght[j]
                j += 1
            k += 1
        while i < len(lft):                 #如果右边完成了排序，则将左边的直接放在数组后面
            nums[k] = lft[i]
            i += 1
            k += 1
        while j < len(rght):                #如果左边的完成了排序，则将右边的直接放在数组后面
            nums[k] = rght[j]
            j += 1
            k += 1
        return nums
        
```


