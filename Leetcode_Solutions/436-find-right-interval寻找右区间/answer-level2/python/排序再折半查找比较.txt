```
class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        if len(intervals) == 1:
            return [-1]
        my_dict = {}
        my_dict_2 = {}
        for i, v in enumerate(intervals):
            my_dict[v[0]] = i
        
        new_l = sorted(intervals, key=lambda x: x[0])

        for i in range(len(new_l)-1):
            j = len(new_l) - 1
            tmp = -1
            left = i
            right = j
            while 1:
                if new_l[j][0] >= new_l[i][1]:
                    tmp = my_dict[new_l[j][0]]
                    right = j
                else:
                    left = j
                j = (left + right) / 2
                if j == left:
                    break

            my_dict_2[new_l[i][0]] = tmp
        
        my_dict_2[new_l[-1][0]] = -1

        return [my_dict_2[v[0]] for v in intervals]
```
排序再折半查找比较
执行用时 :376 ms, 在所有 python 提交中击败了75.00%的用户
内存消耗 :17.9 MB, 在所有 python 提交中击败了100.00%的用户
