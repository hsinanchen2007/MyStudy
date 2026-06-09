### 解题思路

主要是自定义比较函数, 一开始设计的cmp太复杂了!

### 代码

```python3
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        def mycmp(x, y):
            # while x[0]==y[0] and (x[1:] or y[1:]):
            #     if not x[1:]:
            #         x = x[1:]
            #     if not y[1:]:
            #         y = y[1:]
            # return 1 if int(x[0])>int(y[0]) else -1
            # return int(x+y)>int(y+x) # cmp必须要返回1,0,-1, 分别代表大于,相等,小于, 所以这样写不行, 因为只会返回1和0
            return int(x+y)-int(y+x)

        nums = list(map(str, nums))
        nums = sorted(nums, key=cmp_to_key(mycmp), reverse=True)

        # return ''.join(nums) # 因为有[0,0]]
        return str(int(''.join(nums)))
```

这个代码只要20ms,学一下
```
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # 题目采用了一种比较6的方式，采用判断a+b是否比b+a大的方式
        #  倘若a+b>b+a b+c>c+b ==> a+c>c+a
        # 因此只需要比较a+b>b+a即可，采用化str相加的方式
        largest_num = ''.join(sorted(map(str, nums), key=compare))
        return '0' if largest_num[0]=='0' else largest_num # 这个做法怎么影响速度
        
        
class compare(str): # 定义成类更快?
    def __lt__(x, y):
        return x+y>y+x
```