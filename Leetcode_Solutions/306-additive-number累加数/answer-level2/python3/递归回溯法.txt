# 解题思路
1. 首先根据题目在脑子里思考搜索树应该是怎么样的，我的如下图所示（当然图中的例子，使用深度优先遍历就已经得到解了，其他的几个节点只是举个例子）：
![未命名文件.png](https://pic.leetcode-cn.com/fac3f1a01acac769f56f140bad76782f1aaf27a0c7ffa24dfb0bf4d2cbfb070f-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)
2. 判断合法条件（合法即找到解）：
    1. 字符串中的数字均考虑过，即已走到搜索树的叶结点
    2. 符合约束函数：数字不得以“0”开头，“0”本身除外
    3. 是否为累加的：前两个数字相加等于当前的数字
3. 判断是部分解的条件（如果是部分解就进入下一层）：
    1. 字符串中的数字未全考虑过，即未走到搜索树的叶结点
    2. 同 2.2
    3. 同 2.3

# 算法执行
1. 字符串长度小于 3 直接返回 False
2. 初始化前两个数字为 a, b = ''
3. 开始递归，除了必需的变量，还需要一个字符串剩余长度（rest_len），方便在剩余的字符串中计算当前的数字
    - 比如在上图中，当前所在层数为 3（即第四层），我们需要计算当前节点的数字。已知 rest_len = 3，str_len = 6，则取出当前节点的数字为 num[6 - 3: 6 - 3 + span]，span 为取数字的跨度，从 1 开始，所以就取到了数字“3”。在图中可以看到此层还有一个节点“35”，如果 span = 2，我们就取得了 num[6 - 3: 6 - 3 + 2]
        + array[i: j] 在 python 中意为**取出在 array 中从 i 到 j 的元素**（遵从包头不包尾原则）
    - rest_len 另一个用途是计算 span，比如“112358”，rest_len = 3，那么我们只能选择取[3, 35 ,358]。我们从 1 遍历到 rest_len + 1，刚好可以得到可取的 span = [1, 2 ,3]
4. 使用 rest_len 计算当前数字 c
4. 合法则返回 True
5. 部分则进入下一层
    - 由于第 0 层和 第 1 层无法进行比对，所以碰到此两层也可进入下一层

# 代码
```
class Solution:
    def __init__(self):
        self.success = False
        self.str_len = -1

    def isAdditiveNumber(self, num: str) -> bool:
        str_len = len(num)
        if str_len < 3:
            return False
        self.str_len = str_len
        # 开始递归
        self.rec(num, str_len, 0, '', '')
        return self.success

    def rec(self, num_str, rest_len, current_layer, a, b):
        # 遍历所有可能的跨度
        for span in range(1, rest_len + 1):
            if not self.success:
                # 获取当前的数字
                start = self.str_len - rest_len
                c = num_str[start: start + span]
                # 是否合法，合法则找到解，直接退出程序
                if current_layer > 1 and self.is_legal(rest_len, span, a, b, c):
                    self.success = True
                    return
                # 是否为部分解，是则进入下一层
                elif current_layer <= 1 or self.is_partial(rest_len, span, a, b, c):
                    self.rec(num_str, rest_len - span, current_layer + 1, b, c)

    def is_legal(self, rest_len, span, a, b, c):
        return rest_len - span == 0 and self.constraint_func(a , b, c) and self.is_additive(a, b, c)

    def is_partial(self, rest_len, span, a, b, c):
        return rest_len - span != 0 and self.constraint_func(a , b, c) and self.is_additive(a, b, c)

    def constraint_func(self, a, b, c):
        return not (len(a) > 1 and int(a[0]) == 0 or len(b) > 1 and int(b[0]) == 0 or len(c) > 1 and int(c[0]) == 0)

    def is_additive(self, a, b, c):
        return int(a) + int(b) == int(c)
```