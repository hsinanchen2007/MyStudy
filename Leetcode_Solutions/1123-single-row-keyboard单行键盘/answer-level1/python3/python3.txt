### 解题思路
 小白解答，这个注释在用时上为什么会一会加一会减呢

### 代码

```python3
class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        num = []
        num2 = 0
        for i,x in enumerate(word):
            if x in keyboard:
                num.append(keyboard.index(x))
        # print(num)
        # if len(num) == 0:
        #     return 0
        # elif len(num) == 1:
        #     return int(num)
        # else:
        num.insert(0,0)
        for j in range(1,len(num)):
            num2 += abs(int(num[j])-int(num[j-1]))
        return num2

![捕获.PNG](https://pic.leetcode-cn.com/c3ba33d45c3cd0b9edbd089844365ce3e89d58f31b90cee86744bbc7e769da90-%E6%8D%95%E8%8E%B7.PNG)
