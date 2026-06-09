第一次做出竞赛最后一题，可能这次的太简单了吧。。
经典的BFS题，用一个队列存放箱子编号，每次从中取出一个进行判断，当队列为空或者所有箱子都上锁且没有钥匙时返回结果。

```
class Solution:
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        #list01列表中存放剩余的箱子，每次从中取一个出来
        list01=initialBoxes
        #list02列表中存放已经取得的钥匙，每次用完钥匙就扔掉
        list02=[]
        res=0
        c=0
        while list01:
            box=list01.pop(0)
            #箱子没上锁的情况
            if status[box]:
                res+=candies[box]
                list02.extend(keys[box])
                list01.extend(containedBoxes[box])
                c=0
            #箱子上锁但有钥匙的情况
            elif box in list02:
                list02.remove(box)
                res += candies[box]
                list02.extend(keys[box])
                list01.extend(containedBoxes[box])
                c=0
            #箱子上锁且没钥匙的情况
            else:
                #当一把钥匙都没有并且当前箱子是上锁的时候，记录一下作为初始状态
                if not list02:
                    c+=1
                    #当一把钥匙都没有且所有箱子都为上锁状态的时候返回结果
                    if len(list01)+1==c:
                        return res
                #放回箱子列表，期待之后会拿到钥匙
                list01.append(box)
        return res

```
