### 解题思路
首先需要思考字符串可能存在形式，如从长度来看：空，单一，多；从题目要求看，压缩后新旧长度对比情况
其次脑海中存在逻辑图，可在草稿纸上画个轮廓。
（1）_point
字符串使用len()方法
三次 if 条件语句
一次 for 循环遍历
（2）_problem
所定义函数中，输入字符串为S非s
i为int不可变量，不可忘记range()
ini_为单独拎出来的字符，作为与下一个元素对比，并在for语句单次循环后更改
（3）_attention
最为重要的是for语句块，在编写的时候，如果else语句块和if语句块倒过来，将会输出单一计数，从而导致错误
if语句块满足后，便会再次循环，知道元素ini_不再出现，将会跳到else语句，此时count已经明确显示ini_出现的次数，那么此时current += ini_ +str(count)才是真正的ini_加n
最后，count重新赋值为1，for语句再次开始，而此时ini_变为新元素
            for i in range(1,len(S)):
                if ini_ == S[i]:
                    count += 1
                else:
                    current += ini_ +str(count)
                    count = 1
                    ini_ = S[i]
### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) <= 1:#所定义函数中，输入字符串为S非s
            return S 
        if len(S) > 1:
            ini_ = S[0]#ini_为单独拎出来的字符，作为与下一个元素对比
            current = ''
            count = 1
            for i in range(1,len(S)):# i 为int不可变量，不可忘记range()
                if ini_ == S[i]:
                    count += 1
                else:
                    current += ini_ +str(count)
                    count = 1
                    ini_ = S[i]#用于比较的ini_单次循环后更改
            current += ini_ +str(count)
        if len(current) >= len(S):
            return S
        else:
            return current 
        
```