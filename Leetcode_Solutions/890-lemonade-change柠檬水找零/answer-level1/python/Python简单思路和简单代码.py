### 解题思路
因为题目说只有5，10，20元三种可能，所以：
1、遇到5元，直接收了
2、遇到10元，看包包里有没有5元，有就给出来，没有就直接返回false
3、遇到20元，有两种情况
    * 要么找10+5
    * 要么找5+5+5
    * 然后依次去看每种情况下自己包包里有没有这样可以找的钱，有就给出来，没有就返回false
4、最后，所有情况都遍历了一遍，就直接返回True
5、代码还有待优化。。。。写的真的烂。。。。

### 代码

```python3

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if not bills:
            return True
        if bills[0]>5:
            return False
        money = []
        for i in bills:
            if i==5:
                money.append(i)
            if i==10:
                if 5 in money:
                    money.remove(5)
                    money.append(10)
                else:
                    return False
            if i==20:
                if 10 in money and 5 in money:
                    money.remove(10)
                    money.remove(5)
                    money.append(20)
                elif money.count(5)>=3:
                    money.remove(5)
                    money.remove(5)
                    money.remove(5)
                    money.append(20)
                else:
                    return False
        return True

```