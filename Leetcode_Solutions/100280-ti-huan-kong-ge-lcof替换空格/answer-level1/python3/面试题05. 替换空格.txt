解法一：使用Python的replace()函数。replace()语法：str.replace(old,new[,max])，将字符串old替换成new，替换次数不超过max次
```
class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(" ","%20")
```

解法二：将字符串s转换成列表，将列表中的空格替换为“%20”，使用join()拼接字符串，返回拼接后的字符串，str.join(sequence)，sequence为要连接的字符串序列，按照指定格式拼接
```
class Solution:
    def replaceSpace(self, s: str) -> str:
        arr = [str(x) for x in s]
        for i in range(len(arr)):
            if arr[i]==" ":
                arr[i] = "%20"
        return ''.join(arr)
```

解法三：将字符串s转换成列表，将列表中的空格替换成“%20”，使用“+”号拼接字符串返回拼接后的字符串
```
class Solution:
    def replaceSpace(self, s: str) -> str:
        arr = [str(x) for x in s]
        for i in range(len(arr)):
            if arr[i] == " ":
                arr[i] = "%20"
        str1 = ""
        for i in arr:
            str1 += i
        return str1
```