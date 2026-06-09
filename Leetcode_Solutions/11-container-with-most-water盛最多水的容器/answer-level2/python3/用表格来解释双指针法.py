![2.png](https://pic.leetcode-cn.com/771626b9a98827348239111b90fac766591a414b7d8c1ffe21481df64899f7ad-2.png)


用i,j表示前后取的2条线段,用S(i,j)表示其面积，普通搜索算法需要枚举全部的(i,j)组合,如图示:需要计算的是斜线右上部分的区域.
官方题解中说的双指针的关键步骤："**指向较短线段的指针向较长线段那端移动一步**" ，说明如下:
以第一步为例: i=0 高为1, j=8 高为7, 需要i移动1步，这里仔细观察可以看出，i移动以后,相当与我们舍弃计算了所有的i=0的这一行，即为在图示中*打叉*的位置. 可以看出这些位置代表的状态不可能比 (0, 8) 的结果好, 因为其构成的矩形区域高小于等于h[i], 长度比(0,8)的小。
可以得到一个结论，"**关键步骤**"相当于一种剪枝策略，可以把不是最优解的状态去掉.
另外还有一个细节，当H[i] == H[j], i和j高相等的情况时可以同时将i和j都移动一步, 速度更快


```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        i, j = 0, len(height)-1

        while i<j:
            w = j-i
            h_i, h_j = height[i], height[j]

            if h_i <= h_j:
                area = w * h_i
                k = i+1
                while k < j and height[k] < h_i:
                    k += 1
                i = k
                
            if h_i >= h_j:
                area = w * h_j
                k = j-1
                while k > i and height[k] < h_j:
                    k -= 1
                j = k
            
            maxArea = max(area, maxArea)
            
        return maxArea
```
