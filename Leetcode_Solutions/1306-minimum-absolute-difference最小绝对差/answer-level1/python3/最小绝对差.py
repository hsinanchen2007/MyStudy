### 解题思路
先排序，相邻的两个数的差值，进行对比，设置临时最小差值，如果后续出现更小的，则抛弃前面的，如果没有更小的，则把两个数填入结果中。

注意：已经是排序的，无需增加额外的排序相关的操作！！！

### 代码

```python3
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        if not arr:
            return []
     
        arr.sort()  # 注意已经是排序的，无需再两两相减
        res = []
        
        minDiff = arr[1] - arr[0]
        for i in range(1,len(arr)):
            curDiff = arr[i]-arr[i-1]
            if curDiff < minDiff:
                minDiff = curDiff
                res=[[arr[i-1],arr[i]]]

            elif curDiff == minDiff:
                res.append([arr[i-1],arr[i]])
            else:
                continue
        return res

        # 方法2：思路清晰，但是超时。问题所在：数组已经是排序的，无需再两两相减，增加了时间复杂度
        # arrS = sorted(arr)
        # if len(arr) <= 2:
        #     return [ararrSr]
        # minDiff = arrS[1]-arrS[0]
        # result= [[arrS[0], arrS[1]]]
        # for i in range(len(arr)-1):    # 问题所在
        #     for j in range(i+1, len(arr)):
        #         curDiff = arrS[j] - arrS[i]
        #         if curDiff < minDiff:
        #             result = [[arrS[i], arrS[j]]]
        #             minDiff = curDiff
        #             continue
        #         elif curDiff == minDiff:
        #             if [arrS[i],arrS[j]] not in result:
        #                 result.append([arrS[i],arrS[j]])

        # return result

        # 方法3：思路可行，但在测试用例数组长度很长时会超时。问题所在：数组已经是排序的，无需再两两相减，增加了时间复杂度
        # arrS = sorted(arr)

        # if len(arr) <= 2:
        #     return [ararrSr]
        # distance = {}
        # for i in range(len(arr) - 1):
        #     for j in range(i + 1, len(arr)):   # 问题所在
        #         distance.setdefault(abs(arr[i] - arr[j]),[]).append([arr[i],arr[j]])
         
        # minKey = distance[min(distance.keys())]  # 已经是排序的
        # for subL in minKey:
        #     if subL[0] > subL[1]:
        #         subL[0], subL[1] = subL[1], subL[0]
        
        # result = sorted(minKey,key=lambda x:x[0])   # 已经是排序的
        # return result

        
        
```