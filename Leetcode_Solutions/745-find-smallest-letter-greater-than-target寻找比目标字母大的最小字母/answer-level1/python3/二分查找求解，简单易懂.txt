### 解题思路
采用二分查找变更区间
存在两种情况：
（1）当目标值大于等于mid值（中间值），改变区间的左边界值
（2）否则，改变区间的右边界值
最终如果遍历所有字符都没有找到满足要求的值，则输出第一个字符

### 代码

```python
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        left,right=0,len(letters)-1
        while left<=right:
            mid = left + (right-left)//2
            if letters[mid]<=target:
                left=mid+1
            else:
                right=mid-1
        return letters[left] if left<len(letters) else letters[0]

```