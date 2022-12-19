从**折线图**上来看思路能更清晰些。

# 思路
初始化一个栈stack，用来存储索引

遍历整个列表T，只需要**考虑两种情况**：
1.温度下降
  
如图中3-5天，如果温度比昨天的低，就把该天的索引存入stack;

2.温度上升

此时发现温度上升了，如图中第6天的情况，就依次将stack中存储的日期弹出比较，直到**空**或者**之前的温度更高**就退出比较；
图中72就在75和71之间，那么就可以更新第4、5天的结果；
最后将6添加到stack中。


![Inkedtijie_LI.jpg](https://pic.leetcode-cn.com/dc5d60bbf2ef3873e41ef6823613a05f7eb376d268e0df056af00485c8c25643-Inkedtijie_LI.jpg)

```
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        if len(T)==1:
            return [0]
        stack_index = [0]
        res = [0]*len(T)
        for i in range(1, len(T)):
            if T[i]>T[i-1]:
                while stack_index:
                    t = stack_index.pop()
                    if T[i]>T[t]:
                        res[t] = i-t
                    else:
                        stack_index.append(t)
                        break
                stack_index.append(i)
            else:
                stack_index.append(i)
        return res

```