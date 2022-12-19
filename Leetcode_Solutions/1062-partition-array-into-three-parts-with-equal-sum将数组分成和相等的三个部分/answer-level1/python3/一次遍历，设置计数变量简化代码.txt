![微信图片_20200311122014.png](https://pic.leetcode-cn.com/d5512e13c30c0c4311526a1b96c4d43b4f52dfb99ebaa4f8b4d4329c380d6f74-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200311122014.png)

简单易懂直接上代码
```
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        # 长度小于三返回False
        if len(A) < 3:
            return False
        # 总和
        S = sum(A)
        # 当前和
        cur = 0
        # 计数变量   
        tmp = 0
        for i in range(len(A)):
            cur += A[i]
            # 当cur满足三分之一S时，cur归零，计数加一表明有一个子数组满足条件
            if cur == S/3:
                cur = 0
                tmp += 1
        # 当满足条件子数组为3时，成立，大于三说明当前输入sum(A) == 0, 也返回True
        return tmp >= 3
```
