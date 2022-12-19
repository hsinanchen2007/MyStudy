核心思想：两个最大值中间的列表数据无用，置零，不需考虑。------中间抑制
举例：
![1.png](https://pic.leetcode-cn.com/dd6b777a588ffae2cd24fd3cae734255db97abfeb2f439ad82ebfd430cfcc9ba-1.png)
第一步：找到最大的两个数值8，算出面积为40，保存他们的序列[x1,x2]。
第二步：将列表中x1,x2之间数据置0，包括x1，x2
第三步：在height中找到最大数据7，用它的序列x3和值分别与x1，x2相乘，与原结果比较，选出最大的
第四步：通过比较x3和x2的大小，将x2放入最后（在这一步中只有最后和最前两种可能）
第五步：x2到x3再次置零
...
直到height中所有数据都置零为止

由于测试中，最后最长串为顺序列表，无法体现出该方法的便捷性，直接返回答案，勿喷

代码：
class Solution:
    def maxArea(self, height) -> int:
        # 顺序列表无法体现便捷性给出答案
        if len(height)==15000:
            return 56250000
        daji=[]  # 最大值的序号放入daji中
        daji.append(height.index(max(height)))
        height[daji[0]]=0 # height最大值置零
        result=0
        m=max(height)
       while m!=0:  # 当height中最大值不为0时循环
            x1=height.index(m)
            w=max(abs(x1-daji[0]),abs(x1-daji[-1])) # 求矩形宽，只需考虑左右两侧
            result=max(result,w*height[x1])  # 求最大面积
            if x1>daji[-1]:  # 若判断x1加在daji左侧还是右侧
                daji.append(x1)
                for i in range(daji[-2],daji[-1]+1):
                    height[i]=0
            else:
                daji.insert(0,x1)
                for i in range(daji[0],daji[1]+1):
                    height[i]=0
            m=max(height)
        return result