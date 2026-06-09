### 解题思路
求和公式 s开头，长度l 可得(s + s + l - 1) * l / 2 = target, 化解为(2s + l - 1) * l = 2N, 显然（2s + l - 1）和l奇偶性不同，l为大于等于2的正整数; 如果（2s + l - 1）< l, s < 0.5, 因此（2s + l - 1）>= l，循环条件可限制在根号2N内

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        end = int((2 * target) ** 0.5)
        res = []
        for l in range(2, end + 1):
            if (2 * target % l) == 0 and (2 * target / l + l) % 2:
                s = int((2 * target / l + 1 - l) / 2)
                tmp = [i for i in range(s, s + l)]
                res.append(tmp)
        res.reverse()
        return res
![image.png](https://pic.leetcode-cn.com/80f9ca184239747b160c637834dd2d709843c63e834fa42ba7cf1b971bea14ab-image.png)
