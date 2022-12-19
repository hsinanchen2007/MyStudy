看到这个题，一开始就想到了去计算以3为底的对数，如果答案是整数就是3的幂，于是写了如下代码
 ```
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n<=0: return False
        else:
            ans=math.log(n,3)
            if ans==int(ans):
                return True
            else:
                return False
```
结果WA了，因为math.log精度有问题吧，真是个坑，看了下大佬的题解，应该用round函数，把判断条件改成
```
n==3**round(ans)
```
就可以过了