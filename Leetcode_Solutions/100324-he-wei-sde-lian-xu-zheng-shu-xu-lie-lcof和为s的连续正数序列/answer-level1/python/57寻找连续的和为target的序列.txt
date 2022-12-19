### 解题思路
原来一点思路都没有，看了滑动窗口的题解后恍然大悟。
原来用了回溯的方法，令i和j都从左往右滑动，结果超时了
后来再仔细看一遍别人的题解，发现j不能往后退，只能i往前走
要注意的有:
1、i<=target//2
2、先sum=sum+j 再j=j+1

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        # result = []
        # target_list=[]
        # for k in range(1,target):
        #     target_list.append(k)
        # i = 0
        # while i<target:
        #     j = i+1
        #     while j<=target:
        #         j = j + 1
        #         sum_sublist = sum(target_list[i:j])
        #         if sum_sublist == target:
        #             result.append(target_list[i:j])
        #             i = i + 1
        #             break
        #         if j == target:
        #             i = i + 1
        #     if i == target - 1:
        #         break
        # return result


        result = []
        i = 1
        j = 1
        sum_sublist = 0
        while i<=target//2:
            if sum_sublist < target:
                sum_sublist = sum_sublist + j
                j = j + 1
            elif sum_sublist > target:
                sum_sublist = sum_sublist - i
                i = i+1
            else:
                result.append(list(range(i,j)))
                sum_sublist = sum_sublist - i
                i = i+1

        return result

            


```