#### **2.分发饼干**
    假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。*
       
#####  **注意**    

    你可以假设胃口值为正。
    一个小朋友最多只能拥有一块饼干。
#####  **示例**       
```
输入: [1,2,3], [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
```
#####  **我的思路** 
```
两个list排序，从大到小，用饼干去适配小孩的胃口，适配就数量加一，不适合就后移一个小孩，继续适配
```
```
class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort(reverse=True)
        s.sort(reverse=True)
        g_index, s_index, result = 0, 0, 0

        while g_index < len(g) and s_index < len(s):
            if s[s_index] >= g[g_index]:
                result += 1
                s_index += 1
                g_index += 1
            else:
                g_index += 1

        return result
```

*   问题
`花时间太长了，需要优化`
稍微优化一下
```
class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g_ind=s_ind=0
        g.sort()
        s.sort()
        while g_ind<len(g) and s_ind <len(s):
            if g[g_ind]<=s[s_ind]:
                # result +=1
                g_ind +=1
                # s_ind +=1
            # else:
            #     s_ind +=1
            s_ind +=1
        return g_ind
```

