

### 1.暴力解法：time limit exceeded

拿到这个题，先想用暴力的解法先解决，但是超时了，就想怎么才可以优化复杂度

```Python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = []
        for i in range(len(T)):
            find = False
            for j in range(i+1, len(T)):
                if T[j] > T[i]:
                    res.append(j-i)
                    find = True
                    break
            if not find:
                res.append(0)
            
        return res
```


### 2.优化：转换思路，逆序考虑
如果是顺序考虑（类似上面暴力），那么就需要对每个温度，对它之后的温度依次遍历判断，增加了时间复杂度
那如果我们逆序判断呢，我能够从后往前的记录每一个比前一个温度更大一点点的温度：

```
[1,3,2,4]
从后往前考虑：
4，stack=[4]
2，发现stack里面顶层数据是4，比当前的大，那么找到了2最近的最大温度也就是4，然后将2append进去，stack=[4,2]
3，发现stack顶层数据是2，比当前小，那么这个完全不被考虑，于是将2pop掉，stack变为[4]，顶层数据也就是当前温度最近的最大温度
【因为不满足情况的已经被删掉了】然后将3append进去，stack=[4,3]
1，发现stack顶层数据为3，比当前大，那么是当前1的最近的最大温度
```

![image.png](https://pic.leetcode-cn.com/facc48f150edcfe1d56b2a63e51a571352d87e6c9bc9c2bebe148e8493ff6c62-image.png)

于是就可以写出代码：
```
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = [0] * len(T)
        stack = []
        
        for i in range(len(T)-1, -1, -1):
            while stack and T[stack[-1]] <= T[i]:
                stack.pop()
            if stack:
                res[i] = stack[-1]-i
            stack.append(i)
        return res
```


### 3.总结
如果遇到要找某个元素之后最近的满足情况的元素，可以优先考虑**逆序判断**，并且**用栈保存信息**

另：喜欢的人很优秀，那么一定要往心之所向靠近
不能成为绊脚石，要督促自己，持之以恒，以目前的智力水平和文化水平，坚持比一切都重要！！！