思路：「贪心」
    差最后一个测试样例超时。
```
class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        # 生成关于项目的二维数组
        item = []
        for i in range(len(Capital)):
            item.append([Capital[i],Profits[i]])
            
        costSorted = sorted(item, key = lambda x:x[0])
        # count: 用于记录已完成的项目数量
        count = 0
        while count < k and item:
            # 根据当前收益W，选择出可执行的项目
            itemToDo = self.exeItem(W, costSorted)
            print("count: " + str(count) + " " + str(itemToDo))
            if not itemToDo: 
                return W
            # 更新item列表，当前资金W，已执行项目数count
            costSorted.remove(itemToDo)
            W += itemToDo[1]
            count += 1

        return W

    
    def exeItem(self, W, costSorted):
        '''
        : 用于选择可执行的项目
        : array: 所有未执行的项目集合
        : W: 当前资金
        '''
        print("W:" + str(W))
        itemList = []
        for i in range(len(costSorted)):
            if costSorted[i][0] <= W:
                print("costSorted[i]: " + str(costSorted[i]))
                if not itemList:
                    itemList.append(costSorted[i])
                print("itemList_before: " + str(itemList))
                tmp = itemList.pop()
                # tmp: 单个的item元素，[cost,profit]形式，一维数组
                # costSorted: item数组，二维的[[cost1,profit1],[cost2,profit2]...]形式，costSorted[i][1]取第i个项目的索引1处的值。
                if tmp[1] <= costSorted[i][1]:
                    itemList.append(costSorted[i])
                
                else: 
                    itemList.append(tmp)
                print("itemList_after: " + str(itemList))
            else:
                break
                
        if not itemList:
            return None
        else:
            return itemList[-1]
```
