### 解题思路
构建一个空数组，然后每次探索到新值的时候如果比最大值还大就插到最后，如果不是的话就替换掉前面比他大的最小的那个数，而二分法就是用在这个查找位置的地方。

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        sublen = [nums[0]]
        for num in nums:
            if num > sublen[-1]:
                sublen.append(num)#添加更大的
            else:
                i = 0
                j = len(sublen)-1 #i为小指针，j为大指针
                m = (i+j)//2
                while j>i:
                    print(m)
                    if sublen[m] >= num: 
                        j = m
                    else :
                        i = m + 1
                    m = (i+j)//2
                    print(i,j)
                sublen[i] = num
            print(sublen)
        return len(sublen)

        
```