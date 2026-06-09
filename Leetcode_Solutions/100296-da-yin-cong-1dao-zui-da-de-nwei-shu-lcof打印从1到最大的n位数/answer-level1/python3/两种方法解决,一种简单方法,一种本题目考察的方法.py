### 解题思路
方法一:赖皮方法
方法二:用递归求全排列

### 代码
```
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        ret=[]
        for i in range(1,10**n):
            ret.append(i)
        return ret
```

```
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        if n<0:
            return
        ret=['0' for _ in range(n)]
        result=[]
        def str_num(L:list): #将['0','1']返回成数字1
            return int("".join(L))
        def print1toN(ret,length,index): #递归遍历从数组的位置1到n-1,数字0-9所有的全排列
            if index==length-1:
                result.append(str_num(ret))
                return
            for i in range(10):
                ret[index+1]=str(i)
                print1toN(ret,length,index+1)
        for i in range(10):
            ret[0]=str(i)
            print1toN(ret,n,0) #ret表示存储数字的列表,n表示长度,0表示index位置
        return result[1:] #0这个数字不需要返回,所以不用输出
```