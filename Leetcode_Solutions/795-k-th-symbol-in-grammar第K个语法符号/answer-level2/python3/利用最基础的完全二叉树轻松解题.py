
```python3
class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        sign = [] #记录从根结点到目标结点的变换方式，-1 表示左孩子；1 表示右孩子
        number = 2 ** (N - 1) + K - 1 # 在完全二叉树中 最终目标结点的编号
        def recur(number): #当编号为偶数时，该结点为父结点的左孩子： 两者的值相等；否则为右孩子：两者的值相反。
            if number == 1:
                return  
            if number % 2 == 0:
                sign.insert(0,-1)
            else:
                sign.insert(0,1)
            recur(number // 2)
        
        recur(number)
        res = 0
        for i in sign:  #根据sign中的记录，顺藤摸瓜，问题解决。
            if i == 1:
                if res == 0:
                    res = 1
                else:
                    res = 0
        return res    






```