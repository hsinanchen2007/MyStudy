### 解题思路
![image.png](https://pic.leetcode-cn.com/ab76a64a47dbbdc70f313b006af8a18a6d511b620113ab9f5d2e9c1ec5f846e7-image.png)

- 在拿到这个题后,很自然的想到从左上角开始进行搜索,然后在找数组的其他元素,这样的方法很暴力,我相信面试官应该不会喜欢的
- 下面我们看看从右上角开始进行搜索会怎么样,给定如下数组:
![image.png](https://pic.leetcode-cn.com/30ab56e70637acdda3888e7ca5a112e24d890c8e24eba449c1dafaa20be629c7-image.png)
- 首先题目中给我们数组是递增的顺序的,我们要利用这个特性
1. 开始从右上角查找`target = 5`,第一行右上角的元素为`15`,`15>5`,我们知道题目给出是递增的,`15`所在的列的下面的元素都比`15`大,所以`5`不可能出现在`15`所在列的下面中,所以我们的搜索区域变成了:
![image.png](https://pic.leetcode-cn.com/71e575db894c2a1605cf0891ac4d17514d78776eeed9eb0af0d004e3e62d8538-image.png)
2. 继续看右上角的元素`11`,`11>5`,同样的操作,搜索区域变成:
![image.png](https://pic.leetcode-cn.com/1204c0e8c8f130d86a408667bca5e3df9b29cb94786bb9ee454e7a67f769b90f-image.png)
3. 继续看右上角元素`4`,`4<5`,所以应该舍弃这一行,寻找下面的,搜索区域变成:
![image.png](https://pic.leetcode-cn.com/40be16e10dc5f89f85d4144421da0754360f9dc78c0089b532aeeab857dcb5f2-image.png)
4. 此时右上角元素为`5 == target`,则查找成功.
- 时间复杂度`O(m+n)`,空间复杂度`O(1)`

### 代码

```python
class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        raw = len(matrix)
        col = len(matrix[0])
        def search(matrix, target, raw_, col_, raw):
            if raw_ >= raw or col_ < 0:
                return False
            if matrix[raw_][col_] == target:
                return True
            if matrix[raw_][col_] < target:
                return search(matrix, target, raw_+1, col_, raw)
            else:
                return search(matrix, target, raw_, col_-1, raw)
        
        return search(matrix, target, 0, col-1, raw)



```