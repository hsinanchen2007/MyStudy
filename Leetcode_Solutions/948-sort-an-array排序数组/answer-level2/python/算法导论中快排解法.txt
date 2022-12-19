采用一层循环完成切片[快排的四种Python实现](https://blog.csdn.net/razor87/article/details/71155518)
```python
class Solution:
    """算法导论中的快排"""
    def quick_sort(self,array,l,r):
        if l<r:
            q = self.partition(array,l,r)
            self.quick_sort(array,l,q-1)
            self.quick_sort(array,q+1,r)
    def partition(self,array,l,r):
        x = array[r]
        i = l - 1
        for j in range(l,r):
            if array[j] <= x:
                i += 1
                array[i],array[j] = array[j],array[i]
        array[i+1],array[r] = array[r],array[i+1]
        return i+1
    def sortArray(self, nums):
        self.quick_sort(nums,0,len(nums)-1)
        return nums
if __name__ == '__main__':
    nums = [5,1,1,2,0,0]
    s = Solution()
    print(s.sortArray(nums))
```
