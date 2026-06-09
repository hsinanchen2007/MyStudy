### 解题思路
Python find() 方法检测字符串中是否包含子字符串 str ，如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内，如果包含子字符串返回开始的索引值，否则返回-1。

Python index() 方法检测字符串中是否包含子字符串 str ，如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内，该方法与 python find()方法一样，只不过如果str不在 string中会报一个异常。

此处不能用s.index('0')，因为不一定有0 ，找不到0会报错

### 代码

```python3
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res=[]
        for x in range(left,right+1):
            flag=True
            s=str(x)
            if s.find('0')!=-1:
                continue
            for i in s:
                if x % int(i) != 0:
                    flag = False
            if flag == True:
                res.append(x)
        
        return res
```