具体思路就是从索引0开始旋转，如果一直到A的最后一个字母都不匹配则返回False。
所以递归的时候要增加一个p值记录旋转的次数。具体代码如下：
```
def rotateString(self, A: str, B: str) -> bool: 
        m=10
        def check(A,B,p):
            if A==B:
                return True
            if p==len(A):
                return False
            if (A[1:]+A[0])==B:
                return True
            else:
                return check(A[1:]+A[0],B,p+1)
            
        return check(A,B,0)`
   
```


![image.png](https://pic.leetcode-cn.com/04986bbe37d23d9861872bf4497517f28d6550975538ec23c5420a7b0f23681a-image.png)

