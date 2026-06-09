使用字典替代类型转换，虽然代码啰嗦了点，但计算速度还可以。

```
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(b) > len(a):
            a, b = b, a
        b = '0'*(len(a)-len(b))+b

        mapping1 = {
            ('0', '0'): '0',
            ('0', '1'): '1',
            ('1', '0'): '1',
            ('1', '1'): '0'
        }
        mapping2 = {
            ('0', '0'): '1',
            ('0', '1'): '0',
            ('1', '0'): '0',
            ('1', '1'): '1'
        }

        ret = ''
        i = len(a)-1
        up = False
        while i >= 0:
            if up:
                ret = mapping2[(a[i], b[i])] + ret
                if (a[i], b[i]) == ('0', '0'):
                    up = False
            else:
                ret = mapping1[(a[i], b[i])] + ret
                if (a[i], b[i]) == ('1', '1'):
                    up = True 
            i = i - 1

        return '1'+ret if up else ret
```
