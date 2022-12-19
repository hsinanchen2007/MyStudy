'''双指针
首先对列表排序
i=0, j=1
第一种最简单的情况就是，[j][0]>[i][1]  直接压入第i个元素，i移到j的位置，j+1
第二种情况，[j][1] <= [i][1]  因为[j][0]肯定大于等于[i][0],所以当[j][1] <= [i][1]，保留第i个元素的范围不变，j+1
第三种情况，就是[j][0]<=[i][1] and [j][1]>[i][1],直接改变[i][1]扩大第i个元素的范围,j+1
第一种是属于不可合并的情况，所以同时向后移动两个指针；后两种是可以合并的情况，固定第一个指针，移动第二个扫描指针。
最后还要考虑最后一个元素，如果最后一个元素属于第一种情况，在while循环内压入倒数第二个数，循环后压入最后一个数
第二三种情况属于被合并的，直接在循环外压入合并的元素
'''
![image.png](https://pic.leetcode-cn.com/e3cfb9b7a60bb3499608429cfc3ac953fb499af2e9dc5e3ade001d903e6d9b5a-image.png)

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        i = 0; j = 1
        res = []
        if n==0 or n==1:
            res = intervals
            return res

        intervals.sort()
        while(j<n):
            if intervals[j][0] > intervals[i][1]:
                res.append(intervals[i])
                i = j
                j += 1
            elif intervals[j][1] <= intervals[i][1]:
                j += 1
            else:
                intervals[i][1] = intervals[j][1]
                j += 1
        res.append(intervals[i])      
        return res
