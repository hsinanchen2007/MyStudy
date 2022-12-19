拿到这个题最开始想到的是我拿一个变量每次保存最新的最小值，但是这有个问题，就是这个栈会被pop，那万一最小值被pop了怎么办，我怎么拿得到之前的最小值呢，如果拿两个变量保存次最小值呢，那万一次最小值也被pop了呢。。。这就尴尬了
但是这也是考虑的思路，那我把每一次的最小值都保存下来呢？
我把每push一个值的时候都保存当前最小值，放在一个数组里面，然后就算pop掉了一个值，我还能找到之前的最小值，因为都在数组里了，
于是就可以考虑用一个辅助栈来完成。

```
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        # 辅助栈，保存每次的最小值
        self.min_stack = []
        

    def push(self, x: int) -> None:
        self.stack.append(x)
        '''需要判断，辅助栈里需要存放的是最新的最小值
        如果辅助栈里面没值，或者之前的最小值还比我新push的值更大了，那我肯定是存放当前的这个push值作为此次操作的最小值'''
        if not self.min_stack or self.min_stack[-1] > x:
            self.min_stack.append(x)
        else:
            # 如果push的值比之前的最小值大，那么此次操作的最小值还应该是之前的最小值
            '''这里需要注意的就是要存放的值是辅助栈的栈顶元素，而不是原始数据栈的栈顶元素，不要写错了'''
            self.min_stack.append(self.min_stack[-1])
        

    def pop(self) -> None:
        if self.stack:
            self.min_stack.pop()
            return self.stack.pop()
        

    def top(self) -> int:
        if self.stack:
            # 返回原始数据栈的栈顶元素
            return self.stack[-1]
        return None

    def getMin(self) -> int:
        if self.min_stack:
            # 返回辅助栈的栈顶元素
            return self.min_stack[-1]
        return None

```

![image.png](https://pic.leetcode-cn.com/ffee4ab9a1d5d5f83276ac153b071e9a723b40756a2caa36470021c417ddc79f-image.png)
