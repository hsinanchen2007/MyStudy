####  方法1：前缀积乘以后缀积

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|    O(n)    |    O(n)    |

**基本思路：**

> 遍历求出前缀积和后缀积，再结合求出最终答案。

**代码：**

```python []
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 不要使用除法，就不能先算出总乘积，然后一个一个的除；
        # 如果要时间复杂度为O(n)，则必须想办法不做重复的乘法计算；

        # 从前到后计算前缀积，初始值为1，终点是倒数第二个元素
        pre = [1]
        for i in nums[:-1]:
            pre.append(pre[-1] * i)

        # 从后到前计算后缀积
        post = [1]
        for i in nums[-1:0:-1]:
            post.append(post[-1] * i)

        # output[i] = 前缀积乘以后缀积
        return [pre[i] * post[-(i + 1)] for i in range(len(pre))]
```

####  方法2：优化

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|    O(n)    |    O(l)    |

*备注：按照题目的意思，不考虑output数组的空间消耗*

**基本思路：**

> 先计算前缀积，然后有临时变量存储后缀积，降底空间复杂度。

**代码：**

```python []
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 不要使用除法，就不能先算出总乘积，然后一个一个的除；
        # 如果要时间复杂度为O(n)，则必须想办法不做重复的乘法计算；

        # 从前到后计算前缀积，初始值为1，终点是倒数第二个元素
        output = [1]
        for i in nums[:-1]:
            output.append(output[-1] * i)

        # 用临时变量来存储后缀积并且依次算出总乘积
        tmp = 1
        for i in range(len(nums) - 1, -1, -1):
            output[i] *= tmp
            tmp *= nums[i]
        return output
```