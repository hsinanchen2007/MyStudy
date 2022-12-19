### 解题思路
思路很简单，就是排除各种情况有点麻烦，这里使用了int()函数，可能不符合题目要求，但是能通过。
事实证明：只要你错的足够多，你就能把所有情况都写完整，再一次留下菜鸡的眼泪。

### 代码

```python3

class Solution:
    def myAtoi(self, str: str) -> int:

        ##去除空格
        # while " " in str:
        #     str.replace(" ","")
        str = str.strip()
        print("str的结果：",str)
        if not str:
            return 0
        Flag = False
        if str[0] in ["-","+"]:
            if str[0]=="-":
                Flag = True
                str = str[1:]
            else:
                str = str[1:]

        if len(str)<1:
            return 0
        if not str[0].isdigit():
            return 0
        nums = ""
        for i in range(len(str)):
            if str[i].isdigit():
                nums+=str[i]
            else:
                break
        nums = int(nums)
        if Flag:
            return max(-int(nums),-2**31)
        else:
            return min(int(nums),2**31-1)

```