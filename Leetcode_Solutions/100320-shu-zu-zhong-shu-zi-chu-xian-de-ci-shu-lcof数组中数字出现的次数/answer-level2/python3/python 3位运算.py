### 解题思路
位运算

### 代码

```python
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        #一个数和0异或是其本身，和本身异或为0
        n1,n2=0,0
        #(1)计算整个数组的异或值
        xor_num=0
        for num in nums:
            xor_num^=num
        #（2）寻找xor_num从右数第一个为1的位置
        mask=1
        while xor_num&mask==0:
            mask<<=1
        #(3)分组求解两个只出现一次的数字n1,n2
        for num in nums:
            if num&mask==0:
                n1^=num
            else:
                n2^=num
        return [n1,n2]



```