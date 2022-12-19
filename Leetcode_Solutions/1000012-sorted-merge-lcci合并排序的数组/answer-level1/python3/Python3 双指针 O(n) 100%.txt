
### 思路

简单的双指针问题，$i$指向A待排序的末尾，$j$指向B中待排序的末尾。注意处理特殊情况即可。
因为至多只扫描m+n个元素，所以时间复杂度为$O(m+n)$。只储存$i$和$j$两个指针，所以空间复杂度$O(1)$。

![image.png](https://pic.leetcode-cn.com/9e7041c4267282df8da876eb24a54fc53cb34639fede170dfb8306f4690e4267-image.png)

### 代码


```python []
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m-1  # A最后一个元素位置
        j = n-1  # B最后一个元素位置
        index = m + n -1 # A中，等待插入的位置
        while j >= 0: # 如果B都插入A中了，那么排序结束
            if i < 0: # 如果A是空的
                A[0:j+1] = B[0:j+1]
                break
            elif A[i] > B[j]:
                A[index] = A[i]
                i -= 1 # 更新i，注意会出现i = -1的情况，表示A中的元素都被挪到末尾了
            else:
                A[index] = B[j]
                j -= 1 # 更新j
            index -= 1 # 更新插入的索引
```






