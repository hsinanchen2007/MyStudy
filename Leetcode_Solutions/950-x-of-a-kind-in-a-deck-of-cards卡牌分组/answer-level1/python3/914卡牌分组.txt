### 解题思路
- 题目等价于将卡牌分类，各类的牌数是否存在公因子（可以按最小公因子分组）
- 用字典存好牌类和牌数（牌类：牌数）
- 检查（2~最小牌数）中有没有最小公因子（遍历各牌类，一旦最小公因子立刻退出）

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if len(deck)<2:
            return False
        record = {}
        for different in set(deck):
            record[different]=deck.count(different)  #{牌类：数量}
        minlen = record[min(record,key=record.get)]  #数量最小的牌类的牌数
        L = len(set(deck))                           #计算有几类牌
        count = 0
        for x in range(2,minlen+1):                  #检查是否存在公因子
            for k,v in record.items():
                if v%x!=0:
                    count = 0
                    break
                if v%x==0:
                    count = count + 1
                    if count==L:                     #X是各类牌的公因子
                        return True
        return False
```