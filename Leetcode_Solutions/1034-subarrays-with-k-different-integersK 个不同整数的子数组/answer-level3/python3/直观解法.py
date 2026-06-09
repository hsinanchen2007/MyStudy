思路：
1. 使用一个map保存窗口中不同的数字对应的个数；
2. 维护左下标posLeft、右下标posRight，表示最大包含K个不同数字的区间，当posLeft到posRight之间不同数字小于等于K时，posRight+=1；
3. 循环posRight从0到len(A);
4. 当posRight对应元素的加入导致posLeft到posRight之间不同数字等于K+1时，posLeft右移并且在右移过程中检查是否存在K个不同数字；
5. 代码如下：


    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        def cntBaseOn(A, K, windowsMap) -> int:
            nonlocal posLeft
            nonlocal posRight
            totalsubarrays = 0
            lenOfKeys = len(windowsMap.keys())
            if lenOfKeys == K:
                #print(posLeft, windowsMap, totalsubarrays)
                while posLeft < posRight:
                    #print(windowsMap, totalsubarrays)
                    if windowsMap[A[posLeft]] <= 1:
                        del windowsMap[A[posLeft]]
                        posLeft += 1
                        break
                    else:
                        windowsMap[A[posLeft]] -= 1
                        posLeft += 1
                        fromRight = posRight - 1
                        tmpMap={}
                        while fromRight >= posLeft + K - 1:
                            if windowsMap[A[fromRight]] > 1:
                                if A[fromRight] in tmpMap.keys():
                                    tmpMap[A[fromRight]] -= 1
                                    totalsubarrays += 1
                                    if tmpMap[A[fromRight]] == 0:
                                        break
                                else:
                                    tmpMap[A[fromRight]] = windowsMap[A[fromRight]] - 1
                                    totalsubarrays += 1
                            elif windowsMap[A[fromRight]] == 1:
                                totalsubarrays += 1
                                break
                            else:
                                break
                            fromRight -= 1
            return totalsubarrays

        posLeft = 0
        posRight = 0
        windowsMap = {}
        totalsubarrays = 0
        while posRight < len(A):
            if A[posRight] in windowsMap.keys():
                windowsMap[A[posRight]] += 1
                lenOfKeys = len(windowsMap.keys())
                if lenOfKeys == K:
                    totalsubarrays += 1
            else:
                lenOfKeys = len(windowsMap.keys())
                if lenOfKeys == K - 1:
                    totalsubarrays += 1
                elif lenOfKeys == K:
                    totalsubarrays += cntBaseOn(A, K, windowsMap)
                    totalsubarrays += 1
                windowsMap[A[posRight]] = 1
            posRight += 1
        totalsubarrays += cntBaseOn(A, K, windowsMap)
        return totalsubarrays
2. 