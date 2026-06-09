### 解题思路
按位操作：
首先根据 异或运算的结合律，得到那两个不相同的数字的异或运算结果，然后找到这个结果中，为1的位置，在该位置上，说明这两个数对应的二进制的那一位不同；找寻一个匹配模板，使得这个模板在这个位置为1，其余位置的数为0，然后nums中的所有的数与这个模板进行与运算，如果，其中（1）这两个中肯定有一个数在该位置上为1，另一个数在该位置上为0，根据和模板的与运算的结果，就能将两个数进行区分，分到两个不同的组里
（2）其余的数，彼此两两相同，即，这两两相同的任意一个数，和模板进行与运算之后的结果都一样，都会被分到同一组里
（3）分完组的组内成员再次进行异或运算，便能消除掉两两相同的，只剩下各自不同的
### 代码

```python
class Solution(object):
    def singleNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #Hash
        # self.Hash={}
        # for per in nums:
        #     if str(per) in self.Hash:self.Hash.pop(str(per))
        #     else:
        #         self.Hash[str(per)]=None
        # return [key for key in self.Hash.keys()]

        #按照位运算
        YiHu=A=B=0
        for per in nums:
            YiHu^=per
        #找到这两个不相等的数的异或结果的第一个非0位置
        H=1
        while YiHu&H==0 :H<<=1
        for per in nums:
            if H&per==0:
                A^=per
            else:
                B^=per
        return [A,B]




```