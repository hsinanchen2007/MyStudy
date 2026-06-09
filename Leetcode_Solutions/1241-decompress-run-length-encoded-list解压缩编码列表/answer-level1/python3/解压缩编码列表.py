### 解题思路
判断列表需要分成几段，然后用python切片切出每段，对每段用一个循环解压

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        a = [] #存放切分只有的数组
        b = [] #存放返回结果数组
        d = len(nums) 
        c = d / 2 #判断nums数组分成几段
        e = 0
        while(c != 0): 
            a = nums[e:e+2] #每次切分出来的数组
            e += 2 #每次切分的数组段后移两位
            c -= 1 #切分次数
            for i in range(a[0]): #a[0]表示分段频次
                b.append(a[1])
        return b
```