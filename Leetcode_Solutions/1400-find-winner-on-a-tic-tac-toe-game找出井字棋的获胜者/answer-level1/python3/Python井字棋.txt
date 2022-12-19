先将Moves分配到两个列表中去，lista代表第一位选手，listb代表第二位选手。

考虑赢法一定是三点一线。即必有一点中点。那么先查找lista任意两不同点的中点是否仍在集合内，在就说明赢了。如果没有，那么再用同样的方法查找listb是否赢了。

如果a,b都没赢，再根据Moves长度判断结果为"Draw"还是"Pending"。如果长度等于9，则为"Draw",不等于则为"Pending"

以下为代码：
```
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        lista = []
        listb = []
        for step in range(0,(len(moves)),2):
            lista.append(moves[step])
        for step in range(1,(len(moves)),2):
            listb.append(moves[step])
        for num,elem in enumerate(lista):
            choice = lista[num]
            for subel in lista:
                if subel != choice: 
                    x = (subel[0]+choice[0])/2
                    y = (subel[1]+choice[1])/2
                    if [x,y] in lista:
                        return "A"
        for num,elem in enumerate(listb):
            choice = listb[num]
            for subel in listb:
                if subel != choice:
                    x = (subel[0]+choice[0])/2
                    y = (subel[1]+choice[1])/2
                    if [x,y] in listb:
                        return "B"
        if len(moves) == 9:
            return "Draw"
        return "Pending"
```
![wow.JPG](https://pic.leetcode-cn.com/6e7eedca8e6697f7ca999bc8c81d8a6d4ab56c63357c8c95afd955eddef36547-wow.JPG)

