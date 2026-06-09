Python3 双百，这是一个不用回溯和深搜的解决方案，用一个二进制数字i去模拟所有可能的二进制取和不取的情况。因为遍历是二进制顺序连续的，所以只要比较当前的result和上一个result是否相同就行了。
详见注释
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        # 一共有2^n次方种的选法，不考虑重复
        dec = 2**len(nums)
        result = list()
        # 对于每一个选法
        for i in range(dec):
            # 注意这里要用倒序，因为我们是从前往后挨个决定要不要，和二进制进位相反
            tmp = zip(list(bin(i)[2:])[::-1], nums)
            # 如果对应位置是1，就取
            this_result = [j for i,j in tmp if i == '1']
            # 判断和上一个已经收入囊中的result是否一样
            if not result or this_result != result[-1]:
                result.append(this_result)
        return result
```
