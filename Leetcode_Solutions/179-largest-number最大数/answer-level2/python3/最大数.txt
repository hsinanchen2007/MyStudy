想法：取数组里的最大数字，将所有的数字进行拓展到与该数字一样多位的程度，然后对数字进行排序组合。
做法：首先取数组里的最大数字的位数，将其他数字进行拓展，拓展位上的数字为该数字第一位或最后一位的较大值，转换成一个（原始数值，拓展后的数值）的二元组形式，
对该序列的拓展数字进行排序后将原始数字进行连接即可，比如824与8247的排序就是824拓展成8248然后比较8247与8248，连接824与8247。
```
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        max_length = len(str(max(nums)))
        sequence = []
        zeros_num = nums.count(0)
        if zeros_num == len(nums):
            return '0'
        else:
            for num in nums:
                sequence.append((num,int(str(num)+str(max(str(num)[-1],str(num)[0]))*(max_length-len(str(num))))))
            sequence = sorted(sequence,key = lambda x:(x[1],x[0]),reverse=True)
            res = ''
            for seq in sequence:
                res = res + str(seq[0])
            return res
```
