### 解题思路


### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        """单调单调递减的栈，通常我们用于求取数组中某元素之前第一个大于它的数"""
        if len(height)<=2: return 0
        tmp=[height[0]]  #是一个非严格单调递减的栈
        ans,i=0,1        #ans记录结果，i表示height数组索引
        while i<len(height):
            while tmp and height[i]>tmp[-1]:   #如果新元素大于栈顶元素，为维护单调递减，我们做以下操作
                if height[i]>=tmp[0]:      #如果该柱子大于栈中最大的柱子，则说明到该柱子之前蓄的水影响不了后面了
                    ans+=tmp[0]-tmp.pop()  #出栈并且求水量
                else:                    #否则如果没有超过栈中最大元素，那么栈中至少有个元素比新元素大        
                    j=len(tmp)-1         #记录第一个比新元素大的位置，
                #而在i，j两者之间的都是可以接水的，记录节水的大小，注意这里不能出栈，因为加入后面又来了更大的元素，那么出栈部分的水就统计掉了
                    while tmp[j]<height[i]:
                        ans+=height[i]-tmp[j]
                        tmp[j]=height[i]    #计算了他们到目前为止能装的水是多少就把它们的值添加到height[i]这么多
                        j-=1
            tmp.append(height[i])        
            i+=1
        return ans




```