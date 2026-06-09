

    class Solution:
        def smallestDifference(self, a: List[int], b: List[int]) -> int:
            unionList = list(zip(a + b, [0] * len(a) + [1] * len(b)))
            #将两个数组混合按大小排序
            unionList.sort(key=self.getElement0)
            lasta, lastb, minD = None, None, 2147483647
            #获取跟另一个数组的最小差值
            for num in unionList:
                if num[1] == 0:
                    lasta = num[0]
                    if lastb is not None:
                        minD = min(minD, abs(lastb - lasta))
                elif num[1] == 1:
                    lastb = num[0]
                    if lasta is not None:
                        minD = min(minD, abs(lastb - lasta))
            return minD
        
        def getElement0(self, ele):
            return ele[0]




