这样的简单题目，当然是追求极简了：
```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:        
        return [x for x in set(nums1)&set(nums2) for _ in range(min(nums1.count(x),nums2.count(x)))]
```
然后看进阶，若排序好，当然是双指针了：
下面是一个不一样的双指针，优点是修改原数据使内存占用越来越少
```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:         
        nums1.sort()
        nums2.sort()
        rst = []
        try:
            while True:
                i,j=nums1.pop(),nums2.pop()
                if i==j: rst.append(i)
                elif i>j: nums2.append(j)
                else: nums1.append(i)
        except:
            return rst
        # 执行用时 :60 ms, 在所有 python3 提交中击败了93.12%的用户
        # 内存消耗 :13.8 MB, 在所有 python3 提交中击败了5.06%的用户  
```
如果nums1 的大小比 nums2 小很多，嗯~方法2更好。
如果 nums2 的元素存储在有限内存的磁盘上，那就先把nums1的元素组成字典`{i:nums1.count(i) for i in set(nums1)}`，再将nums2切分为内存允许的几块（假设为subs），每一块加载入内存，与上述字典求交集，有交集则将对应的value减1，求完交集后从内存中删除，遍历完所有sub后，取字典中value>0的key，组成新list即结果。
其伪代码如下：
```
visited1 = {i:nums1.count(i) for i in set(nums1)}
subs = split(nums2,n) ## split 是切分函数，n是分成n份
对每个sub导入内存后执行以下操作：
    for j in sub:
        if visited1.get(j):
            visited1[j] -= 1
删除此sub，导入下一个sub，重复上述过程。

rst = [key for k,v in visited1.items() for _ in range(v)] ## 用遍历后的字典，每个key重复value次，组成最后结果
```


