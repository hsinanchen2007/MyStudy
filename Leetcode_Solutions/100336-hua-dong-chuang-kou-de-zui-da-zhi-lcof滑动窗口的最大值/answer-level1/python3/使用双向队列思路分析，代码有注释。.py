### 解题思路
主旨：构造双向队列，保证队列头元素为当前窗口中最大值，同时将未来可能成为某窗口中最大值的候选数保留在队列中。
重点：
point.1:从左往右扫描nums，每个新元素都可能今后成为某窗口中的最大值，因此每个新来的元素都必须入队；
point.2:当双向队列头元素和当前即将入队的新元素下标距离大于等于k，则去掉双向列表的头元素。
point.3:某个新元素入队前，需从尾到头检查队列中已有元素，若小于新元素则pop掉它，因为它不可能成为某窗口的最大元素。

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue2 = []#双向队列
        rec = len(nums)*[0]#
        for i in range(len(nums)):
            if not queue2:
                queue2.append(i)
                rec[i] = nums[queue2[0]]
                continue
            
            if i-queue2[0]>=k:#检查是否有滑出窗外的数字[point.2]
                queue2.pop(0)
            #下面queue不会为空
            while queue2 and nums[queue2[-1]] < nums[i]:
                #如果有候选数小于本数，则这些候选数不会成为某段max[point.3]
                queue2.pop()
            queue2.append(i)#每个新来的数都可能成为今后的最低值，都必须入队[point.1]
            rec[i] = nums[queue2[0]]#记录当前位置最大值
            #print(rec)
        return rec[k-1:]

```
### 时间复杂度
看似for循环进行了n次，每次最大要对k长的队列扫描。然而换个角度来看，实际上每个元素都入队一次，每个元素也最多出队一次（有的元素可能不会出队），因此每个元素都有至多2次操作。因此时间复杂度：O(n)

### 如有不妥，欢迎交流！