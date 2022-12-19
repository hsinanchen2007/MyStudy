

![提交记录](https://pic.leetcode-cn.com/472e29b6794bf942f09800d2ee816ba65bf7aaa817d460e3302ab70e89db6e8d-image.png)

首先，如果你完全看不懂我在说啥，不是你的问题，是我解释的还不够到位。

你可以先看496题，进而做一下503题，这两道做完了，这道题我不讲你也就会了。

下面解释一下这道题，这道题用栈做非常巧妙，不仅速度快，而且过程很简洁，有一种稀里糊涂就把结果算出来了的感觉。这道题的关键是：**用栈记录的是list中元素的index**，而不是list中元素值本身。后面在操作stack时，操作的都是index，这样就能实现把res中对应位置给替换掉的效果。

看代码：

```python3 []
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        l = len(T)
        stack = []    #这里定义一个栈就不用说了
        res = [0] * l   # 这里是最后要返回的result，因为题目中说没有匹配的就返回0，
                        # 所以这里初始化一个全是0的list，然后把那些有匹配的替换掉即可。

        for idx, t in enumerate(T):  # 下面是关键
            while stack and t > T[stack[-1]]:  # 当stack为空时，运行stack.append(idx)，则stack=[0]
                                                # 然后仅当遍历元素 t 小于stack顶端的值时append进去，
                                                # 这会导致stack中idx代表的元素是单调递减的，
                                                # 如果此时遍历到一个 t，大于stack顶端的值，那这个t就是离stack
                                                # 顶端值最近的那个大值。
                res[stack.pop()] = idx-stack[-1] # 然后pop出来，还是要注意stack.pop出来的是idx，这样res这
                                                 # 一串0里对应位置的0就会被替换成应有的值。                                        
                                                # 再进入while循环判断t和stack.pop后的新的顶端值哪个大。
                                                # 如此反复。
            stack.append(idx)
        return res
```

大概过程就是这样，如果实在不能理解，那可以先把这个方法直接记脑子里，待以后慢慢理解。
总的来说，这题充分利用了栈先进后出的特性，进去时一个比一个小（例如[5,3,1]），pop时自然就一个比一个大，t就和这一个比一个大的数比较，最后得出结果。
（例如t = 4，那么 4 > 1,pop掉，记录在res中；再比较4和3，发现4也大于3，那就同样pop掉，同样记录在res中；再比较4和5，发现4小于5，那就不pop了，把 4 append进去，stack就变成了[5,4]如此重复。）

以上





