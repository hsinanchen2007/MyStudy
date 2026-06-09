## 思路:

思路一: 库函数

二进制转十进制,十进制数相加再转二进制

```python
class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        return bin(int(a,2) + int(b,2))[2:]
```

思路二:模拟加法过程

## 代码:

思路二 :

```python [1]
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        while i >=0 or j >= 0 or carry:
            tmp1 = int(a[i]) if i >= 0 else 0
            tmp2 = int(b[j]) if j >= 0 else 0
            carry, t = divmod(tmp1 + tmp2 + carry, 2)
            res = str(t) + res
            i -= 1
            j -= 1
        return res
```



```java [1]
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder res = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int tmp1 = (i >= 0 ? a.charAt(i--) - '0' : 0);
            int tmp2 = (j >= 0 ? b.charAt(j--) - '0' : 0);
            res.append((tmp1 + tmp2 + carry) % 2);
            carry = (tmp1 + tmp2 + carry) / 2;
        }
        return res.reverse().toString();      
    }
}
```

