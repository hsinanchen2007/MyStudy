方法一：
利用python中列表的del删除为0的元素，之后再末尾加上0。
这样的方法有一个弊端就是你到底要while执行多少次？因为你删了一个0但是后面又加了一个0，通过i-,i+,就陷入死循环了。
我在这里给出的方法是while执行最多执行的次数，这个次数就是nums的长度。
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length=len(nums)-1
        i=0;m=0
        while m <=length-1:
            if nums[i]==0:
                del nums[i]
                nums.append(0)
                i-=1
            i+=1
            m+=1
```
时间复杂度分析：
由于列表的删除操作时间复杂度是O(n),以及外围的while循环时间复杂度为O(n),时间复杂度一共是O(n^2).


方法二：
我们如果不做删除操作的话，采用两个指针移动法，一个指针p用来指向当前被修改的元素位置，另外一个q作为滑动，总体滑动次数就为数组的长度。
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p=0;q=0
        length=len(nums)
        while q<=length-1:
            if nums[q]!=0:
                nums[p]=nums[q]
                p+=1
            q+=1
        # print("p=",p)
        for i in range (p,length):
            nums[i]=0
```
方法三：
由于上面我们在最后还需要对p之后的数组赋值为0，那么我们能不能让代码更加优雅一点？同样的时间复杂度但是代码优雅一点？
有的，那就是交换元素，我们在上面的代码中交换p,q位置就可以了。