执行用时 : 12 ms , 在所有 Python 提交中击败了 97.92% 的用户
内存消耗 : 12.8 MB , 在所有 Python 提交中击败了 5.55% 的用户


普通的栈遍历一次即可。



```py
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        for i, c in enumerate(s):
            if c != "]":
                stack.append(c)
            else:
                stack_cur_string = []  # 用于 存放当前括号内的内容
                while stack and stack[-1] != "[":
                    stack_cur_string.append(stack.pop())
                stack.pop()  # 弹出 “[” 符号，这个符号不需要被复制

                stack_int = []  # 用于 存放括号前面的数字，作为重复的次数。
                # 因为重复的次数可能不止一位数，所以可以使用栈存放每一个位数字。  
                while stack and "0" <= stack[-1] <= "9":
                    stack_int.append(stack.pop())

                # print("stack_cur_string = ", stack_cur_string)
                # print("stack_int = ", stack_int)
                times = int("".join(stack_int[::-1]))
                
                # 将括号中的字符转成是字符串的，并复制多次。
                temp_string = "".join(stack_cur_string[::-1]) * times 
                # print("times = ", times)

                temp_string_list = list(temp_string)
                # print("temp_string_list = ", temp_string_list )

                stack += temp_string_list

        # print(stack)

        return "".join(stack)
```
