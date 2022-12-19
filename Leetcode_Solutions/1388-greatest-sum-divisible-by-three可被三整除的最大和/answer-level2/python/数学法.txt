### 解题思路

数组中数字无非三种，除3余0，除3余1，除余2。除3余0的数字的和仍除3余0，所以应全部采纳。然后将除3余1，除3余2的数字分别从小到大排序。
则假设从大到小采纳n个1，则最多可以从大到小采用f(n)个2，f(n)是可以从n中算出来的。举个例子，假设总共5个1，5个2，如果采用4个1（等价于1个1），则最多可以采用4个2（等价于1个2）。另外，遍历全部的n是不必要的。假设总共有10个1，则 7<n<11,因为如果n=7，则剩下的3个1又可以组成一个3，相悖。

### 代码

```python
class Solution(object):
    def maxSumDivThree(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum_3 = 0
        mods_2 = []
        mods_1 = []
        for i in nums:
            if i%3 == 0:
                sum_3 += i
            if i%3 == 2:
                mods_2.append(i)
            if i%3 == 1:
                mods_1.append(i)

        mods_1.sort()
        mods_2.sort()

        l_1 = len(mods_1)%3
        l_2 = len(mods_2)%3

        sum_12 = 0
        if len(mods_1) == 0:
            sum_12 = sum(mods_2[l_2:])
        for i in range(min(len(mods_1),2)+1):
            tmp_1 = (len(mods_1)-i)%3
            if tmp_1 == 0:
                start_2 = l_2
            elif tmp_1 == 1:
                if l_2 == 0:
                    start_2 = 2
                else:
                    start_2 = l_2-1
            elif tmp_1 == 2:
                if l_2 == 2:
                    start_2 = 0
                else:
                    start_2 = l_2+1
            if len(mods_2)>=start_2:
                tmp_sum = sum(mods_1[i:])+sum(mods_2[start_2:])
            else:
                tmp_sum = 0
            if sum_12 <= tmp_sum:
                sum_12 = tmp_sum
        out = sum_12+sum_3

        return out
                    


                            
                        
                   

                        
            
        


```