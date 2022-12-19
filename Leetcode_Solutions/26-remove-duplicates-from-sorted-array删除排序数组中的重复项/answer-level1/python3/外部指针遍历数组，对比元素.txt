### 解题思路
解题图示
![image.png](https://pic.leetcode-cn.com/af8ff4515677970935cc58282c8f692fa0d58f1142faf990bfcfea104532d841-image.png)
此处撰写解题思路
相比较27题：移除元素
python3
1.利用一个外部指针res去遍历数组
for i in range(0,len(nums))
2.如果外部指针res下的元素不等当前遍历的数组元素则指针+1、将改元素赋值给+1后指针res的元素
res +=1
nums[res] = nums[i]
3.返回指针res，这里需要注意，指针是从0开始，但是返回要长度。则指针res+1

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        size = len(nums)
        if size==0 or size==1: return size
        res = 0
        for i in range(0,size):
            print(nums[i])
            if nums[res] != nums[i]:
                res +=1
                nums[res]=nums[i]
        return res+1       
```