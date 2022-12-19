# 1.流程分支法（代码风格臃肿，大量嵌套if-else）
**思路(针对第一个非空字符的取值，按照数学老师教的分类讨论走起):**
1. 找到第一个非空字符***first***的位置***pos***，这是字符转换整数工作的起点（丢弃无用的开头空格字符）
2. 如果***first***是'+'或'-'，采用有符号整数的转换流程：读取后续字符
- 如果是非数字字符，说明无法进行有效转换，结束
- 如果是数字字符，则将当前整数左移一位，把数字追加在整数的末尾，由于是十进制数，所以存在如下关系：`new_num = last_num * 10 + int(char)`
- 处理整数边界溢出问题，根据正负符号返回转换结果
3. 如果first是数字字符，采用无符号整数的转换流程：区别于有符号整数装换的是要从当前字符开始转换，其他逻辑是一样的
4. 以上两种情况之外的情况都表示字符串无法进行有效转换，`return 0`，over！
```
# 流程分支法，代码风格臃肿，大量嵌套if-else
class Solution:
    def myAtoi(self, str: str) -> int:
        # 初始化第一个非空字符及其位置为不存在
        pos = -1
        first = None
        # 找到第一个非空字符及其位置
        for index, char in enumerate(str):
            if char != ' ':
                pos = index
                first = char
                break
        # 初始化转换的整数为0
        num = 0
        # 代表数字的字符列表
        numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        # 第一个非空字符为正或者符号的处理方法
        if first == '+' or first == '-':
            for char in str[pos + 1:]:
                if char in numbers:
                    num = num * 10 + int(char)
                else:
                    break
            # 正数的边界处理，INT_MAX(2^31 - 1)
            if first == '+':
                if num <= 2 ** 31 - 1 :
                    return num
                else:
                    return 2 ** 31 - 1
            # 负数的边界处理，INT_MIN(-2^31)
            if first == '-':
                if num <= 2 ** 31:
                    return -num
                else:
                    return - 2 ** 31
        # 第一个非空字符为数字的处理方法
        if first in numbers:
            for char in str[pos:]:
                if char in numbers:
                    num = num * 10 + int(char)
                else:
                    break
            # 无符号整数的边界处理
            if num <= 2 ** 31 - 1:
                return num
            else:
                return 2 ** 31 - 1
        # 第一个非空字符不是一个有效整数字符、字符串为空或者字符串仅包含空白字符时，无法进行有效转换
        return 0
```
# 2.一行代码流（正则表达式提取数字字符，调用内置函数/库函数完成转换处理）
**思路：就是上面的思路，只是通过调用函数实现了，可以把层层嵌套的函数分成5层逻辑来分析，直接看下面注释**
```
# 调用库函数一行代码解决法
import re
class Solution:
    def myAtoi(self, str: str) -> int:
        # 从内层到外层解析本行代码
        # level-1: str.lstrip(chars=None)
        #   返回将字符串前面空白字符移除后的字符串备份
        # level-2：'^[\+\-]?\d+' Regular Expression Syntax
        #   ^:插入字符/脱字符，表示从字符串的开头开始匹配模式
        #   []:字符集，用于表明内容是一个字符集合
        #   \:转义字符，用于如*、?等特殊字符的转义为字符本身或作为如\d、\s、\w等特殊序列的开始信号
        #   ?:表示模式匹配字符串0次或1次
        #   +:表示模式匹配字符串1次或多次（表达式中第二个+）
        #   \d:表示decimal digit，即[0-9]
        # level-3: re.findall(pattern, string, flags=0)
        #   返回一个对字符串不相重叠的匹配结果列表
        #   此处返回结果为['+/-'&'number_string']，eg. ['+42'],['-357']
        #   或空列表[]
        # level-4: int([x]) -> integer
        #   将string转换为相应的integer，连同字面量前的'+'、'-'一同处理
        # level-5: 边界限制
        # max(arg1, arg2, *[, default=obj, key=func]) -> value
        # 返回传入函数的最大参数，即转换后的数字不小于系统数字范围的下限INT_MIN(-2^31)
        # min(arg1, arg2, *[, default=obj, key=func]) -> value
        # 返回传入函数的最小参数，即转换后的数字不大于系统数字范围的上限INT_MAX(2^31 - 1)
        return max(min(int(*re.findall('^[\+\-]?\d+', str.lstrip())), 2 ** 31 -1), -2 ** 31)
```
# 3.自动机法（对官方解法代码的注解和debug）
看到官方解法的代码忘记做边界处理了~~~ 九监 九介！！！
思路：官方解法讲得很清楚了！这里不做赘述！
下面是对官方解法代码的个人解读和调整！
```
# 自动机法
# DFA（Deterministic Finite Automaton），确定有穷自动机
# 可被表示为一个五元组：(Q, Σ, δ, q0, F)
# Q is a finite set of states.有穷状态集合
# Σ is a finite set of symbols called the alphabet.符号的有穷集合（字母表）
# δ is the transition function where δ:Q × Σ -> Q.状态转换函数
# q0 is the initial state where any input is processed(q0 ∈ Q).初始状态
# F is a set of final state/states of Q(F ⊆ Q).终止状态集合，Q的子集
from enum import Enum
# 定义数字范围的上下边界
INT_MAX = 2 ** 31 - 1
INT_MIN = -2 ** 31
# 由Enum类派生出新的枚举类型State，表示自动机的状态集合，其中END为终止状态
class State(Enum):
    START = 0
    SIGNED = 1
    IN_NUMBER = 2
    END = 3
# 定义自动机
class Automaton:
    # 初始化自动机
    def __init__(self):
        # 状态为初始状态
        self.state = State.START
        # 符号位默认为正，符号因子为1，负数的符号因子为-1
        self.sign = 1
        # 转换结果默认为0
        self.ans = 0
        # 状态转换表，各列读取到的符号分别为：空白字符' '、正负符号'+'或'-'、数字符号、其他符号
        self.table = {
                State.START:[State.START, State.SIGNED, State.IN_NUMBER, State.END],
                State.SIGNED:[State.END, State.END, State.IN_NUMBER, State.END],
                State.IN_NUMBER:[State.END, State.END, State.IN_NUMBER, State.END],
                State.END:[State.END, State.END, State.END, State.END]
                }
    
    # 读取字符映射到状态转换表的列标
    def get_col(self, char) -> int:
        # 空白字符列标为0
        if char.isspace():
            return 0
        # 正负符号列标为1
        if char == '+' or char == '-':
            return 1
        # 数字符号列标为2
        if char.isdigit():
            return 2
        # 其他字符列标为3
        return 3
    
    # 状态转换函数
    # 读取状态转换表，计算下一状态
    def get(self, char):
        # 查询状态转换表，更新状态
        self.state = self.table[self.state][self.get_col(char)]
        # 当前状态为在数字处理中，计算当前已读取符号所代表的数字
        if self.state == State.IN_NUMBER:
            self.ans = self.ans * 10 + int(char)
        # 当前状态为正负符号中，设置符号因子
        if self.state == State.SIGNED:
            self.sign = 1 if char == '+' else -1

class Solution:
    def myAtoi(self, str: str) -> int:
        # 创建一个状态机
        automaton = Automaton()
        # 遍历字符串，更新自动机状态
        for char in str:
            automaton.get(char)
        # 计算数字
        num = automaton.sign * automaton.ans
        # 边界溢出处理
        if num >INT_MAX:
            return INT_MAX
        elif num < INT_MIN:
            return INT_MIN
        else:
            return num
```




