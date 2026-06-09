![image.png](https://pic.leetcode-cn.com/b9da4e227bb2e38138e10681b9781dd9f4a7df5447a95272c7b2ce2bf13580f6-image.png)

经典的堆栈问题:
1.遇到左括号就压栈。
2.遇到右括号就与栈顶元素比较是否匹配（通过字典的方式），匹配则出栈。
3.根据栈的长度判断是否完全匹配。

这里需要注意字典的建立方式（key，value的循序）