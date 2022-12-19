### 解题思路
新建一个列表，用于存储当前元素及之前对应的最小元素作为“132”中的“1”
新建一个栈，用与存储“132”中的“2”


1. 记录下从数组开始到当前位置的最小元素
2. 新建一个栈，把数组最后一个元素放入栈里
3. 从倒数第二个元素开始，逆序遍历数组
4. 如果当前元素之前的最小值大于等于栈里的最顶层元素，删除栈顶元素直至栈顶元素大于当前元素，如果栈被删空了，就把当前元素放入栈5. 中，然后continue
5. 到了这一步，说明当前元素之前的最小值小于栈顶元素，然后判断当前元素是否大于栈顶元素。如果是，返回True；如果不是，把当前元素放入栈，continue
6. 如果数组遍历结束也没有返回True，就返回False


代码有点长，看起来有点丑
![TIM截图20200118210827.png](https://pic.leetcode-cn.com/317d48c914627cea7a57ff1bfdb3280b6bb6704d8c4255c64f6abfe160a453d1-TIM%E6%88%AA%E5%9B%BE20200118210827.png)


### 代码

```python3
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        min_num = nums[0]
        min_list = []
        res = []
        for i in nums:
            if i <= min_num:
                min_list.append(i)
                min_num = i
            else:
                min_list.append(min_num)
        for i in range(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                res.append(nums[i])
                continue
            try:
                while res[-1] <= min_list[i]:
                    del res[-1]
            except IndexError as e:
                res.append(nums[i])
                continue
            if nums[i] <= res[-1]:
                res.append(nums[i])
                continue
            else:
                return True
        return False
            
```