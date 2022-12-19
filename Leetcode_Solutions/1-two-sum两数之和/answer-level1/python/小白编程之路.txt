### 解题思路
最开始，是没有做出来，参照前辈们的，进行了梳理，这是需要求解两个数的和，并且找到这两个数的下标进行返回
1、我们采用python来写，里面有三个主要参数，两个数，目标值，两个数的下标，需要用index()来获取
2、这两个数存在与数组中，数组自然有下标，一般从0开始，我们要知道此数组的共个数是多长，用n表示，n来获取数组sums的长度
3、问题就简化为for循环，找到一个下标x从n中遍历，在循环里面，我们要知道目标值减去我们取得那个下标的数的差为多少为a
4、判断数a在不在数组中，在的话，我们就找到a所对应的下标，再此强调：要排除同一个位置上的数，否则就没有意义了
5、最后得到我们的下标x和a所对应的y下标了，程序结束。若前面条件不满足，重复此类步骤，以此类推。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #直接用目标值减去取出的数，看结果有没有在数组里面
        n = len(nums)
        for x in range(n):
            a = target - nums[x]
            if a in nums:
                y = nums.index(a)
                if x == y:
                    continue
                else:
                    return x,y
                    break  #程序终止的标志
            else:
                continue
```