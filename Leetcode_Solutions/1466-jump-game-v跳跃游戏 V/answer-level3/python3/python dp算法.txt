### 解题思路
此处撰写解题思路
先把效果贴一下
![WechatIMG6165.png](https://pic.leetcode-cn.com/1cbe85b4662c7d34e6a6ba1308d9d6f1515f0e8ac48ffb1ee31b4f91db733da4-WechatIMG6165.png)
动态规划，先将柱子按照度排个序，从最小的柱子开始记录，从低到高开始遍历。用index_visit这个map记录。index_visit[index] = max(index可以到达的柱子高度) + 1. 最终从map选取value最大值。
时间复杂度和空间复杂度均为O(1)
### 代码

```python3
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        len_index = {}
        for ind in range(len(arr)):
            if arr[ind] not in len_index.keys():
                len_index[arr[ind]] = []
            len_index[arr[ind]].append(ind)
        
        len_order = [i for i in sorted(len_index.keys())]
        # print(len_order)
        index_visit = {}
        for ind in len_index[len_order[0]]:
            index_visit[ind] = 1
        
        for i in range(1, len(len_order)):
            # print(i)
            for ind in len_index[len_order[i]]:
                tmp_max = 0 #if there is no property j, the i should be 0 + 1
                for k in range(1, d+1):
                    if ind + k >= len(arr):
                        break
                    if arr[ind + k] >= arr[ind]:
                        break
                    if ind + k in index_visit.keys():
                        tmp_max = max(tmp_max, index_visit[ind+k])
                for k in range(1, d+1):
                    if ind - k < 0:
                        break
                    if arr[ind - k] >= arr[ind]:
                        break
                    if ind - k in index_visit.keys():
                        tmp_max = max(tmp_max, index_visit[ind-k])
                index_visit[ind] = tmp_max + 1
        # print(index_visit)
        return max(index_visit.values())
        

```