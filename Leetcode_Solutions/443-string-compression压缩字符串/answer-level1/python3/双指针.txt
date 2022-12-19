## 思路:

思路一：三指针

思路二：双指针

两种方法思路一样的，一个指针判断数组到什么位置，另外两个（或者一个）判断个数！

## 代码:

思路一：三指针

```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        # 下面两个指针判断个数
        j = 0
        k = 0
        while k < len(chars):
            while k + 1 < len(chars) and chars[k + 1] == chars[j]:
                k += 1
            chars[i] = chars[j]
            i += 1
            if j != k:
                num = k - j + 1
                for s in str(num):
                    chars[i] = s
                    i += 1
            k += 1
            j = k
        return i 
```

思路二：双指针

```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        j = 0
        while j < len(chars):
            chars[i] = chars[j]
            i += 1
            # 个数
            num = 1
            while j + 1 < len(chars) and chars[j + 1] == chars[j]:
                num += 1
                j += 1
            if num != 1:
                for s in str(num):
                    chars[i] = s
                    i += 1
            j += 1
        return i 
```



