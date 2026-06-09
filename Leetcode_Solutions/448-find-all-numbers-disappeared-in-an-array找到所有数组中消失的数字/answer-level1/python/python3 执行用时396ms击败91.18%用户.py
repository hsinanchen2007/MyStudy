### 解题思路
此处撰写解题思路
菜鸟第一次写题注。![批注 2020-03-31 185423.png](https://pic.leetcode-cn.com/16343bc4e7e5e4470eb93fd753c8822b82a96594d6cce33b26a873e6e58ef920-%E6%89%B9%E6%B3%A8%202020-03-31%20185423.png)

刚开始是这么想的，利用for循环产生从1到len(nums)之间的数字，然后依次判断每个数字有没有在数组nums里面，没有的话就把这个数字保存下来。下面是代码。
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        length=len(nums)
        disappear=[]
        for i in range(1,length+1):
            if i not in nums:
                disappear.append(i)
        return disappear

很容易就想到这个思路，代码也比较简洁，但是运行时间超时。本来以为自己这个时间复杂度是O(n),结果运行超时，傻眼了。我想了一下，运行超时是因为每一次for循环都要判断当前元素in不in 数组nuns，这样的话时间复杂度可能实际上就类似于O(n^2)了，从而导致超时。
于是，想到了下面的思路。先把列表nums变为集合set,目的是去除重复元素，然后构建一个标准数组standard,这个数组长度和nums相同，并且所有元素置0。接下来利用两个for循环：第一个循环的作用是将去重后的nums中的值赋给standard中对应位置的元素；第二个循环是检测standard中为0的元素，如果为某个位置i的元素为0，就可以判定出nums中缺了元素(i+1)，并放置于disappear中。最后返回disappear.
### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        length=len(nums)
        standard=[0]*length
        disappear=[]
        for i in list(set(nums)):
            standard[i-1]=i
        for i  in range(length):
            if standard[i]==0:
                disappear.append(i+1)
        return disappear
```