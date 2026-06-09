
o(n)时间，因为计算了len，空间o(n),此方法用了nums[:],属于伪原地。
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums[:]=nums[(len(nums)-k):]+nums[:(len(nums)-k)]
```


o(n^2)时间，list增删效率低，o(1)空间
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n=0
        while n<k: 
            nums.insert(0,nums[-1])
            nums.pop()
            n+=1
```


o(n)时间，改为双端队列，相当于linklist.增删效率高。不过队列开辟了o(n)的空间，也是伪原地。
```
from collections import deque
    def rotate(nums, k) :
        q=deque(nums)
        q.rotate(k)
        nums[:]=q
```

暴力法，真原地操作，将最后一个元素存为临时，其余元素后移一个格子，再把临时存的放在位置0，
重复K次，因为移动次数太多。友情提示，超时。
```
def rotate(nums, k) :
    n=0
    while n<k:
        temp=nums[-1]
        for i in range(len(nums)-2,-1,-1):
            nums[i+1]=nums[i]
        nums[0]=temp
        n+=1
```

从题意看O(1)的额外空间，可知必须用多指针操作。这类见官答。。