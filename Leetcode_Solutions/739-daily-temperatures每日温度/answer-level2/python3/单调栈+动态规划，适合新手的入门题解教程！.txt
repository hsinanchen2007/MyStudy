通过这道题巩固了单调栈的应用。另外可以考虑动态规划的思想（其实就是把有结果的数据记下，便于后面比较时利用）。
作为单调栈的基础题，很容易写出解题代码。

单调栈讲的最好的我首推这篇博客：
https://www.cnblogs.com/grandyang/p/8887985.html
其中的插队领救济的比喻特别贴切。

题解里有人说单调栈需要从后往前遍历，个人认为完全没必要，设定等长的全0结果列表，顺序遍历就OK。

要选出右侧第一个更大的值，就要维护一个递减栈，元素从左向右挨个入栈，要入栈的元素先和栈顶比较，入栈元素更大，则弹出栈顶，直到入栈元素比栈顶小。

单调栈实际应用的核心在于，每次比较后弹出元素，再跟一步针对此弹出元素的业务操作，元素从左到右全部操作后，也就生成了答案。

解题代码：
```
class Solution:
    
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        
        stack = []  ## 初始栈（固定套路）
        rst = [0]*len(T) ## 初始结果列表（固定套路）
        
        for i, v in enumerate(T): ## 循环入栈（固定套路）
            
            while stack and stack[-1][1] < v: ## 维护单调栈（固定套路）
                    
                ii, _ = stack.pop() ## 维护单调栈（固定套路）

                rst[ii] = i-ii ## 业务代码（因题而异）

            stack.append((i,v)) ## 维护单调栈（固定套路）
            
        return rst ## 返回结果列表（固定套路）
```
下面是动态规划的思路，其实就是比较时利用已有结果跳着比较。

这就需要从后往前了，因为后面（对本题来讲是最后2个数的结果）是确定的，越往前越有跳跃。

参考评论区高赞回答，写了如下代码，不同之处见注释，原理相同，可能我的简洁一点。
```
class Solution:
    
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        
        rst = [0]*len(T)
        
        for i in range(len(T)-2, -1, -1):

            if T[i+1] > T[i]:                 
                rst[i]=1
                
            else:               
                ii = i+1                    
                while T[ii] <= T[i]:
                    if rst[ii] == 0: 
                        ii = i ## 这里这样赋值，是为了下面 rst[i] = ii-i 里 ii-i 值为0
                        break
                    ii += rst[ii]                    
                rst[i] = ii-i                    
                    
        return rst
```
结果最好也只击败20%+的python3，咋回事啊？
