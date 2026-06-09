### 解题思路

考虑到只有1,10，100,1000 四类会出现多个的情况

只分开考虑这四类，其余的都只会出现一次，只要从大到小遍历即可。


```
执行用时 :40 ms, 在所有 python3 提交中击败了 99.21% 的用户
内存消耗 : 12.8 MB , 在所有 python3 提交中击败了 99.54% 的用户
```

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        rr=''
        vs=[('M', 1000), ('CM', 900), ('D', 500), ('CD', 400), ('C', 100), ('XC', 90), ('L', 50), ('XL', 40), ('X', 10), ('IX', 9), ('V', 5), ('IV', 4), ('I', 1)]
        for r in vs:
            if num>=r[1]:
                if (str(r[1])[0]!='1'):
                        num=num-r[1]
                        rr+=r[0]
                else:
                        k=int(num/r[1])
                        rr+=r[0]*k
                        num=num-r[1]*k
        return rr

```
-----

## 垃圾解法

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        result=[]
        while num!=0:
            if int(num/1000)>0:
                result.append('M')
                num=num-1000
                continue
            elif int(num/900)>0:
                result.append('CM')
                num=num-900
                continue
            elif int(num/500)>0:
                result.append('D')
                num=num-500
                continue

            elif int(num/400)>0:
                result.append('CD')
                num=num-400
                continue

                            
            elif int(num/100)>0:
                result.extend(['C']*int(num/100))
                num=num-100*int(num/100)
                continue

                            
            elif int(num/90)>0:
                result.append('XC')
                num=num-90
                continue

                            
            elif int(num/50)>0:
                result.append('L')
                num=num-50
                continue

                            
            elif int(num/40)>0:
                result.append('XL')
                num=num-40
                continue

                            
            elif int(num/10)>0:

                result.extend(['X']*int(num/10))
                num=num-10*int(num/10)
                continue
                            
            elif int(num/9)>0:
                result.append('IX')
                num=num-9
                continue
                                
            elif int(num/5)>0:
                result.append('V')
                num=num-5
                continue
            
            elif int(num/4)>0:
                result.append('IV')
                num=num-4
                continue
                            
            else:
                result.extend(['I']*int(num/1))
                num=0
                continue
        return ''.join(result)
```
