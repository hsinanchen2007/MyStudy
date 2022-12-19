### 解题思路
执行用时 :516 ms, 在所有 Python 提交中击败了11.03%的用户
内存消耗 :11.8 MB, 在所有 Python 提交中击败了100.00%的用户
暴力求解：
    最大不能超过target的一半加一
    从1开始，依次右移开始值，求解最小的符合条件的值，找到、找不到都将开始值右移

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        n=target//2+1
        i=1
        result=[]
        while i <= n:
            j=i
            mysum=0
            mylist=[]
            while j <=n:
                mysum=mysum+j
                if mysum<target:
                    mylist.append(j)
                    j=j+1
                    continue
                elif mysum==target:
                    mylist.append(j)
                    result.append(mylist)
                    break
                else:
                    break
            i=i+1
        return result



```