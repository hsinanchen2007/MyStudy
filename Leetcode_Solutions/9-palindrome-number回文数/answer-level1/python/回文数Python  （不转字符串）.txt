```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <0:return False
        if x==0:return True
        tube = []
        while x:
            tube.append(x%10)
            x=x//10
        size = len(tube)
        if size%2==0:
            left = tube[:size//2]
            right = tube[size//2:][::-1]
        else:
            left = tube[:size//2]
            right = tube[(size//2)+1:][::-1]
        return left == right
```

![image.png](https://pic.leetcode-cn.com/a568aa065f5b944986a0b8484c0d911914c095ac074f6c496551771b48cd8dd7-image.png)
虽然简单粗暴，但是效率不行

```
#第二种
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <0:return False
        if x==0:return True
        tube = 0
        x_bck = x
        while x:
            tube = tube*10 + x %10
            x=x//10
        return x_bck == tube
```
![image.png](https://pic.leetcode-cn.com/dc95b80515d7f7e7dc3b49b457068a77b0ec6e78ad57c1ba8d3bbcc7ef649388-image.png)

```
#优化
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <0 or x%10 ==0 and x!=0:
            return False
        tube = 0
        x_bck = x
        while x:
            tube = tube*10 + x %10
            if tube == x:return True
            x=x//10
        return tube == x_bck
```

![image.png](https://pic.leetcode-cn.com/bc7a354854fb7c25d2b2f319dd9ef2cc77d242daaa62b950dc2577979b7716d4-image.png)