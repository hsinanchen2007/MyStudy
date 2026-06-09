### 解题思路
    ex： 输入：target = 9
         输出：[[2,3,4],[4,5]]

    流程：
        ①从1开始，[1,2]、[1,2,3]、[1,2,3,4]不断的添加后续数字，直至大于等于target
        ②在[序列]大于target的基础上，开始抛弃首位的数值即[2,3,4]
        ③添加后续数字[2,3,4,5],抛弃首位的数值即[3,4,5]……寻找其他解

    补充：
        题目要求输出连续的序列，且序列中的数应至少为2个。
        以9为例，只需要考虑[1,2,3,4,5]序列其中的子序列皆可，因为[4,5]已是最大子序列。
        同理，对于11，考虑范围为[1,2,3,4,5,6]。对于12，考虑范围为[1,2,3,4,5,6]

    实际效果：
        
![下载 (9).png](https://pic.leetcode-cn.com/becc2262f8bae039f119b2d969de0655caa29101d0ba9a49c3513c2f07a9c667-%E4%B8%8B%E8%BD%BD%20\(9\).png)


### 代码

```py
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        start = 1
        flag = []             #考虑范围中子序列滑窗
        while start < target:
            if sum(flag) < target:
                flag.append(start)
                start += 1
            elif sum(flag) > target:
                if len(flag)==2:    #当超出最大子序列时，结束循环。以9为例，当出现[5,6]时，结束循环
                    break     
                flag = flag[1:]
            else:
                flag.append(start)
                start += 1
                ans.append(flag[:-1])
        return ans
```