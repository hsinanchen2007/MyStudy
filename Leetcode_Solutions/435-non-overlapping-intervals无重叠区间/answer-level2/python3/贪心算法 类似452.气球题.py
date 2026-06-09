**思路**

其实只需判断终点的位置，跟452题，引爆气球的思路类似，可以说一毛一样
看不懂我的解释的可以看这个[官方解释](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/solution/yong-zui-shao-shu-liang-de-jian-yin-bao-qi-qiu-b-2/)


1、按终点排序；
2、另end=第一个区间的终点，遍历比较，
      * 第二个区间的起点小于前一个区间终点时，需删除第二个区间 result +=1；
      * 第二个区间起点大于等于前一个区间终点时，不需要删除，end = 第二个区间的终点；


``` python
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        ##思路
        ##1、按终点排序  2、第二个数的起点小于第二个的终点时，删除第二个区间
        ## 类似于射气球的题目
        intervals.sort(key = lambda x:x[1])
        print(intervals)
        result = 0
        if len(intervals) <=1:
            return(0)
        end = intervals[0][1]
        for i in range(1,len(intervals)):
            if intervals[i][0] < end:
                result +=1
            else:
                end = intervals[i][1]
        return(result)
```
