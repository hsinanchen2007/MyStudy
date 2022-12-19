### 解题思路
思路：本题要求对输入的俩个数进行对比，前提条件，输入的俩个数都是一样长，所以我们首先判断那个位置的值相同，就把这俩个字符串里的这个位置的数删除，其次我们判断剩下的数里，有没有母牛这种情况

### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        # 思路：本题要求对输入的俩个数进行对比，前提条件，输入的俩个数都是一样长
        # 所以我们首先判断那个位置的值相同，就把这俩个字符串里的这个位置的数删除
        # 其次我们判断剩下的数里，有没有母牛这种情况
        list1 = []
        list_secret = list(secret)
        list_guess = list(guess)
        num = 0
        s = 0
        # 判断那个位置的值，是一样的，也就是公牛的判断，这里将值存起来，方便以后删除和计算
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                list1.append(i)
        # 处理公牛，将刚找到的，删掉，因为字符串不好删，我们转成列表，
        # 因为删除以后列表结构会改变，所以我们需要在删了s个以后将j减去循环了几次这个值
        for j in list1:
            j -= s
            list_secret.pop(j)
            list_guess.pop(j)
            s += 1
        # 将公牛计算出来
        A = str(len(list1)) + "A"
        # 计算母牛，如果secret这个列表里的值在guess里有，就表示有一个母牛，
        # 因为如果不删除guess里的值，可能会，重复母牛的数量，所以我们将再里面的值删除
        for t in list_secret:
            if t in list_guess:
                num += 1
                list_guess.remove(t)
        # 将公牛计算出来
        B = str(num) + "B"
        # 输出结果
        str1 = A + B
        return str1
```