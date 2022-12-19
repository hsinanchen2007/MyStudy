### 解题思路
原来以为数字是可以任意组合的，后来看了题解才知道是要找划分点，不能改变数组的顺序，这才有了思路。
我觉得总体不难，就是遍历一遍数组，但是有几个需要注意的地方：
1、要设一个flag，之前没有等于等分值，才可以设这个index，不管是第一组还是第二组
2、第二组的时候，要注意判断i>first_part_index并且i<len(A)-1
3、当i已经来到了数组末尾，还没有找到等分点，要记得返回False，不要只管第一组和第二组如何判断

### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        remain = sum(A) % 3

        if remain != 0:
            return False
        else:
            one_part_sum = sum(A) / 3
            first_part_index = 0
            second_part_index = 0
            i = 0
            part_sum = 0
            flag = 0
            while i<len(A):
                part_sum = part_sum + A[i]
                if flag == 0 and part_sum == one_part_sum:
                    first_part_index = i
                    flag = 1
                if flag and part_sum == one_part_sum*2 and (i>first_part_index and i<len(A)-1):
                    second_part_index = i
                    return True
                    break
                if i==len(A)-1:
                    return False
                i=i+1

```