解法思路很简单，就是来一个数字就拼接一次
例如 "23" 这个例子
初始化 结果为 ""
先取出 2 对应的列表 [a b c], 用 "" 和 a b c 分别拼接并加入结果 得到  [a b c]
再取出 3 对应的列表 [d e f], 分别用a b c 和 d e f 拼接并加入结果得到[ad ae af bd be bf cd ce cf]

![image.png](https://pic.leetcode-cn.com/a0ddb15837de076c058e64d4ffed7490afef9391810e7b16266725dada97c17b-image.png)
